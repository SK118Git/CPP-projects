/*
Post-Deployment Script Template							
--------------------------------------------------------------------------------------
 This file contains SQL statements that will be appended to the build script.		
 Use SQLCMD syntax to include a file in the post-deployment script.			
 Example:      :r .\myfile.sql								
 Use SQLCMD syntax to reference a variable in the post-deployment script.		
 Example:      :setvar TableName MyTable							
               SELECT * FROM [$(TableName)]					
--------------------------------------------------------------------------------------
*/



/*
INSERT INTO [Department] VALUES (1, 'Secretariat')
INSERT INTO [Department] VALUES (2, 'Marketing')
INSERT INTO [Department] VALUES (3, 'Salesteam')
INSERT INTO [Department] VALUES (4, 'HR')
*/
 
/*
TRUNCATE TABLE Employees
INSERT INTO Employees VALUES (1, 'Jones', 'INDIANA', 49, 4300, 'Archeologist', 2)
INSERT INTO Employees VALUES (2, 'Harry', 'POTTER', 18, 2200, 'Mage', 2)
INSERT INTO Employees VALUES (3, 'Patrick', 'CHIRAC', 58, 2300, 'CAP', 1)
INSERT INTO Employees VALUES (4, 'James', 'BOND', 46, 5500, 'MI6', 4)
INSERT INTO Employees VALUES (5, 'Jean-Claude', 'DUSSE', 54, 1700, 'NULL', 3)
*/

SELECT * FROM Employees
GO
