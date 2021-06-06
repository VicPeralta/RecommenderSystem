
#include "pch.h"
#include <iostream>
#include "Recommender.h"
#include "ConsoleShowData.h"
int main() {
	int option{};
	int customer{};
	Recommender recommender{};
	ConsoleShowData showData{};
	for (;;) {
		std::cout << "Enter your customer ID\n";
		std::cin >> customer;
		if (recommender.login(customer)) {

			do {
				std::cout << "\n1.- View all available items\n";
				std::cout << "2.- View purchase history\n";
				std::cout << "3.- View recommended items\n";
				std::cout << "4.- Login again\n";
				std::cout << "5.- Exit\n";
				std::cin >> option;
				switch (option)
				{
				case 1:
					showData.ShowItems(recommender.getItems());
					break;
				case 2:
					showData.ShowPurchaseHistoryCustomer(recommender.getPurchasesHistory(customer));
					break;
				case 3:
					showData.ShowRecommendedItems(recommender.getRecommendations(customer));
					break;
				case 4:
					break;
				case 5:
					return 0;
				default:
					break;
				}
			} while (option != 4);
		}
		else {
			std::cout << "Invalid ID\n";
			std::cout << "Try again...\n";
		}
	}
	return 0;
}

