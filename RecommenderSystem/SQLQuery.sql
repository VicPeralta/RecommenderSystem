
USE Poco
CREATE SCHEMA Recommender AUTHORIZATION dbo;
GO
DROP TABLE IF EXISTS Recommender.Customers;
GO
CREATE TABLE Recommender.Customers(
	ID integer NOT NULL,
	Name VARCHAR(30)
	CONSTRAINT Customers_PK_Ids
	PRIMARY KEY(ID)
);
GO
DROP TABLE IF EXISTS Recommender.Categories;
GO
CREATE TABLE Recommender.Categories(
	ID integer NOT NULL,
	Name VARCHAR(30)
	CONSTRAINT Categories_PK_Ids
	PRIMARY KEY(ID)
);
GO
DROP TABLE IF EXISTS Recommender.Items;
GO
CREATE TABLE Recommender.Items(
	ID integer NOT NULL,
	Name VARCHAR(30) NOT NULL,
	Category_ID integer NOT NULL,
	CONSTRAINT Items_PK_Ids
	PRIMARY KEY(ID)
);
GO
DROP TABLE IF EXISTS Recommender.SalesHistory;
GO
CREATE TABLE Recommender.SalesHistory(
	ID integer IDENTITY(1,1), 
	OrderID integer NOT NULL,
	CustomerID integer NOT NULL,
	ItemID integer NOT NULL,
	CONSTRAINT Sales_PK_Ids
	PRIMARY KEY(ID),
	CONSTRAINT FK_Sales_Customers FOREIGN KEY(CustomerID)
	REFERENCES Recommender.Customers(ID),
	CONSTRAINT FK_Sales_Items FOREIGN KEY(ItemID)
	REFERENCES Recommender.Items(ID),
);
GO
-- Populate Customers table
INSERT INTO Recommender.Customers VALUES(0, 'Victor Peralta');
INSERT INTO Recommender.Customers VALUES(1, 'Michael Jordan');
INSERT INTO Recommender.Customers VALUES(2, 'Irving Johnson');
INSERT INTO Recommender.Customers VALUES(3, 'Tim Duncan');
INSERT INTO Recommender.Customers VALUES(4, 'Isaac Newton');
INSERT INTO Recommender.Customers VALUES(5, 'Galileo Galilei');
INSERT INTO Recommender.Customers VALUES(6, 'Leonardo Da Vinci');
INSERT INTO Recommender.Customers VALUES(7, 'Thomas Edison');
INSERT INTO Recommender.Customers VALUES(8, 'Nikola Tesla');
INSERT INTO Recommender.Customers VALUES(9, 'Bill Gates');
INSERT INTO Recommender.Customers VALUES(10, 'Joe Montana');
INSERT INTO Recommender.Customers VALUES(11, 'Jerry Rice');
INSERT INTO Recommender.Customers VALUES(12, 'Miguel Superman Marin');
INSERT INTO Recommender.Customers VALUES(13, 'Clark Kent');
INSERT INTO Recommender.Customers VALUES(14, 'Bruno Diaz');
INSERT INTO Recommender.Customers VALUES(15, 'Diego Maradona');
INSERT INTO Recommender.Customers VALUES(16, 'Albert Einstein');
INSERT INTO Recommender.Customers VALUES(17, 'Vincent Van Gogh');
INSERT INTO Recommender.Customers VALUES(18, 'Nadia Comanechi');
INSERT INTO Recommender.Customers VALUES(19, 'Ben Johnson');
INSERT INTO Recommender.Customers VALUES(20, 'Dennis Ritchie');
INSERT INTO Recommender.Customers VALUES(21, 'Stephen Hawking');
INSERT INTO Recommender.Customers VALUES(22, 'Johannes Keppler');
INSERT INTO Recommender.Customers VALUES(23, 'Nicolas Copernico');
INSERT INTO Recommender.Customers VALUES(24, 'Marie Curie');
INSERT INTO Recommender.Customers VALUES(25, 'Arquimedes De Siracusa');
-- Populate Categories table
INSERT INTO Recommender.Categories VALUES(0, 'Office Supply');
INSERT INTO Recommender.Categories VALUES(1, 'Furniture');
INSERT INTO Recommender.Categories VALUES(2, 'Electronics');
INSERT INTO Recommender.Categories VALUES(3, 'Break Room');
INSERT INTO Recommender.Categories VALUES(4, 'Computers');
INSERT INTO Recommender.Categories VALUES(5, 'Accesories Office');
INSERT INTO Recommender.Categories VALUES(6, 'Accesories Computers');
INSERT INTO Recommender.Categories VALUES(7, 'School Supplies');
INSERT INTO Recommender.Categories VALUES(8, 'Ink & Toner');
INSERT INTO Recommender.Categories VALUES(9, 'Cleaning');
INSERT INTO Recommender.Categories VALUES(10, 'Printing');
INSERT INTO Recommender.Categories VALUES(11, 'Scanning');

-- Populate table Items
INSERT INTO Recommender.Items VALUES(0,'Printing paper',0) -- Office Supply
INSERT INTO Recommender.Items VALUES(1,'File folders',0)
INSERT INTO Recommender.Items VALUES(2,'Markers & Pencils',0)
INSERT INTO Recommender.Items VALUES(3,'Office chair',1) -- Furniture
INSERT INTO Recommender.Items VALUES(4,'File Cabinet',1)
INSERT INTO Recommender.Items VALUES(5,'Conference tables',1)
INSERT INTO Recommender.Items VALUES(6,'Calculators',2) -- Electronics
INSERT INTO Recommender.Items VALUES(7,'Shredders',2)
INSERT INTO Recommender.Items VALUES(8,'Cash registers',2)
INSERT INTO Recommender.Items VALUES(9,'Coffe & Supplies',3)--Break Room
INSERT INTO Recommender.Items VALUES(10,'Cooking Utensils',3)
INSERT INTO Recommender.Items VALUES(11,'Enery drinks',3)
INSERT INTO Recommender.Items VALUES(12,'Dell Inspiron 15 3501',4)--Computer
INSERT INTO Recommender.Items VALUES(13,'HP Pavilion',4)
INSERT INTO Recommender.Items VALUES(14,'Lenovo IdeaPad ',4)
INSERT INTO Recommender.Items VALUES(15,'Desk organizer',5)--Accesories Office
INSERT INTO Recommender.Items VALUES(16,'Desk pad',5)
INSERT INTO Recommender.Items VALUES(17,'Document holder',5)
INSERT INTO Recommender.Items VALUES(18,'Computer Headset',6)--Accesories Computers
INSERT INTO Recommender.Items VALUES(19,'Computer speakers',6)
INSERT INTO Recommender.Items VALUES(20,'Gaming keyboards',6)
INSERT INTO Recommender.Items VALUES(21,'Notebook five stars',7)--School Supply
INSERT INTO Recommender.Items VALUES(22,'Notebook Office depot',7)
INSERT INTO Recommender.Items VALUES(23,'Backpack Black',7)
INSERT INTO Recommender.Items VALUES(24,'HP 10 Black',8) -- Ink & Toner
INSERT INTO Recommender.Items VALUES(25,'HP 10 Magenta',8)
INSERT INTO Recommender.Items VALUES(26,'HP 10 Cyan',8)
INSERT INTO Recommender.Items VALUES(27,'Paper towels',9)--Cleaning
INSERT INTO Recommender.Items VALUES(28,'Toilet paper',9)
INSERT INTO Recommender.Items VALUES(29,'Cleaning tool Set',9)
INSERT INTO Recommender.Items VALUES(30,'HP Printing paper',10) --printing
INSERT INTO Recommender.Items VALUES(31,'HP Scanner 1231',11) --scanning
-- OrderID, CustomerID, ItemID
INSERT INTO Recommender.SalesHistory VALUES(0,0,7)
INSERT INTO Recommender.SalesHistory VALUES(0,0,4)
INSERT INTO Recommender.SalesHistory VALUES(0,0,3)

INSERT INTO Recommender.SalesHistory VALUES(1,1,31)
INSERT INTO Recommender.SalesHistory VALUES(1,1,21)
INSERT INTO Recommender.SalesHistory VALUES(1,1,11)

INSERT INTO Recommender.SalesHistory VALUES(2,2,2)
INSERT INTO Recommender.SalesHistory VALUES(2,2,12)
INSERT INTO Recommender.SalesHistory VALUES(2,2,8)

INSERT INTO Recommender.SalesHistory VALUES(3,3,30)
INSERT INTO Recommender.SalesHistory VALUES(3,3,6)
INSERT INTO Recommender.SalesHistory VALUES(3,3,1)

INSERT INTO Recommender.SalesHistory VALUES(4,4,5)
INSERT INTO Recommender.SalesHistory VALUES(4,4,13)
INSERT INTO Recommender.SalesHistory VALUES(4,4,14)

INSERT INTO Recommender.SalesHistory VALUES(5,5,9)
INSERT INTO Recommender.SalesHistory VALUES(5,5,25)
INSERT INTO Recommender.SalesHistory VALUES(5,5,15)

INSERT INTO Recommender.SalesHistory VALUES(6,6,14)
INSERT INTO Recommender.SalesHistory VALUES(6,6,26)
INSERT INTO Recommender.SalesHistory VALUES(6,6,28)

INSERT INTO Recommender.SalesHistory VALUES(7,7,27)
INSERT INTO Recommender.SalesHistory VALUES(7,7,29)
INSERT INTO Recommender.SalesHistory VALUES(7,7,16)

INSERT INTO Recommender.SalesHistory VALUES(8,8,18)
INSERT INTO Recommender.SalesHistory VALUES(8,8,27)
INSERT INTO Recommender.SalesHistory VALUES(8,8,17)

INSERT INTO Recommender.SalesHistory VALUES(9,9,16)
INSERT INTO Recommender.SalesHistory VALUES(9,9,26)
INSERT INTO Recommender.SalesHistory VALUES(9,9,6)

INSERT INTO Recommender.SalesHistory VALUES(10,10,5)
INSERT INTO Recommender.SalesHistory VALUES(10,10,15)
INSERT INTO Recommender.SalesHistory VALUES(10,10,25)

INSERT INTO Recommender.SalesHistory VALUES(11,11,1)
INSERT INTO Recommender.SalesHistory VALUES(11,11,11)
INSERT INTO Recommender.SalesHistory VALUES(11,11,21)

INSERT INTO Recommender.SalesHistory VALUES(12,12,2)
INSERT INTO Recommender.SalesHistory VALUES(12,12,22)
INSERT INTO Recommender.SalesHistory VALUES(12,12,18)

INSERT INTO Recommender.SalesHistory VALUES(13,13,6)
INSERT INTO Recommender.SalesHistory VALUES(13,13,16)
INSERT INTO Recommender.SalesHistory VALUES(13,13,26)

INSERT INTO Recommender.SalesHistory VALUES(14,14,7)
INSERT INTO Recommender.SalesHistory VALUES(14,14,17)
INSERT INTO Recommender.SalesHistory VALUES(14,14,27)

INSERT INTO Recommender.SalesHistory VALUES(15,15,8)
INSERT INTO Recommender.SalesHistory VALUES(15,15,18)
INSERT INTO Recommender.SalesHistory VALUES(15,15,28)

INSERT INTO Recommender.SalesHistory VALUES(16,16,9)
INSERT INTO Recommender.SalesHistory VALUES(16,16,19)
INSERT INTO Recommender.SalesHistory VALUES(16,16,29)

INSERT INTO Recommender.SalesHistory VALUES(17,17,0)
INSERT INTO Recommender.SalesHistory VALUES(17,17,10)
INSERT INTO Recommender.SalesHistory VALUES(17,17,20)

INSERT INTO Recommender.SalesHistory VALUES(18,18,30)
INSERT INTO Recommender.SalesHistory VALUES(18,18,4)
INSERT INTO Recommender.SalesHistory VALUES(18,18,14)

INSERT INTO Recommender.SalesHistory VALUES(19,19,8)
INSERT INTO Recommender.SalesHistory VALUES(19,19,2)
INSERT INTO Recommender.SalesHistory VALUES(19,19,6)

INSERT INTO Recommender.SalesHistory VALUES(20,20,2)
INSERT INTO Recommender.SalesHistory VALUES(20,20,10)
INSERT INTO Recommender.SalesHistory VALUES(20,20,30)

INSERT INTO Recommender.SalesHistory VALUES(21,21,7)
INSERT INTO Recommender.SalesHistory VALUES(21,21,3)
INSERT INTO Recommender.SalesHistory VALUES(21,21,11)

INSERT INTO Recommender.SalesHistory VALUES(22,22,23)
INSERT INTO Recommender.SalesHistory VALUES(22,22,28)
INSERT INTO Recommender.SalesHistory VALUES(22,22,0)

INSERT INTO Recommender.SalesHistory VALUES(23,23,22)
INSERT INTO Recommender.SalesHistory VALUES(23,23,24)
INSERT INTO Recommender.SalesHistory VALUES(23,23,27)

INSERT INTO Recommender.SalesHistory VALUES(24,24,0)
INSERT INTO Recommender.SalesHistory VALUES(24,24,3)
INSERT INTO Recommender.SalesHistory VALUES(24,24,7)

INSERT INTO Recommender.SalesHistory VALUES(25,25,6)
INSERT INTO Recommender.SalesHistory VALUES(25,25,30)
INSERT INTO Recommender.SalesHistory VALUES(25,25,28)

-- SELECT SalesHistory
SELECT OrderID,CustomerID, Recommender.Customers.Name, ItemID, Recommender.Items.Name, Recommender.Categories.Name
	FROM Recommender.SalesHistory 
	INNER JOIN Recommender.Customers ON CustomerID= Recommender.Customers.ID
	INNER JOIN Recommender.Items ON ItemID= Recommender.Items.ID
	INNER JOIN Recommender.Categories ON Recommender.Items.Category_ID=Recommender.Categories.ID
ORDER BY OrderID
-- SELECT SalesHistory by customer
SELECT OrderID,CustomerID, Recommender.Customers.Name, ItemID, Recommender.Items.Name, Recommender.Categories.Name
	FROM Recommender.SalesHistory 
	INNER JOIN Recommender.Customers ON CustomerID= Recommender.Customers.ID
	INNER JOIN Recommender.Items ON ItemID= Recommender.Items.ID
	INNER JOIN Recommender.Categories ON Recommender.Items.Category_ID=Recommender.Categories.ID
	WHERE CustomerID=0
ORDER BY OrderID
-- SELECT items by category
SELECT * FROM Recommender.Items 
WHERE Category_ID=2

--SELECT ALL ITEMS
SELECT Recommender.Items.ID, Recommender.Items.Name, Recommender.Categories.Name 
FROM Recommender.Items
INNER JOIN Recommender.Categories ON Category_ID= Recommender.Categories.ID
ORDER BY Recommender.Items.ID

-- SELECT Recomendations by customer
SELECT Recommender.Items.ID, Recommender.Items.Name, Recommender.Categories.Name 
FROM Recommender.Items
INNER JOIN Recommender.Categories ON Category_ID= Recommender.Categories.ID
WHERE Recommender.Items.Category_ID IN 
(SELECT Recommender.Items.Category_ID FROM Recommender.Items
INNER JOIN Recommender.SalesHistory ON  Recommender.Items.ID= Recommender.SalesHistory.ItemID
WHERE Recommender.SalesHistory.CustomerID=0)
AND Recommender.Items.ID NOT IN(
SELECT Recommender.SalesHistory.ItemID FROM Recommender.SalesHistory 
WHERE Recommender.SalesHistory.CustomerID=0)
ORDER BY ID;




