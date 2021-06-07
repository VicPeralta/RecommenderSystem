// recommender.cpp
// Copyright 2021 Victor Peralta
// victor.peralta.gomez@gmail.com
#include "pch.h"
#include "Recommender.h"

std::vector<Item> const& Recommender::getItems() {
	return _provider.getItems();
}

std::vector<Customer> const& Recommender::getCustomers()
{
	return _provider.getCustomers();
}

std::vector<SalesHistory> const& Recommender::getSalesHistory()
{
	return _provider.getAllSalesHistory();
}

std::vector<SalesHistory> const Recommender::getPurchasesHistory(const int customerID)
{
	return _provider.getCustomerPurchaseHistory(customerID);
}

std::vector<Item> Recommender::getRecommendations(const int customerID)
{
	return _provider.getRecomendations(customerID);
}

bool Recommender::login(const int customerID, Customer & customer)
{
	auto customers = _provider.getCustomers();
	auto res = std::find(customers.begin(), customers.end(), customerID);
	if (res == customers.end()) {
		return false;
	}
	else {
		customer = *res;
		return true;
	}
}
