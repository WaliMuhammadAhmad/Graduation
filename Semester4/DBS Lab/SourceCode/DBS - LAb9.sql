DROP PROCEDURE IF EXISTS customer_view
Go 
Create PROCEDURE customer_view
AS begin 
Select * From Customers 
END;

EXEC customer_view

---------------------------------
DROP PROCEDURE IF EXISTS customer_selected_view
Go
Create PROCEDURE customer_selected_view(@id VARCHAR(20))
As Begin 
Select ContactName,Country, City, Address FROM Customers where CustomerID = @id
END;

EXEC customer_selected_view WALLE;

----------------------------------
DROP PROCEDURE IF EXISTS customer_insert
Go
Create PROCEDURE customer_insert (@id VARCHAR(20),@company VARCHAR(20),@contact VARCHAR(20),@title VARCHAR(20), @address VARCHAR(20), @city VARCHAR(20), @country VARCHAR(20))
As begin 
Insert into Customers (CustomerID,CompanyName, ContactName, ContactTitle, Address, City, Country) 
VALUES (@id, @company, @contact, @title, @address, @city, @country)
END;

EXEC customer_insert 'WALLE','CyberGhost','Wali Muhammad', 'Stakeholder', 'Model town', 'Lahore', 'Pakistan';

----------------------------------
DROP PROCEDURE IF EXISTS customer_delete
Go
Create PROCEDURE customer_delete (@name varchar(20))
AS begin
DELETE FROM Customers where ContactName = @name
END;

EXEC customer_delete 'Wali Muhammad'

-------------------------------------
GO
CREATE TRIGGER insert_trigger
ON Customers
AFTER INSERT
AS
BEGIN
PRINT 'New data added or updated.';
END;

INSERT INTO customers VALUES ('WALLE','CyberGhost','Wali Muhamamd','Stakeholder','Model town','Lahore',NULL,5477,'Pakistan',NULL,NULL)

-------------------------------------
GO 
CREATE TRIGGER any_trigger
ON Customers
AFTER INSERT, DELETE, UPDATE 
AS BEGIN 
PRINT 'Data Added, Update or Deleted'
END;

DELETE FROM Customers WHERE CustomerID = 'WALLE'