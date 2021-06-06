#pragma once
#include <vector>
#include "Customer.h"
#include "Item.h"
#include "SalesHistory.h"
class IDataProvider
{
public:
	virtual std::vector<Customer>const & getCustomers()=0;
	virtual std::vector<Item>const & getItems() = 0;
	virtual std::vector<Item>const getRecomendations(const int customerID) = 0;
	virtual std::vector<SalesHistory>const & getAllSalesHistory() = 0;
	virtual std::vector<SalesHistory>const getCustomerPurchaseHistory(const int customerID) = 0;
};

