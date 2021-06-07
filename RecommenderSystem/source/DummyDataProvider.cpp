#include "pch.h"
#include "DummyDataProvider.h"

DummyDataProvider::DummyDataProvider()
{
	_customers = std::vector<Customer>({
		{ 0,"Victor Peralta" },
		{ 1,"Alejandra Peralta" },
		{ 2, "Cynthia Peralta" },
		{ 3, "Rocio Esquinca" },
		{ 4, "John Smith" },
		{ 5, "Earving Johnson" },
		{ 6, "Albert Einstein" },
		{ 7, "Isaac Newton" },
		{ 8, "Benjamin Button"},
		{ 9, "Michael Irving"},
		{ 10, "Joe Montana"}
		});
	_items = std::vector<Item>({
		{0,"Printing paper","Office Supply"},
		{1,"PC Desktop","Furniture"},
		{2,"Regulator","Electronics"},
		{3,"Coffee","Break Room"},
		{4,"Notebook Dell","Computer"},
		{5,"Mouse","Accesories Office"},
		{6,"Mouse","Accesories Computers"},
		{7,"BackPack","School Supplies"},
		{8, "Ink Epson", "Ink & Toner"},
		{9, "Cleaning wipes", "Cleaning"},
		{10, "Printer Epson", "Printing"},
		{11, "Scanner Epson", "Scanning"}
		});
	_salesHistory = std::vector<SalesHistory>({
		{0,0,"Victor Peralta", 7,"BackPack", "School Supplies"},
		{0,0,"Victor Peralta", 8,"Ink Epson", "Ink & Toner"},
		{0,0,"Victor Peralta", 10,"Printer Epson", "Printing"},
		});
}

std::vector<Customer>const& DummyDataProvider::getCustomers()
{
	return _customers;
}

std::vector<Item>const& DummyDataProvider::getItems()
{
	return _items;
}

std::vector<Item> const DummyDataProvider::getRecomendations(const int )
{
	return std::vector<Item>({
		{0,"Printing paper","Office Supply"},
		{1,"PC Desktop","Furniture"},
		{2,"Regulator","Electronics"},
		{3,"Coffee","Break Room"},
		{4,"Notebook Dell","Computer"},
		{5,"Mouse","Accesories"},
		{6,"Mouse","Accesories"},
		{7,"BackPack","School Supplies"},
		{8, "Ink Epson", "Ink & Toner"},
		{9, "Cleaning wipes", "Cleaning"},
		{10, "Printer Epson", "Printing"},
		{11, "Scanner Epson", "Scanning"}
		});
}

std::vector<SalesHistory>const& DummyDataProvider::getAllSalesHistory()
{
	return _salesHistory;
}

std::vector<SalesHistory> const DummyDataProvider::getCustomerPurchaseHistory(const int )
{
	std::vector<SalesHistory> salesHistory{
		{0,0,"Victor Peralta", 7,"BackPack", "School Supplies"},
		{0,0,"Victor Peralta", 8,"Ink Epson", "Ink & Toner"},
		{0,0,"Victor Peralta", 10,"Printer Epson", "Printing"},
	};
	return salesHistory;
}
