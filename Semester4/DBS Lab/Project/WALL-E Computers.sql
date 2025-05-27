CREATE TABLE Admin
(
Admin_ID int PRIMARY KEY,
Admin_Name varchar(20)
)

insert into Admin values (141,'Wali Muhammad')

select*from Admin

---------------------------------------------------
CREATE TABLE Product
(
Product_ID int PRIMARY KEY,
Product_Name varchar(20),
Product_Manufacturer_Name varchar(50),
Product_Specs varchar(100),
Product_Price money
)

insert into Product values (1,'Normal PC','Alienware', 'Intel i5-12th Gen Processor serires & Geforce GTX GPU',1000)
insert into Product values (2,'Gaming PC','MSI', 'Intel i7-12th Gen Processor serires & Geforce RTX GPU',2000)
insert into Product values (5,'Mouse','Redragon', 'Redragon Griffrn 802 RGB 8 Button Mouse ',200)
insert into Product values (3,'Gaming PC','ASUS ROG', 'Intel i9-12th Gen Processor serires & Geforce RTX GPU',4000)
insert into Product values (4,'Gaming PC','ASUS TUF', 'Ryzen 5000 series Processor serires & Geforce RTX GPU',3000)
insert into Product values (6,'Keyboard','Crosair', 'Crosair K70 RGB Mechanical Keyboead with palm pad',300)

select*from Product

-----------------------------------------------------
CREATE TABLE Computers
(
Computer_ID int PRIMARY KEY,
Computer_Catagoty_No int  references Product,
Computer_Name varchar(50),
Computer_Vendor_Name varchar(10),
Computer_Type varchar(50),
Computer_Specs varchar(100),
Computer_Price money
)

insert into Computers values (213,1,'ASUS Prime 14','ASUS','Desktop PC', 'Intel i5-1200H Processor & Geforce 1650',999)
insert into Computers values (312,4,'ASUS TUF F-4','ASUS TUF','Gaming PC', 'Ryzen 5 5900X Processor & Geforce 3060',1999)
insert into Computers values (243,3,'ASUS ROG Strix G-12','ASUS ROG','Gaming PC', 'Intel i9-12900K Processor & Geforce 3090 Beast',3999)
insert into Computers values (445,2,'MSI Gaming X Edition 6','MSI','Gaming PC', 'Intel i7-1277F Processor & Geforce 1080 Gaming X',2999)

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
