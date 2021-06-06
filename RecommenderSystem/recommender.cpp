// recommender.cpp
// Copyright 2021 Victor Peralta
// victor.peralta.gomez@gmail.com

/*
	This is basic recommender system.
	Bases on a purchase history of a client, it recommend items that are releated
*/

#include "pch.h"
#include "DummyDataProvider.h"
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

bool Recommender::login(const int customerID)
{
	auto customers = _provider.getCustomers();
	if (std::find(customers.begin(), customers.end(), customerID) == customers.end()) return false;
	else return true;
}



