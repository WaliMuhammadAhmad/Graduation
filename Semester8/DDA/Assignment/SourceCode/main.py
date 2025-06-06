import sympy as sym
import math

def parse_fn(expr):
    """Convert input f(n) string to symbolic expression."""
    n = sym.Symbol('n')
    try:
        expr = expr.replace('logn', 'log(n)').replace('^', '**')
        return sym.sympify(expr, locals={'n': n, 'log': sym.log})
    except Exception:
        raise ValueError("Invalid f(n). Use expressions like n^2, n*log(n), 1, etc.")

def solve_master_case(a, b, f_n):
    """Solve T(n) = a T(n/b) + f(n) using Master Theorem."""
    n = sym.Symbol('n')
    if a <= 0 or b <= 1:
        raise ValueError("a must be > 0 and b must be > 1")
    log_val = math.log(a, b)
    base_term = n ** log_val
    ratio = sym.limit(f_n / base_term, n, sym.oo)

    # Case 1: f(n) = O(n^{log_b(a) - epsilon})
    if ratio == 0:
        return "polynomial", f"Theta(n^{log_val:.2f})"

    # Case 2: f(n) = Theta(n^{log_b(a)} log^k(n))
    k_limit = sym.limit(f_n / (base_term * sym.log(n)), n, sym.oo)
    if ratio.is_finite and ratio != 0:
        return "polynomial", f"Theta(n^{log_val:.2f} * log(n)**2)"

    # Case 3: f(n) = Omega(n^{log_b(a) + epsilon}) with regularity
    if ratio == sym.oo:
        regular = sym.limit(a * f_n.subs(n, n / b) / f_n, n, sym.oo)
        if regular.is_finite and regular < 1:
            return "polynomial", f"Theta({sym.latex(f_n)})"
    
    return "none", "Master Theorem not applicable"

def solve_diff_sizes(b1, b2, f_n):
    """Estimate T(n) = T(n/b1) + T(n/b2) + f(n) using recursion tree approximation."""
    if b1 <= 1 or b2 <= 1:
        raise ValueError("b and b' must be > 1")
    return "polynomial", f"O({sym.latex(f_n)} * log(n))"

def solve_decreasing_case(a, b, f_n):
    """Solve decreasing recurrence: T(n) = a T(n - b) + f(n)."""
    n = sym.Symbol('n')
    if b <= 0:
        raise ValueError("b must be > 0")

    if a == 1:
        if f_n == 1:
            return "linear", "Theta(n)"
        elif f_n == n:
            return "quadratic", f"Theta(n**2)"
        else:
            return "polynomial", f"Theta(n * {sym.latex(f_n)})"
    
    if f_n == 1:
        return "exponential", f"Theta({a}^(n/{b}))"
    if f_n == n:
        return "exponential", f"Theta(n * {a}^(n/{b}))"
    
    return "exponential", f"O({a}^(n/{b}) * {sym.latex(f_n)})"

def main_solver():
    """Main function to solve recurrence relations with an improved CLI."""
    while True:
        try:
            print("\n===== Recurrence Relation Solver =====")
            print("Select the recurrence type:")
            print("1 → T(n) = a T(n/b) + f(n)  (Dividing, same-size subproblems)")
            print("2 → T(n) = T(n/b) + T(n/b') + f(n)  (Dividing, different-size subproblems)")
            print("3 → T(n) = a T(n - b) + f(n)  (Decreasing)")
            print("4 → Exit")
            choice = input("Your choice (1/2/3/4): ")

            if choice == "4":
                print("not good")
                break

            if choice not in ["1", "2", "3"]:
                print("⚠️ Invalid selection. Please enter 1, 2, 3, or 4.")
                continue

            if choice == "1":
                print("\nSolving: T(n) = a T(n/b) + f(n)")
                a = int(input("Enter 'a' (number of subproblems): "))
                b = int(input("Enter 'b' (subproblem size factor): "))
                if a <= 0 or b <= 1:
                    print("Error: 'a' must be > 0, 'b' must be > 1.")
                    continue
                fn_input = input("Enter f(n) (e.g., n^2, n*log(n), 1): ")
                f_n = parse_fn(fn_input)
                class_type, result = solve_master_case(a, b, f_n)
                if result == "Master Theorem not applicable":
                    print("Master Theorem not applicable. Falling back to approximation.")
                    class_type, result = solve_diff_sizes(b, b, f_n)
                print(f"\nTime Complexity Class: {class_type.upper()}")
                print(f"T(n) = {result}")

            elif choice == "2":
                print("\nSolving: T(n) = T(n/b) + T(n/b') + f(n)")
                b1 = float(input("Enter 'b' (first subproblem size factor): "))
                b2 = float(input("Enter 'b'' (second subproblem size factor): "))
                if b1 <= 1 or b2 <= 1:
                    print("Error: 'b' and 'b'' must be > 1.")
                    continue
                fn_input = input("Enter f(n) (e.g., n^2, n*log(n), 1): ")
                f_n = parse_fn(fn_input)
                class_type, result = solve_diff_sizes(b1, b2, f_n)
                print(f"\nTime Complexity Class: {class_type.upper()}")
                print(f"T(n) = {result}")

            elif choice == "3":
                print("\nSolving: T(n) = a T(n - b) + f(n)")
                a = int(input("Enter 'a' (multiplier for subproblem): "))
                b = int(input("Enter 'b' (decrement in size): "))
                if b <= 0:
                    print("Error: 'b' must be > 0.")
                    continue
                fn_input = input("Enter f(n) (e.g., n^2, n*log(n), 1): ")
                f_n = parse_fn(fn_input)
                class_type, result = solve_decreasing_case(a, b, f_n)
                print(f"\nTime Complexity Class: {class_type.upper()}")
                print(f"T(n) = {result}")

        except ValueError as e:
            print(f"Error: {e}")
        except Exception as e:
            print(f"An unexpected error occurred: {e}")

        another = input("\nsolve another recurrence? (y/n): ")
        if another.lower() != 'y':
            print("ok")
            break

if __name__ == "__main__":
    main_solver()