#pragma once
#include <string>
#include <memory>
#include "IDataProvider.h"
#include "Poco\Data\ODBC\Connector.h"
#include "Poco\Data\Session.h"
#include "Poco\Data\SessionFactory.h"

class SqlDataProvider: public IDataProvider
{
public:
	SqlDataProvider(
		std::string connectionString="DRIVER=SQL Server;"
		"UID=poco;PWD=poco;"
		"DATABASE=poco;"
		"SERVER=localhost\\SQLEXPRESS;"
		"port=1433;");
	// Heredado vía IDataProvider
	virtual std::vector<Customer> const& getCustomers() override;
	virtual std::vector<Item> const& getItems() override;
	virtual std::vector<Item> const getRecomendations(const int customerID) override;
	virtual std::vector<SalesHistory> const& getAllSalesHistory() override;
	virtual std::vector<SalesHistory> const getCustomerPurchaseHistory(const int customerID) override;
private:
	std::vector<Customer> _customers;
	std::vector<Item> _items;
	std::vector<SalesHistory> _history;
	std::string _connectionString{};
	std::unique_ptr<Poco::Data::Session> _ptrSession;
	bool _connected{};
};

