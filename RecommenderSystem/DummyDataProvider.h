#pragma once
#include "IDataProvider.h"
class DummyDataProvider: public IDataProvider
{
public:
	DummyDataProvider();
	// Heredado vía IDataProvider
	virtual std::vector<Customer>const& getCustomers() override;
	virtual std::vector<Item>const& getItems() override;
	virtual std::vector<Item>const getRecomendations(const int customerID) override;
	virtual std::vector<SalesHistory> const& getAllSalesHistory() override;
	virtual std::vector<SalesHistory> const getCustomerPurchaseHistory(const int customerID) override;
private:
	std::vector<Customer> _customers;
	std::vector<Item> _items;
	std::vector<SalesHistory> _salesHistory;
};

