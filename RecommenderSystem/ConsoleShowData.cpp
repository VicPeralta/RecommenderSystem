#include "pch.h"
#include "ConsoleShowData.h"
#include <iostream>
#include <iomanip>

void ConsoleShowData::ShowItems(std::vector<Item>const& items) {
	std::cout << ConsoleColor::foregroundRed << "<<< Items >>>\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen 
		<< std::left << std::setw(20) << "Item#"
		<< std::left << std::setw(30) <<"Description"
		<< std::left << std::setw(20) <<"Category" << ConsoleColor::foregroundDefault << std::endl;
	for (auto& i : items)
		std::cout << std::left <<  std::setw(20)<< i.Id 
		<< std::left << std::setw(30) << i.Name 
		<< std::left << std::setw(20) << i.Category << "\n";
}

void ConsoleShowData::ShowCustomers(std::vector<Customer>const& customers) {
	std::cout << ConsoleColor::foregroundRed << "<<< Customers >>>\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen
		<< std::left << std::setw(20) << "ID#"
		<< std::left << std::setw(30) << "Name"<< ConsoleColor::foregroundDefault << std::endl;
	for (auto& i : customers)
		std::cout << std::left << std::setw(20) << i.Id
		<< std::left << std::setw(30) << i.Name<< "\n";
}

void ConsoleShowData::ShowSalesHistory(std::vector<SalesHistory>const& history) {
	std::cout << ConsoleColor::foregroundRed << "<<< Sales History >>>\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen 
		<< std::left << std::setw(20) << "Order# " 
		<< std::left << std::setw(20) << "Item#" 
		<< std::left << std::setw(30) << "Description" << ConsoleColor::foregroundDefault << std::endl;
	for (auto& i : history) {
		std::cout
			<< std::left << std::setw(20) << i.OrderId
			<< std::left << std::setw(20) << i.ItemID
			<< std::left << std::setw(30) << i.Item << "\n";
	}
}

void ConsoleShowData::ShowPurchaseHistoryCustomer(std::vector<SalesHistory>const& history)
{
	std::cout << ConsoleColor::foregroundRed << "<<< Purchase History >>>\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen 
		<< std::left << std::setw(20) << "Order#" 
		<< std::left << std::setw(20) << "Item#" 
		<< std::left << std::setw(30) << "Description" << ConsoleColor::foregroundDefault << std::endl;
	for (auto& i : history) {
		std::cout 
			<< std::left << std::setw(20)  << i.OrderId 
			<< std::left << std::setw(20) << i.ItemID
			<< std::left << std::setw(30) << i.Item << "\n";
	}
}

void ConsoleShowData::ShowRecommendedItems(std::vector<Item>const& items)
{
	std::cout << ConsoleColor::foregroundRed << "<<< Recommendations based on purchased history >>>\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen 
		<< std::left << std::setw(20) << "Item# "
		<< std::left << std::setw(30) << "Description"
		<< std::left << std::setw(30) << "Category" << ConsoleColor::foregroundDefault << std::endl;
	for (const auto& i : items)
		std::cout 
		<< std::left << std::setw(20) << i.Id 
		<< std::left << std::setw(30) << i.Name
		<< std::left << std::setw(30) << i.Category << "\n";
}
