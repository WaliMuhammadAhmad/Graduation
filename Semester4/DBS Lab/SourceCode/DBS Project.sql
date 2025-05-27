CREATE TABLE Admin
(
Admin_ID int PRIMARY KEY,
Admin_Name varchar(20),
Admin_Username varchar(20),
Admin_Password varchar(14)
)

insert into Admin values (141,'Wali Muhammad','walim','walim141')

select*from Admin

---------------------------------------------------
CREATE TABLE Product
(
Product_ID int PRIMARY KEY,
Product_Type varchar(10),
Product_Name varchar(30),
)

insert into Product values (1,'Computer','Normal PC')
insert into Product values (2,'Computer','Mac Pro')
insert into Product values (3,'Computer','Gaming PC')
insert into Product values (4,'Computer','Workstation Computer')
insert into Product values (5,'Monitor','LED Monitor')
insert into Product values (6,'Headphones','Wired On-head Headphones')
insert into Product values (7,'Headphones','Wireless On-head Headphones')
insert into Product values (8,'Headphones','RGB Gaming Headphones')
insert into Product values (9,'Headphones','Beats Headphones')
insert into Product values (10,'Mouse','Simple Wired Mouse')
insert into Product values (11,'Mouse','Wireless Mouse')
insert into Product values (12,'Mouse','RGB Gaming Mouse')
insert into Product values (13,'Keyboard','Simple Wired Keyboard')
insert into Product values (14,'Keyboard','Simple Wireless Keyboard')
insert into Product values (15,'Keyboard','Mechanical Keyboard')
insert into Product values (15,'Keyboard','RGB Gaming Keyboard')

select*from Product

-----------------------------------------------------
CREATE TABLE Computers
(
Computer_ID int PRIMARY KEY,
Product_Type_No int  references Product,
Computer_Name varchar(50),
Computer_Manufacturer_Name varchar(10),
Computer_Specs varchar(100),
Computer_Price money
)

insert into Computers values (113,1,'ASUS Prime 14','ASUS', 'Intel i5-1200 Processor & Intel HD 740 Graphics',999)
insert into Computers values (212,2,'Mac Pro','Apple', 'Intel i9-12500 Processor & Intel HD Graphics',3999)
insert into Computers values (310,3,'ASUS TUF F-4','ASUS TUF', 'Ryzen 5 5900X Processor & Geforce 3060',1999)
insert into Computers values (350,3,'ASUS ROG Strix G-12','ASUS ROG', 'Intel i9-12900K Processor & Geforce 3090 Gamnig Beast',3599)
insert into Computers values (401,3,'MSI Gaming X Edition 6','Intel i7-1277F Processor & Geforce 3080 Gaming X',2999)
insert into Computers values (501,4,'Workstatoin T3500','DELL','Intel Xeon 5680 Processor & Intel HD 520 Graphics',1399)
insert into Computers values (502,4,'Workstation T5500','DELL','Intel Xeon 1620 v2 Processor & Intel HD 630 Graphics',999)
insert into Computers values (503,4,'Thinksystem ST5500','Lenovo','Intel Xeon W-3175X Processor & Intel HD 740 Graphics',1999)

select*from Computers

------------------------------------------------------
CREATE TABLE Customer
(
Customer_ID int PRIMARY KEY,
Customer_Name varchar(20),
Customer_Information varchar(20),
Email varchar(50),
Adress varchar(20),
Country varchar(20),
City varchar(20),
PostalCode int,
Phone varchar(13),
Payment_Method varchar(30),
Order_ID int references Order_Info,
Order_Detail varchar(50),
Order_state varchar(10)
)

insert into Customer values (39,'Wali', 'NULL','wali.muhammad.ahmad@gmail.com','Model Town Q-Block','Pakistan','Lahore',54700,+923147363206,'Credit Card',101,'Product Name: MSI Gaming X Edition ','Shipping')
insert into Customer values (14,'Ali','NULL', 'ali..ahmad@gmail.com','Model Town Q-Block','Pakistan','Lahore',54700,03147363121,'PayPal',0,'NULL','NULL')
insert into Customer values (15,'Ahmad','NULL', 'muhammad.ahmad@gmail.com','Model Town Q-Block','Pakistan','Lahore',54700,042927363206,'Cash',0,'NULL','NULL')

select*from Customer

--------------------------------------------------------
CREATE TABLE Order_Info
(
Order_ID int PRIMARY KEY,
Product_ID int references Product,
Customer_ID int references Customer,
Order_Inforamtion varchar(50),
Order_State varchar(20)
)

insert into Order_Info values (11,2,39,'Product Name: MSI Gaming X Edition','Shipping')

select*from Order_Info
--------------------------------------------------------
