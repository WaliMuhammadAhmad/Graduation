SELECT * From Customers Where ContactName Like 'M%k%'

--SELECT TOP 5 * From Shippers

--SELECT EmployeeID,Count(TitleOfCourtesy) From Employees Where TitleOfCourtesy='Ms.' AND Country='USA' Group By EmployeeID

--SELECT MAX(UnitPrice),MIN(UnitPrice) From Products

SELECT ProductID,ProductName,UnitPrice from Products where UnitPrice < 20