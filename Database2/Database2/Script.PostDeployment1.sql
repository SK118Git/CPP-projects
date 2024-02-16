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


Go 
INSERT [dbo].[Table1] ([Id], [Age], [Full Name]) VALUES (3, 20, 'rasha')
INSERT [dbo].[Table1] ([Id], [Age], [Full Name]) VALUES (4, 49, 'kasha')
INSERT [dbo].[Table1] ([Id], [Age], [Full Name]) VALUES (5, 50, 'aasha')


