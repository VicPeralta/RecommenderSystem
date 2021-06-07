#pragma once

#include "consoleUtils.h"
#include "Item.h"
#include "Customer.h"
#include "SalesHistory.h"
class ConsoleShowData
{
private:
	ConsoleColor _cc;
public:
	void ShowItems(std::vector<Item>const &);
	void ShowCustomers(std::vector<Customer>const&);
	void ShowSalesHistory(std::vector<SalesHistory>const&);
	void ShowPurchaseHistoryCustomer(std::vector<SalesHistory>const&);
	void ShowRecommendedItems(std::vector<Item>const&);
};

