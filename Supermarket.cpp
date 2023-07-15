#include "Supermarket.h"


bool Ecommerce::register_user() {
	std::string name, password;
	int balance;
	std::cout << "Enter name" << std::endl;
	std::cin >> name;
	std::cout << "Enter password" << std::endl;
	std::cin >> password;
	std::cout << "Enter your card info" << std::endl;
	std::cin >> balance;

	Client client(name, password, balance);
	this->client = &client;
	this->clients.push_back(client);
	return true;
}

bool Ecommerce::login_user() {
	std::string name, password;
	int balance;
	std::cout << "Enter name" << std::endl;
	std::cin >> name;
	std::cout << "Enter password" << std::endl;
	std::cin >> password;

	for (auto client : this->clients) {
		if (name == client.name) {
			if (password == client.password)
			{
				std::cout << "You successfully logged in" << std::endl;
				this->client = &client;
				this->user_interface();
			}
			else
			{
				std::cout << "Sorry, password is invalid" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "User with this username not found" << std::endl;
			return false;
		}
	}
}

void Ecommerce::change_stock(int id, int quantity) {
	products.erase(products.begin() + id);
}


void Ecommerce::offer_products(){
	int choice, quantity;

	std::cout << "Choose product" << std::endl;

	for (int i = 0; i < products.size(); i++) {
		std::cout << products[i].name << " - " << i + 1 << "/";
	}
	std::cin >> choice;

	std::cout << "Choose quantity" << std::endl;
	std::cin >> quantity;

	if (make_order(choice, quantity)) {
		std::cout << "The order was successfully placed" << std::endl;
	}
	else
	{
		std::cout << "Something went wrong" << std::endl;
	}

}

bool Ecommerce::make_order(int id, int quantity) {

	

	auto* product = &products[id];

	if (product) {

		if (product->quantity >= quantity) {

			if (client->balance > product->price) {
				change_stock(id, -quantity);
				return true;
			}
			else
			{
				std::cout << "Your balance is insufficient" << std::endl;
				std::cout << "Debit your balance" << std::endl;
			}
		}
		else
		{
			std::cout << "The product is not available in stock or" << std::endl;
			std::cout << "We can provide it in smaller quantities" << std::endl;
		}
	}
	else
	{
		std::cout << "The product doesn't exist" << std::endl;
	}

	return false;
}



void Ecommerce::user_interface() {
	if (client) {

	}
	else {
		int choice;
		bool _continue  = true; // c

		while(_continue)
			std::cout << "Register - 1/ Login - 3/ Quit - 5";
			std::cin >> choice;

			if (choice == 1) {
				this->register_user();
			}
			else if(choice == 3)
			{
				this->login_user();
			}
			else if(choice == 3)
			{
				_continue = false;
			} 
	}
}

