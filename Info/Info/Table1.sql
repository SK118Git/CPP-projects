
CREATE TABLE [dbo].[Department]
(
	[Id_dep] INT NOT NULL PRIMARY KEY,
	[NOM_dep] NCHAR(40)
)

Go 

CREATE TABLE [dbo].[Employees]
(
	[Id] INT NOT NULL PRIMARY KEY,
	[Nom] NCHAR(40),
	[Prenom] NCHAR(40),
	[Age] INT, 
	[Salaire] INT, 
	[Formation] NCHAR(40),
	[Dep] INT,
	FOREIGN KEY ([Dep]) REFERENCES Department([Id_dep]) 
)

Go

CREATE TABLE [dbo].[vehicule]
(
	id_vehicule INT NOT NULL PRIMARY KEY,
	marque NCHAR(40),
	modele NCHAR(40),
	prix_neuf INT
)

Go 

CREATE TABLE [dbo].[annonce]
(
	id_annonce INT NOT NULL PRIMARY KEY,
	annee INT,
	km INT,
	prix_occassion INT,
	id_vehicule INT FOREIGN KEY REFERENCES vehicule(id_vehicule)
)
