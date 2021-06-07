#include "pch.h"
#include "SqlDataProvider.h"
SqlDataProvider::SqlDataProvider(std::string connectionString)
{
	_connectionString = connectionString;
	Poco::Data::ODBC::Connector::registerConnector();
	try {
		_ptrSession = std::make_unique<Poco::Data::Session>(
			std::move(Poco::Data::Session("ODBC", _connectionString.c_str())));
		_connected = true;
	}
	catch (...) {
		_connected = false;
	}
}

std::vector<Customer> const& SqlDataProvider::getCustomers()
{
	_customers.clear();
	if (_connected) {
		Poco::Data::Statement select(*_ptrSession);
		Customer customer{};
		select << "SELECT ID, Name FROM Recommender.Customers;",
			Poco::Data::Keywords::into(customer.Id),
			Poco::Data::Keywords::into(customer.Name),
			Poco::Data::Keywords::range(0, 1);
		while (!select.done()) {
			select.execute();
			_customers.push_back(customer);
		}
	}
	return _customers;
}

std::vector<Item> const& SqlDataProvider::getItems()
{
	_items.clear();
	if (_connected) {
		Poco::Data::Statement select(*_ptrSession);
		Item item{};
		select << "SELECT Recommender.Items.ID, Recommender.Items.Name, Recommender.Categories.Name "
			"FROM Recommender.Items "
			"INNER JOIN Recommender.Categories ON Category_ID = Recommender.Categories.ID "
			"ORDER BY Recommender.Items.ID",
			Poco::Data::Keywords::into(item.Id),
			Poco::Data::Keywords::into(item.Name),
			Poco::Data::Keywords::into(item.Category),
			Poco::Data::Keywords::range(0, 1);
		while (!select.done()) {
			select.execute();
			_items.push_back(item);
		}
	}
	return _items;
}

std::vector<Item> const SqlDataProvider::getRecomendations(const int customerID) 
{
	std::vector<Item> recommendations{};
	if (_connected) {
		Poco::Data::Statement select(*_ptrSession);
		Item item{};
		std::string query{ "SELECT Recommender.Items.ID, Recommender.Items.Name, Recommender.Categories.Name "
		"FROM Recommender.Items "
		"INNER JOIN Recommender.Categories ON Category_ID = Recommender.Categories.ID "
		"WHERE Recommender.Items.Category_ID IN "
		"(SELECT Recommender.Items.Category_ID FROM Recommender.Items "
		"INNER JOIN Recommender.SalesHistory ON  Recommender.Items.ID = Recommender.SalesHistory.ItemID "
		"WHERE Recommender.SalesHistory.CustomerID = " };
		query += std::to_string(customerID);
		query += ")AND Recommender.Items.ID NOT IN( "
			"SELECT Recommender.SalesHistory.ItemID FROM Recommender.SalesHistory "
			"WHERE Recommender.SalesHistory.CustomerID = ";
		query += std::to_string(customerID);
		query += ") ORDER BY ID;";
		select << query,
			Poco::Data::Keywords::into(item.Id),
			Poco::Data::Keywords::into(item.Name),
			Poco::Data::Keywords::into(item.Category),
			Poco::Data::Keywords::range(0, 1);
		while (!select.done()) {
			select.execute();
			recommendations.push_back(item);
		}
	}
	return recommendations;
}

std::vector<SalesHistory> const& SqlDataProvider::getAllSalesHistory()
{
	_history.clear();
	if (_connected) {
		Poco::Data::Statement select(*_ptrSession);
		SalesHistory history{};
		select << "SELECT OrderID,CustomerID, Recommender.Customers.Name, ItemID, Recommender.Items.Name, Recommender.Categories.Name "
			"FROM Recommender.SalesHistory "
			"INNER JOIN Recommender.Customers ON CustomerID = Recommender.Customers.ID "
			"INNER JOIN Recommender.Items ON ItemID = Recommender.Items.ID "
			"INNER JOIN Recommender.Categories ON Recommender.Items.Category_ID = Recommender.Categories.ID "
			"ORDER BY OrderID;",
			Poco::Data::Keywords::into(history.OrderId),
			Poco::Data::Keywords::into(history.CustomerID),
			Poco::Data::Keywords::into(history.Customer),
			Poco::Data::Keywords::into(history.ItemID),
			Poco::Data::Keywords::into(history.Item),
			Poco::Data::Keywords::into(history.Category),
			Poco::Data::Keywords::range(0, 1);
		while (!select.done()) {
			select.execute();
			_history.push_back(history);
		}
	}
	return _history;
}

std::vector<SalesHistory> const SqlDataProvider::getCustomerPurchaseHistory(const int customerID)
{
	std::vector<SalesHistory> purchases{};
	if (_connected) {
		Poco::Data::Statement select(*_ptrSession);
		std::string query{ "SELECT OrderID,CustomerID, Recommender.Customers.Name, ItemID, Recommender.Items.Name, Recommender.Categories.Name "
			"FROM Recommender.SalesHistory "
			"INNER JOIN Recommender.Customers ON CustomerID = Recommender.Customers.ID "
			"INNER JOIN Recommender.Items ON ItemID = Recommender.Items.ID "
			"INNER JOIN Recommender.Categories ON Recommender.Items.Category_ID = Recommender.Categories.ID "
			"WHERE CustomerID=" };
		query += std::to_string(customerID);
		query += " ORDER BY OrderID;";
		SalesHistory history{};
		select << query,
			Poco::Data::Keywords::into(history.OrderId),
			Poco::Data::Keywords::into(history.CustomerID),
			Poco::Data::Keywords::into(history.Customer),
			Poco::Data::Keywords::into(history.ItemID),
			Poco::Data::Keywords::into(history.Item),
			Poco::Data::Keywords::into(history.Category),
			Poco::Data::Keywords::range(0, 1);
		while (!select.done()) {
			select.execute();
			purchases.push_back(history);
		}
	}
	return purchases;
}
