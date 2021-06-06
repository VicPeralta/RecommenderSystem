// recommender.cpp
// Copyright 2021 Victor Peralta
// victor.peralta.gomez@gmail.com

/*
	This is basic recommender system.
	Bases on a purchase history of a client, it recommend items that are releated
*/
#define UNICODE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <set>
#include "win32/Utils/utils.h"

template<int Min, int Max>
class generator
{
private:
	std::random_device m_device;
	std::mt19937 m_gen;
	std::uniform_int_distribution<int> m_distribution{ Min, Max };
public:
	generator() :m_gen{ m_device() } {};
	int getNextValue() {
		return m_distribution(m_gen);
	}
};

struct Customer {
	int Id;
	std::string Name;
};

struct Item {
	int Id;
	std::string Name;
	int CategoryId;
};

struct Category {
	int Id;
	std::string Name;
};

struct SalesHistory {
	int OrderId;
	int CustId;
	int ItemId;
};

void generateRandomData(std::vector<Customer>& customers, std::vector<Category>& categories,
	std::vector<Item>& items, std::vector<SalesHistory>& salesHistory);

void showData(std::vector<Customer>const& customers, std::vector<Category> const& categories,
	std::vector<Item> const& items, std::vector<SalesHistory> const& salesHistory);

void showItems(std::vector<Item>const& items);

void showCustomers(std::vector<Customer> const& customers);

void showHistoryCustomer(std::vector<SalesHistory>const& salesHistory, int const customer, std::vector<Item>const& items);

void showRecommendedItems(std::vector<SalesHistory>const& salesHistory, int const customer, std::vector<Item> const& items);

bool login(int const customer, std::vector <Customer> const& custumers);

std::string getProductName(std::vector<Item> const& items, int const id);

int main() {
	std::vector<Customer> customers;
	std::vector<Category> categories;
	std::vector<Item> items;
	std::vector<SalesHistory> salesHistory;
	generateRandomData(customers, categories, items, salesHistory);
	showData(customers, categories, items, salesHistory);
	int option{};
	int customer{};
	for (;;) {
		std::cout << "Enter your customer ID\n";
		std::cin >> customer;
		if (login(customer, customers)) {

			do {
				std::cout << "\n1.- View all available items\n";
				std::cout << "2.- View purchase history\n";
				std::cout << "3.- View recommended items\n";
				std::cout << "4.- Login again\n";
				std::cout << "5.- Exit\n";
				std::cin >> option;
				switch (option)
				{
				case 1:
					showItems(items);
					break;
				case 2:
					showHistoryCustomer(salesHistory, customer, items);
					break;
				case 3:
					showRecommendedItems(salesHistory, customer, items);
					break;
				case 4:
					break;
				case 5:
					return 0;
				default:
					break;
				}
			} while (option != 4);
		}
		else {
			std::cout << "Invalid ID\n";
			std::cout << "Try again...\n";
		}
	}
	return 0;
}
void showItems(std::vector<Item> const& items) {
	std::cout << ConsoleColor::foregroundRed << "Items\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen << "Item# " << "\t Description\t Category\n" << ConsoleColor::foregroundDefault;
	for (auto& i : items)
		std::cout << i.Id << "\t" << i.Name << " \t\t" << i.CategoryId << "\n";
}

void showCustomers(std::vector<Customer> const& customers) {
	std::cout << "Customers\n";
	for (auto& i : customers)
		std::cout << "\tId:" << i.Id << "\t" << i.Name << "\n";
}

void showHistoryCustomer(std::vector<SalesHistory> const& salesHistory, int const customer, std::vector<Item> const& items) {
	std::cout << ConsoleColor::foregroundRed << "Purchase History\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen << "Order# " << "\t Item#\t Description\n" << ConsoleColor::foregroundDefault;
	for (auto& i : salesHistory) {
		if (i.CustId == customer) {
			std::cout << i.OrderId << "\t " << i.ItemId;
			std::cout << "\t " << getProductName(items, i.ItemId) << "\n";
		}
	}
}

std::string getProductName(std::vector<Item> const& items, int const id) {
	auto res = std::find_if(items.begin(), items.end(), [id](const Item& i) {
		return i.Id == id;
		});
	return (*res).Name;
}
int getCategoryProduct(std::vector<Item> const& items, int const id) {
	auto res = std::find_if(items.begin(), items.end(), [id](const Item& i) {
		return i.Id == id;
		});
	return (*res).CategoryId;
}

void showData(std::vector<Customer> const& customers, std::vector<Category> const& categories,
	std::vector<Item> const& items, std::vector<SalesHistory> const& salesHistory) {
	ConsoleColor cc;

	std::cout << ConsoleColor::foregroundRed << "Items\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen << "Item#\t\tName\t\t\tCategory\n" << ConsoleColor::foregroundDefault;
	for (auto& i : items)
		std::cout << i.Id << "\t\t" << i.Name << "  \t\t\t" << i.CategoryId << "\n";
	std::cout << ConsoleColor::foregroundRed << "Customers\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen << "ID#\t\tName\n" << ConsoleColor::foregroundDefault;
	for (auto& i : customers)
		std::cout << i.Id << "\t\t" << i.Name << "\n";
	std::cout << ConsoleColor::foregroundRed << "Categories\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen << "ID#\t\tName\n" << ConsoleColor::foregroundDefault;
	for (auto& i : categories)
		std::cout << i.Id << "\t\t" << i.Name << "\n";
	std::cout << ConsoleColor::foregroundRed << "History\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen << "OrderID#\tCustomerID#\t\tItem#\n" << ConsoleColor::foregroundDefault;
	for (auto& i : salesHistory)
		std::cout << i.OrderId << "\t\t" << i.CustId << "\t\t\t" << i.ItemId << "\n";
}

void generateRandomData(std::vector<Customer>& customers, std::vector<Category>& categories,
	std::vector<Item>& items, std::vector<SalesHistory>& salesHistory) {
	for (int i = 0; i < 25; i++) {
		customers.push_back({ i,std::string{"Customer #"}.append(std::to_string(i)) });
	}
	for (int i = 0; i < 10; i++) {
		categories.push_back({ i,std::string{"Category #"}.append(std::to_string(i)) });
	}
	for (int i = 0; i < 30; i++) {
		items.push_back({ i,std::string{"Item #"}.append(std::to_string(i)), i / 3 });
	}
	generator<1, 4> itemsPerOrden{};
	generator<0, 30> item;
	int orderid{};
	for (int c = 0; c < customers.size(); c++) {
		for (int i = 0; i < itemsPerOrden.getNextValue(); i++) {
			salesHistory.push_back({ orderid, c, item.getNextValue() });
		}
		orderid++;
	}
}

bool login(int const customer, std::vector<Customer> const& customers) {
	auto res = std::find_if(customers.begin(), customers.end(), [customer](const Customer& c) {
		return c.Id == customer;
		});
	if (res == customers.end()) return false;
	return true;
}

void showRecommendedItems(std::vector<SalesHistory>const& salesHistory, int const customer, std::vector<Item> const& items) {
	// get items purchased by this customer
	std::set<int> itemsPurchased;
	std::set<int> categories;
	for (auto& i : salesHistory) {
		if (i.CustId == customer) {
			itemsPurchased.insert(i.ItemId);
			categories.insert(getCategoryProduct(items, i.ItemId));
		}
	}
	std::cout << ConsoleColor::foregroundRed << "Recommendations based on purchased history\n" << ConsoleColor::foregroundDefault;
	std::cout << ConsoleColor::foregroundGreen << "Item# " << "\t Description\t Category\n" << ConsoleColor::foregroundDefault;
	for (auto& c : categories) {
		for(const auto &i: items)
		if (i.CategoryId==c) {
			if(itemsPurchased.find(i.Id)==itemsPurchased.end())
				std::cout << i.Id << "\t" << i.Name << " \t\t" << i.CategoryId << "\n";
		}
	}
}

