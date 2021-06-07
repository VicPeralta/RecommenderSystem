
#include "pch.h"

int main() {
	int option{};
	int customerID{};
	Recommender recommender{};
	ConsoleShowData showData{};
	for (;;) {
		ConsoleColor::clearScreen(std::cout);
		std::cout << "Welcome to THE Recommender app\n";
		std::cout << "<<< Enter your customer ID >>>\n";
		std::cin >> customerID;
		Customer customer{};
		if (std::cin.good() && recommender.login(customerID, customer)) {
			do {
				ConsoleColor::clearScreen(std::cout);
				std::cout << ConsoleColor::foregroundGreen << "<<< Recommender System >>>\n" << ConsoleColor::foregroundDefault;
				std::cout << "Welcome " << customer.Name << "\n";
				std::cout << "1.- View all available items\n";
				std::cout << "2.- View purchase history\n";
				std::cout << "3.- View recommended items\n";
				std::cout << "4.- Login again\n";
				std::cout << "5.- Exit\n";
				std::cin >> option;
				if (!std::cin.good()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				switch (option)
				{
				case 1:
					showData.ShowItems(recommender.getItems());
					pressEnterKey();
					break;
				case 2:
					showData.ShowPurchaseHistoryCustomer(recommender.getPurchasesHistory(customerID));
					pressEnterKey();
					break;
				case 3:
					showData.ShowRecommendedItems(recommender.getRecommendations(customerID));
					pressEnterKey();
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
			std::cin.clear();
			std::cout << "Invalid ID\n";
			std::cout << "Try again...\n";
			pressEnterKey();
		}
	}
	return 0;
}

