#pragma once
#include "DummyDataProvider.h"
#include "SqlDataProvider.h"
class Recommender {
private:
	// DummyDataProvider _provider{};
	SqlDataProvider _provider{};
public:
	bool login(const int customerID);
	std::vector<Item> const& getItems();
	std::vector<Customer> const& getCustomers();
	std::vector<SalesHistory> const& getSalesHistory();
	std::vector<SalesHistory> const getPurchasesHistory(const int customerID);
	std::vector<Item> getRecommendations(const int customerID);
};

