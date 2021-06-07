#pragma once
#include <string>

struct SalesHistory {
	int OrderId{};
	int CustomerID{};
	std::string Customer{};
	int ItemID{};
	std::string Item{};
	std::string Category{};
};
