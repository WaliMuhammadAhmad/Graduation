#lab 12 task 1

print("hello")
r=float(input("Enter radius: "))
area=3.14*r**2
print("the area of a circle is",area)

#lab 12 task 2

val=input("Enter some comma separated numbers: ")
list=val.split(",")
tuple=tuple(list)
print('list: ',list)
print('tuple: ',tuple)

#lab 13 task 1

c=float(input("Enter temp in celcius: "))
f=c*9/5+32
print("the tempreture in fahrenheit is: ",f)
f=float(input("Enter temp in fahrenheit: "))
c=(f-32)*5/9
print("the tempreture in celcius is: ",c)

#lab 13 task 2

n=5
for i in range(n):
    for j in range(i):
        print('*',end="")
    print('')
for i in range(n,0,-1):
    for j in range (i):
        print("*",end='')
    print("")

