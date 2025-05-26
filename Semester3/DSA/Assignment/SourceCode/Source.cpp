#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<stack>
#include<string>
// Min and max values only for testing
constexpr auto maxValue = 100;
constexpr auto minValue = 1;
using namespace std;

//class Declaration
class TreeNode;
class StackNode;
class ExpressionTree;

//class Defination
class TreeNode
{
private:
	int value;
	char letter;
	TreeNode* left; 
	TreeNode* right;
public:
	TreeNode(char l = '\0', int v = 0) : left(NULL), right(NULL)
	{
		value = v;
		letter = l;
	}

	friend class StackNode;
	friend class ExpressionTree;
};

class StackNode
{
public:
	TreeNode* treeNode;					//Tree Node to hold the expression tree in Stack Node
	StackNode* top;
	StackNode(TreeNode* treeNode): top(NULL)
	{
		this->treeNode = treeNode;
	}

	TreeNode* getTreeNode()
	{
		return treeNode;
	}

	StackNode* getStackTop()
	{
		return top;
	}

	friend class ExpressionTree;
};

class ExpressionTree {
public:
	StackNode* root; 
	int n;							//for size

	ExpressionTree() : root(NULL) { n = 0; }

	int size() const				//Return size of tree
	{
		return n;
	}

	bool isEmpty() const
	{
		return (root == NULL);
	}

	bool isRoot() const
	{
		return (root->treeNode->left != NULL) && (root->treeNode->right != NULL);
	}

	bool isLeaf() const
	{
		return (root->treeNode->left == NULL) && (root->treeNode->right == NULL);
	}

	StackNode* getRoot() const
	{
		return root;
	}

	TreeNode* getTree() const
	{
		return root->treeNode;
	}

	TreeNode* getLeft() const
	{
		return root->treeNode->left;
	}
	
	TreeNode* getRight() const
	{
		return root->treeNode->right;
	}

	TreeNode* top()
	{
		return root->treeNode;
	}

	TreeNode* pop()
	{
		if (root == NULL)
		{
			cout << "Cannot pop!" << endl;
		}
		else
		{
			TreeNode* ptr = root->treeNode;
			root = root->top;
			return ptr;
		}
	}

	void push(TreeNode* ptr)
	{
		if (root == NULL)
			root = new StackNode(ptr);
		else
		{
			StackNode* nptr = new StackNode(ptr);
			nptr->top = root;
			root = nptr;
		}
	}

	int randomValue()
	{
		int x = 0;
		x = (rand() % (maxValue - minValue + 1)) + minValue;
		cout << "Random Value: " << x << endl;
		return x;
	}

	void insert(char val)
	{
			if (isOperand(val))
			{
				TreeNode* nptr = new TreeNode(val, randomValue());
				push(nptr);
			}
			else if (isOperator(val))
			{
				TreeNode* nptr = new TreeNode(val);
				nptr->left = pop();
				nptr->right = pop();
				push(nptr);
			}
			else
			{
				cout << "Invalid Expression" << endl;
				return;
			}
	}

	bool isOperand(char ch)
	{
		return ch >= 'a' && ch <= 'z';
	}

	bool isOperator(char ch)
	{
		return ch == '+' || ch == '-' || ch == '*' || ch == '/';
	}

	int toDigit(char ch)
	{
		return ch - '0';
	}

	void buildTree(string eqn)
	{
		for (int i =  0; i <= eqn.length(); i++)
			insert(eqn[i]);
	}

	double evaluate(TreeNode* ptr)					//Recursive function to Evaluate ExpressionTree
	{
		if (ptr->left == NULL && ptr->right == NULL)
			return toDigit(ptr->value);
		else
		{
			double result = 0.0;
			ptr->right->value = randomValue();
			ptr->left->value = randomValue();
			double left = evaluate(ptr->left);
			double right = evaluate(ptr->right);
			char op = ptr->letter;
			switch (op)
			{
			case '+':
				result = left + right;
				break;
			case '-':
				result = left - right;
				break;
			case '*':
				result = left * right;
				break;
			case '/':
				result = left / right;
				break;
			default:
				cout << "Invalid expression." << endl;
				break;
			}
			return result;
		}
	}

	int prec(char c)
	{
		if (c == '^')
			return 3;
		else if (c == '*' || c == '/')
			return 2;
		else if (c == '-' || c == '+')
			return 1;
		else
			return 0;
	}

	string InfixtoPostfix(string exp)
{
		stack<char> s;						//A STL stack for Infix to Postfix expression
		string postfix;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] >= 'a' && exp[i] <= 'z')
			postfix += exp[i];
		else if (exp[i] == '(')
			s.push(exp[i]);
		else if (exp[i] == ')')
		{
			while (!s.empty() && s.top() == '(')
			{
				postfix += s.top();
				s.pop();
			}
			if(!s.empty())
				s.pop();
		}
		else
		{
			while (!s.empty() && prec(s.top()) > prec(exp[i]))
			{
				postfix += s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
	}

		while (!s.empty())
		{
			postfix += s.top();
			s.pop();
		}
		return postfix;
	}

	string infixtoExpTree()
	{
		string postfix,userInput ;
		postfix = userInput = "\0";
		cout << "Enter the infix expression: ";
		cin >> userInput;
		postfix = InfixtoPostfix(userInput);
		buildTree(postfix);
		inlineDisplay(root->treeNode);
		return userInput;
	}

	void inlineDisplay(TreeNode* head)
	{
		if (head == NULL)
			return;

		inlineDisplay(head->left);
		cout << head->value << " ";
		inlineDisplay(head->right);
	}
};

int main()
{
	ExpressionTree tree;					//Expression tree Object to use Expression class Function

	int choice = 1;
	do
	{
		cout << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|          Expression Tree             |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << endl;
		cout << "[1] Infix to Expression Tree \n";
		cout << "[2] Evaluate Expression Tree \n";
		cout << "[3] Display Expression Tree (Inline Display) \n";
		cout << "[4] Quit \n";
		cout << "\n Enter your choice between [1-4] : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			tree.infixtoExpTree();
			break;
		case 2:
			tree.evaluate(tree.root->treeNode);
			break;
		case 3:
			tree.inlineDisplay(tree.root->treeNode);
			break;
		case 4:
			return 0;
			break;
		}

	} while (choice < 1 || choice > 4);

	return 0;
}