#pragma once
#include <string>

struct Customer {
	int Id{};
	std::string Name{};
	bool operator==(const int other)const {
		return Id == other;
	}
};

