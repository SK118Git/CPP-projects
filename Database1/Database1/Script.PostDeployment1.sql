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

TRUNCATE TABLE Persons;

INSERT INTO Persons (PersonID, LastName, FirstName, Addressloc, City) 
VALUES (1, 'KISTNASSAMY', 'Lucas', 'Arras', 'Sartrouville');

INSERT INTO Persons (PersonID, LastName, FirstName, Addressloc, City) 
VALUES (2, 'KISTNASSAMY', 'Mevin', 'Arras', 'Sartrouville');

INSERT INTO Persons (PersonID, LastName, FirstName, Addressloc, City) 
VALUES (3, 'KISTNASSAMY', 'Sophie', 'Arras', 'Sartrouville');

INSERT INTO Persons (PersonID, LastName, FirstName, Addressloc, City) 
VALUES (4, 'KISTNASSAMY', 'Sasha', 'Arras', 'Sartrouville');

SELECT * FROM Persons;