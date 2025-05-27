------------------------------------------------------
--						Table						--
------------------------------------------------------

CREATE TABLE Admin
(
Admin_ID int PRIMARY KEY,
Admin_Name varchar(20),
Admin_Username varchar(20),
Admin_Password varchar(14)
)

insert into Admin values (141,'Wali Muhammad','walim','walim141')

select*from Admin

------------------------------------------------------

CREATE TABLE Salesman
(
Salesman_ID int PRIMARY KEY,
Salesman_Name varchar(20),
Salesman_age int,
Salesman_joining_date date,
Salesman_salery money,
Salesman_Username varchar(20),
Salesman_Password varchar(14)
)

INSERT INTO Salesman VALUES (01,'John',22,'2022-11-4',20000,'john','john123')
INSERT INTO Salesman VALUES (02,'Arthur',28,'2022-10-3',20000,'arthur','arthur123')
INSERT INTO Salesman VALUES (03,'Smith',21,'2022-9-2',20000,'smith','smith123')
INSERT INTO Salesman VALUES (04,'Christopher',25,'2022-10-3',20000,'chris','chris123')
INSERT INTO Salesman VALUES (05,'Zach',23,'2022-11-5',20000,'zach','zach123')

select*from Salesman

------------------------------------------------------

CREATE TABLE Laptop
(
Product_ID INT PRIMARY KEY,
Laptop_Name varchar(30) NOT NULL,
Laptop_Vendor_Name varchar(20) NOT NULL,
Laptop_Specs varchar(50),
Processor varchar(20) NOT NULL,
RAM varchar(10) NOT NULL,
SSD varchar(10) NOT NULL,
HDD varchar(10) NULL,
GPU varchar(30) NULL,
Screen varchar(30) NOT NULL,
Color varchar(10) NOT NULL,
Price money NOT NULL,
)

insert into Laptop values (1,'test','test','test','test','test','test','test','test','test','test',1)

INSERT INTO Laptop VALUES (1001,'Elitebook 840 G5','HP','Elitebook 840 G5 Intel 8th gen','Intel i5 8th gen','8 GB DDR4','256 GB','512 GB',NULL,'14 inches','White',62000)
INSERT INTO Laptop VALUES (1002,'Elitebook 840 G5 i5','HP','Elitebook 840 G5 Intel 7th gen','Intel i5 7th gen','16 GB DDR4','256 GB','512 GB',NULL,'14 inches','White',65000)
INSERT INTO Laptop VALUES (1003,'Elitebook 840 G5 i7','HP','Elitebook 840 G5 Intel 7th gen','Intel i7 7th gen','8 GB DDR4','256 GB','512 GB',NULL,'14 inches','White',68000)
INSERT INTO Laptop VALUES (1004,'Elitebook 840 G6','HP','Elitebook 840 G5 Intel 9th gen','Intel i5 9th gen','16 GB DDR4','256 GB','512 GB',NULL,'14 inches','White',75000)
INSERT INTO Laptop VALUES (1005,'Elitebook 840 G6 i5','HP','Elitebook 840 G5 Intel 8th gen','Intel i5 8th gen','8 GB DDR4','256 GB','512 GB',NULL,'14 inches','White',78000)
INSERT INTO Laptop VALUES (1006,'Elitebook 840 G6 i7','HP','Elitebook 840 G5 Intel 8th gen','Intel i7 8th gen','8 GB DDR4','256 GB','512 GB',NULL,'14 inches','White',85000)
INSERT INTO Laptop VALUES (1007,'Dell 5490','DELL','Dell 5490 Intel i5 8th gen','Intel i5 8th gen','8 GB DDR4','256 GB M2',NULL,NULL,'14 inches','Black',68000)
INSERT INTO Laptop VALUES (1008,'Dell 5470','DELL','Dell 5470 Intel i5 6th gen','Intel i5 6th gen','8 GB DDR4','256 GB M2',NULL,NULL,'14.4 inches','Black',55000)
INSERT INTO Laptop VALUES (1009,'Dell 7270','DELL','Dell 7270 Intel i5 6th gen','Intel i5 8th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',78000)
INSERT INTO Laptop VALUES (1010,'Dell 7280','DELL','Dell 7280 Intel i5 6th gen','Intel i5 8th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',68000)
INSERT INTO Laptop VALUES (1011,'Dell 7290','DELL','Dell 7290 Intel i5 8th gen','Intel i5 8th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',78000)
INSERT INTO Laptop VALUES (1012,'Dell 7470','DELL','Dell 7470 Intel i5 6th gen','Intel i5 6th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',68000)
INSERT INTO Laptop VALUES (1013,'Dell 7480','DELL','Dell 7480 Intel i5 6th gen','Intel i5 6th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',56000)
INSERT INTO Laptop VALUES (1014,'Dell 7490','DELL','Dell 7490 Intel i5 8th gen','Intel i5 8th gen','4 GB DDR4','256 GB M2',NULL,NULL,'14 inches','Black',67000)
INSERT INTO Laptop VALUES (1015,'Dell 5440','DELL','Dell 5440 Intel i3 6th gen','Intel i5 8th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',52000)
INSERT INTO Laptop VALUES (1016,'Dell 5470','DELL','Dell 5470 Intel i5 6th gen','Intel i5 6th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',61000)
INSERT INTO Laptop VALUES (1017,'Dell 5480','DELL','Dell 5480 Intel i5 7th gen','Intel i5 7th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',60000)
INSERT INTO Laptop VALUES (1018,'Dell 5570','DELL','Dell 5570 Intel i5 6th gen','Intel i5 6th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',55000)
INSERT INTO Laptop VALUES (1019,'Dell 5580','DELL','Dell 5580 Intel i5 7th gen','Intel i5 7th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',65000)
INSERT INTO Laptop VALUES (1020,'Lenovo T470','Lenovo','Dell 5570 Intel i3 6th gen','Intel i3 6th gen','8 GB DDR4','128 GB ',NULL,NULL,'14 inches','Black',45000)
INSERT INTO Laptop VALUES (1021,'Yoga 360','Lenovo','Dell 5570 Intel i3 6th gen','Intel i3 6th gen','8 GB DDR4','256 GB ',NULL,NULL,'14 inches','Black',47000)
INSERT INTO Laptop VALUES (1022,'Thinkpad x260','Lenovo','Thinkpad x260 i5 6th','Intel i5 6th gen','8 GB DDR4','256 GB ','500 GB',NULL,'16 inches','Black',61000)
INSERT INTO Laptop VALUES (1023,'Thinkpad x250','Lenovo','Thinkpad x250 i5 5th gen','Intel i5 5th gen','8 GB DDR4','128 GB ','500 GB',NULL,'16 inches','Black',55000)
INSERT INTO Laptop VALUES (1023,'Thinkpad x240','Lenovo','Thinkpad x240 i5 4th gen','Intel i5 5th gen','8 GB DDR4','128 GB ','500 GB',NULL,'16 inches','Black',42000)
INSERT INTO Laptop VALUES (1023,'L440p','Lenovo','Dell 5570 Intel i5 4th gen','Intel i5 4th gen','4 GB DDR4','128 GB ','500 GB',NULL,'14.4 inches','Black',39000)

select*from Laptop
------------------------------------------------------

CREATE TABLE Invoice
(
Invoice_ID int PRIMARY KEY,
Product_ID INT FOREIGN KEY REFERENCES Laptop,
Customer_Name varchar(50) NOT  NULL,
Payment_Amount money NOT NULL,
Invoice_Date date,
Sales_ID INT FOREIGN KEY REFERENCES Sales,
)

INSERT INTO Invoice VALUES (1, 1001, 'John Doe', 62000, '2023-03-1', 3)
INSERT INTO Invoice VALUES (2, 1002, 'Jane Smith', 1200.00, '2023-03-1', 3);
INSERT INTO Invoice VALUES (3, 1003, 'Bob Johnson', 1800.00, '2023-03-2', 3);
INSERT INTO Invoice VALUES (4, 1004, 'Sarah Williams', 2000.00, '2023-03-2', 3);
INSERT INTO Invoice VALUES (5, 1001, 'Mary Brown', 1300.00, '2023-03-2', 3);
INSERT INTO Invoice VALUES (6, 1002, 'David Lee', 1100.00, '2023-03-3', 3);
INSERT INTO Invoice VALUES (7, 1005, 'Karen Chen', 1700.00, '2023-03-3', 3);
INSERT INTO Invoice VALUES (8, 1003, 'Tom Lee', 1900.00, '2023-03-3', 3);
INSERT INTO Invoice VALUES (9, 1004, 'Susan Wang', 2200.00, '2023-03-3', 3);
INSERT INTO Invoice VALUES (10, 1001, 'James Kim', 1400.00, '2023-03-4', 3);
INSERT INTO Invoice VALUES (11, 1002, 'Emily Chen', 1250.00, '2023-03-4', 3);
INSERT INTO Invoice VALUES (12, 1003, 'Alex Brown', 1750.00, '2023-03-4', 3);
INSERT INTO Invoice VALUES (13, 1004, 'Michelle Wang', 2100.00, '2023-03-5', 3);
INSERT INTO Invoice VALUES (14, 1001, 'Peter Lee', 1350.00, '2023-03-5', 3);
INSERT INTO Invoice VALUES (15, 1014, 'Kimberly Kim', 8000.00, '2023-03-5', 3);
INSERT INTO Invoice VALUES (16, 1013, 'Chris Johnson', 7500.00, '2023-03-5', 3);
INSERT INTO Invoice VALUES (17, 1012, 'Maggie Lee', 7000.00, '2023-03-5', 3);
INSERT INTO Invoice VALUES (18, 1011, 'William Davis', 6500.00, '2023-03-6', 3);
INSERT INTO Invoice VALUES (19, 1010, 'Emily Jones', 6000.00, '2023-03-6', 3);
INSERT INTO Invoice VALUES (29, 1009, 'Joshua Park', 5500.00, '2023-03-7', 3);
INSERT INTO Invoice VALUES (30, 1008, 'Karen Wong', 5000.00, '2023-03-7', 3);
INSERT INTO Invoice VALUES (31, 1007, 'Michael Kim', 4500.00, '2023-03-7', 3);
INSERT INTO Invoice VALUES (32, 1006, 'Samantha Chen', 4000.00, '2023-03-8', 3);
INSERT INTO Invoice VALUES (33, 1005, 'David Lee', 3500.00, '2023-3-8', 3);
INSERT INTO Invoice VALUES (34, 1004, 'Sarah Williams', 3000.00, '2023-3-9', 3);
INSERT INTO Invoice VALUES (35, 1003, 'Bob Johnson', 2500.00, '2023-3-9', 3);
INSERT INTO Invoice VALUES (36, 1003, 'Bob Johnson', 2500.00, '2023-3-9', 3);
INSERT INTO Invoice VALUES (37, 1002, 'Jane Smith', 2000.00, '2023-03-11', 3);
INSERT INTO Invoice VALUES (38, 1002, 'John Doe', 1250.00, '2023-03-11', 3);
INSERT INTO Invoice VALUES (39, 1004, 'Sarah Smith', 1350.00, '2023-03-14', 3);
INSERT INTO Invoice VALUES (40, 1001, 'Alex Johnson', 1100.00, '2023-03-17', 3);
INSERT INTO Invoice VALUES (41, 1003, 'Emma Watson', 1200.00, '2023-03-20', 3);
INSERT INTO Invoice VALUES (42, 1005, 'Ryan Reynolds', 1400.00, '2023-03-20', 3);
INSERT INTO Invoice VALUES (43, 1002, 'Jessica Williams', 1250.00, '2023-03-21', 3);
INSERT INTO Invoice VALUES (44, 1004, 'Michael Scott', 1350.00, '2023-03-21', 3);
INSERT INTO Invoice VALUES (45, 1001, 'Pam Beesly', 1100.00, '2023-03-22', 3);
INSERT INTO Invoice VALUES (46, 1003, 'Jim Halpert', 1200.00, '2023-03-24', 3);
INSERT INTO Invoice VALUES (47, 1005, 'Dwight Schrute', 1400.00, '2023-03-24', 3);
INSERT INTO Invoice VALUES (48, 1022, 'John Doe', 1250.00, '2023-03-25', 3);
INSERT INTO Invoice VALUES (49, 1004, 'Sarah Smith', 1350.00, '2023-03-25', 3);
INSERT INTO Invoice VALUES (50, 1001, 'Alex Johnson', 1100.00, '2023-03-27', 3);
INSERT INTO Invoice VALUES (51, 1003, 'Emma Watson', 1200.00, '2023-03-27', 3);
INSERT INTO Invoice VALUES (52, 1005, 'Ryan Reynolds', 1400.00, '2023-03-27', 3);
INSERT INTO Invoice VALUES (53, 1002, 'Jessica Williams', 1250.00, '2023-03-27', 3);
INSERT INTO Invoice VALUES (54, 1024, 'Michael Scott', 1350.00, '2023-03-28', 3);
INSERT INTO Invoice VALUES (55, 1021, 'Pam Beesly', 1100.00, '2023-03-29', 3);
INSERT INTO Invoice VALUES (56, 1023, 'Jim Halpert', 1200.00, '2023-03-29', 3);
INSERT INTO Invoice VALUES (57, 1005, 'Dwight Schrute', 1400.00, '2023-03-29', 3);
INSERT INTO Invoice VALUES (58, 1012, 'John Doe', 1250.00, '2023-03-29', 3);
INSERT INTO Invoice VALUES (59, 1014, 'Sarah Smith', 1350.00, '2023-03-29', 3);
INSERT INTO Invoice VALUES (60, 1010, 'Alex Johnson', 1100.00, '2023-03-30', 3);
INSERT INTO Invoice VALUES (61, 1013, 'Emma Watson', 1200.00, '2023-03-30', 3);
INSERT INTO Invoice VALUES (62, 1005, 'Ryan Reynolds', 1400.00, '2023-03-30', 3);
INSERT INTO Invoice VALUES (63, 1002, 'Jessica Williams', 1250.00, '2023-03-31', 3);
INSERT INTO Invoice VALUES (64, 1014, 'Michael Scott', 1350.00, '2023-03-31', 3);
INSERT INTO Invoice VALUES (65, 1001, 'Pam Beesly', 1100.00, '2023-03-31', 3);
INSERT INTO Invoice VALUES (66, 1003, 'Jim Halpert', 1200.00, '2023-03-31', 3);
INSERT INTO Invoice VALUES (67, 1015, 'Dwight Schrute', 1400.00, '2023-03-31', 3);

INSERT INTO Invoice VALUES (68, 1001, 'John Doe', 62000, '2023-04-1', 4)
INSERT INTO Invoice VALUES (69, 1002, 'Jane Smith', 1200.00, '2023-04-1', 4);
INSERT INTO Invoice VALUES (70, 1013, 'Bob Johnson', 1800.00, '2023-03-1', 4);
INSERT INTO Invoice VALUES (71, 1004, 'Sarah Williams', 2000.00, '2023-04-2', 4);
INSERT INTO Invoice VALUES (72, 1001, 'Mary Brown', 1300.00, '2023-04-2', 4);
INSERT INTO Invoice VALUES (73, 1002, 'David Lee', 1100.00, '2023-04-3', 4);
INSERT INTO Invoice VALUES (74, 1005, 'Karen Chen', 1700.00, '2023-04-3', 4);
INSERT INTO Invoice VALUES (75, 1003, 'Tom Lee', 1900.00, '2023-04-3', 4);
INSERT INTO Invoice VALUES (76, 1004, 'Susan Wang', 2200.00, '2023-04-3', 4);
INSERT INTO Invoice VALUES (77, 1001, 'James Kim', 1400.00, '2023-04-4', 4);
INSERT INTO Invoice VALUES (78, 1002, 'Emily Chen', 1250.00, '2023-04-4', 4);
INSERT INTO Invoice VALUES (79, 1003, 'Alex Brown', 1750.00, '2023-04-4',4);
INSERT INTO Invoice VALUES (80, 1004, 'Michelle Wang', 2100.00, '2023-04-5', 4);
INSERT INTO Invoice VALUES (81, 1001, 'Peter Lee', 1350.00, '2023-04-5', 4);
INSERT INTO Invoice VALUES (82, 1014, 'Kimberly Kim', 8000.00, '2023-04-5', 4);
INSERT INTO Invoice VALUES (83, 1013, 'Chris Johnson', 7500.00, '2023-04-5', 4);
INSERT INTO Invoice VALUES (84, 1012, 'Maggie Lee', 7000.00, '2023-04-5', 4);
INSERT INTO Invoice VALUES (85, 1011, 'William Davis', 6500.00, '2023-04-6', 4);
INSERT INTO Invoice VALUES (86, 1010, 'Emily Jones', 6000.00, '2023-04-6', 4);
INSERT INTO Invoice VALUES (87, 1009, 'Joshua Park', 5500.00, '2023-04-7', 4);
INSERT INTO Invoice VALUES (88, 1008, 'Karen Wong', 5000.00, '2023-04-7', 4);
INSERT INTO Invoice VALUES (89, 1007, 'Michael Kim', 4500.00, '2023-04-8', 4);
INSERT INTO Invoice VALUES (90, 1006, 'Samantha Chen', 4000.00, '2023-4-8', 4);
INSERT INTO Invoice VALUES (91, 1005, 'David Lee', 3500.00, '2023-4-8', 4);
INSERT INTO Invoice VALUES (92, 1004, 'Sarah Williams', 3000.00, '2023-4-9', 4);
INSERT INTO Invoice VALUES (93, 1003, 'Bob Johnson', 2500.00, '2023-4-10', 4);
INSERT INTO Invoice VALUES (93, 1003, 'Bob Johnson', 2500.00, '2023-4-10', 4);
INSERT INTO Invoice VALUES (95, 1002, 'Jane Smith', 2000.00, '2023-04-11', 4);
INSERT INTO Invoice VALUES (96, 1002, 'John Doe', 1250.00, '2023-04-11', 4);
INSERT INTO Invoice VALUES (97, 1004, 'Sarah Smith', 1350.00, '2023-04-14', 4);
INSERT INTO Invoice VALUES (98, 1001, 'Alex Johnson', 1100.00, '2023-04-17', 4);
INSERT INTO Invoice VALUES (99, 1003, 'Emma Watson', 1200.00, '2023-04-20', 4);
INSERT INTO Invoice VALUES (100, 1005, 'Ryan Reynolds', 1400.00, '2023-04-20', 4);
INSERT INTO Invoice VALUES (101, 1002, 'Jessica Williams', 1250.00, '2023-04-21', 4);
INSERT INTO Invoice VALUES (102, 1004, 'Michael Scott', 1350.00, '2023-04-21', 4);
INSERT INTO Invoice VALUES (103, 1001, 'Pam Beesly', 1100.00, '2023-04-22', 4);
INSERT INTO Invoice VALUES (104, 1003, 'Jim Halpert', 1200.00, '2023-04-24', 4);
INSERT INTO Invoice VALUES (105, 1005, 'Dwight Schrute', 1400.00, '2023-04-24', 4);
INSERT INTO Invoice VALUES (106, 1022, 'John Doe', 1250.00, '2023-04-25', 4);
INSERT INTO Invoice VALUES (107, 1004, 'Sarah Smith', 1350.00, '2023-04-25', 4);
INSERT INTO Invoice VALUES (131, 1005, 'Ryan Reynolds', 1400.00, '2023-04-26', 4);
INSERT INTO Invoice VALUES (132, 1002, 'Jessica Williams', 1250.00, '2023-04-26', 4);
INSERT INTO Invoice VALUES (134, 1001, 'Pam Beesly', 1100.00, '2023-04-26', 4);
INSERT INTO Invoice VALUES (135, 1003, 'Jim Halpert', 1200.00, '2023-04-26', 4);
INSERT INTO Invoice VALUES (136, 1005, 'Dwight Schrute', 1400.00, '2023-04-26', 4);
INSERT INTO Invoice VALUES (108, 1001, 'Alex Johnson', 1100.00, '2023-04-27', 4);
INSERT INTO Invoice VALUES (109, 1003, 'Emma Watson', 1200.00, '2023-04-27', 4);
INSERT INTO Invoice VALUES (110, 1005, 'Ryan Reynolds', 1400.00, '2023-04-27', 4);
INSERT INTO Invoice VALUES (133, 1004, 'Michael Scott', 1350.00, '2023-04-27', 4);
INSERT INTO Invoice VALUES (112, 1002, 'Jessica Williams', 1250.00, '2023-04-27', 4);
INSERT INTO Invoice VALUES (113, 1024, 'Michael Scott', 1350.00, '2023-04-28', 4);
INSERT INTO Invoice VALUES (114, 1021, 'Pam Beesly', 1100.00, '2023-04-29', 4);
INSERT INTO Invoice VALUES (115, 1023, 'Jim Halpert', 1200.00, '2023-04-29', 4);
INSERT INTO Invoice VALUES (116, 1005, 'Dwight Schrute', 1400.00, '2023-04-29', 4);
INSERT INTO Invoice VALUES (117, 1012, 'John Doe', 1250.00, '2023-04-29', 4);
INSERT INTO Invoice VALUES (118, 1014, 'Sarah Smith', 1350.00, '2023-04-29', 4);
INSERT INTO Invoice VALUES (119, 1010, 'Alex Johnson', 1100.00, '2023-04-30', 4);
INSERT INTO Invoice VALUES (120, 1013, 'Emma Watson', 1200.00, '2023-04-30', 4);
INSERT INTO Invoice VALUES (121, 1005, 'Ryan Reynolds', 1400.00, '2023-04-30', 4);
INSERT INTO Invoice VALUES (127, 1002, 'John Doe', 1250.00, '2023-04-30', 4);
INSERT INTO Invoice VALUES (128, 1004, 'Sarah Smith', 1350.00, '2023-04-30', 4);
INSERT INTO Invoice VALUES (129, 1001, 'Alex Johnson', 1100.00, '2023-04-30', 4);
INSERT INTO Invoice VALUES (130, 1003, 'Emma Watson', 1200.00, '2023-04-30', 4);

select * from Invoice

------------------------------------------------------

CREATE TABLE Sales
(
Sales_ID INT PRIMARY KEY,
Sales_month varchar(10) NOT NULL,
Monthly_sales_amount money,
)

INSERT INTO Sales VALUES (3,'March',210000)
INSERT INTO Sales VALUES (4,'April',250000)

select * from Sales

------------------------------------------------------

------------------------------------------------------
--				  Prodcedure						--
------------------------------------------------------
--					Search							--
------------------------------------------------------

GO
CREATE PROCEDURE Sales_Month (@month varchar(10))
AS BEGIN
SELECT Sales_month,Monthly_sales_amount FROM Sales WHERE Sales.Sales_month = @month;
END;

EXEC Sales_Month 'April'

------------------------------------------------------

GO
CREATE PROCEDURE Search_invoice_by_name (@customer varchar(50))
AS BEGIN
SELECT * FROM Invoice WHERE Invoice.Customer_Name = @customer;
END;

EXEC Search_invoice_by_name 'Tom Lee'

------------------------------------------------------

GO
CREATE PROCEDURE Search_invoice_by_id (@order_id INT)
AS BEGIN
SELECT * FROM Invoice WHERE Invoice.Invoice_ID = @order_id;
END;

EXEC Search_invoice_by_id 136

------------------------------------------------------

GO
CREATE PROCEDURE Search_laptop_by_id (@id INT)
AS BEGIN
SELECT * FROM Laptop WHERE Laptop.Product_ID = @id;
END;

EXEC Search_laptop_by_id 1001

------------------------------------------------------

GO
CREATE PROCEDURE Search_laptop_by_name (@name varchar(50))
AS BEGIN
SELECT * FROM Laptop WHERE Laptop.Laptop_Name = @name;
END;

EXEC Search_laptop_by_name 'DELL 7490'

------------------------------------------------------

GO
CREATE PROCEDURE Search_salesman_by_name (@name varchar(50))
AS BEGIN
SELECT * FROM Salesman WHERE Salesman.Salesman_Name = @name;
END;

EXEC Search_salesman_by_name 'Arthur'

------------------------------------------------------

GO
CREATE PROCEDURE Search_salesman_by_id (@id INT)
AS BEGIN
SELECT * FROM Salesman WHERE Salesman.Salesman_ID = @id;
END;

EXEC Search_salesman_by_id 01

------------------------------------------------------

------------------------------------------------------
--					Delete							--
------------------------------------------------------

DROP PROCEDURE IF EXISTS Delete_computer_by_name;
GO
CREATE PROCEDURE Delete_Sales_Month (@month varchar(10))
AS BEGIN
Delete FROM Sales WHERE Sales.Sales_month = @month;
END;

EXEC Delete_Sales_Month 'January'

------------------------------------------------------

GO
CREATE PROCEDURE Delete_invoice_by_id (@order_id INT)
AS BEGIN
Delete FROM Invoice WHERE Invoice.Invoice_ID = @order_id;
END;

EXEC Delete_invoice_by_id 37

------------------------------------------------------

GO
CREATE PROCEDURE Delete_laptop_by_id (@id INT)
AS BEGIN
Delete FROM Laptop WHERE Laptop.Product_ID = @id;
END;

EXEC Delete_computer_by_id 113

------------------------------------------------------

GO
CREATE PROCEDURE Delete_laptop_by_name (@name varchar(50))
AS BEGIN
Delete FROM Laptop WHERE Laptop.Laptop_Name = @name;
END;

EXEC Delete_computer_by_name 'ASUS TUF Gaming'

------------------------------------------------------

GO
CREATE PROCEDURE Delete_salesman_by_name (@name varchar(50))
AS BEGIN
Delete FROM Salesman WHERE Salesman.Salesman_Name = @name;
END;

EXEC Delete_salesman_by_name 'Arthur'

------------------------------------------------------

GO
CREATE PROCEDURE Delete_salesman_by_id (@id INT)
AS BEGIN
Delete FROM Salesman WHERE Salesman.Salesman_ID = @id;
END;

EXEC Delete_salesman_by_id 01

------------------------------------------------------
------------------------------------------------------
--					Triggers						--
------------------------------------------------------
