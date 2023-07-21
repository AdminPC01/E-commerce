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

bool Ecommerce::change_account() {
	
	std::cout << "Change username - 1 / Change - password 2" << std::endl;
	int choice;

	if (choice == 1) {
		std::string name;
		std::cout <<  "Enter your new username" << std::endl;
		std::cin >> name;

		for (int i = 0; i < clients.size(); i++) {
			if (client->name == clients[i].name &&
				client->password == clients[i].password) {
				clients[i].name = name;
				std::cout << "Username was succesfully changed" << std::endl;
			}
		}
	}
	else if(choice == 2)
	{
		std::string password;
		std::cout << "Enter your new password" << std::endl;
		std::cin >> password;

		for (int i = 0; i < clients.size(); i++) {
			if (client->name == clients[i].name &&
				client->password == clients[i].password) {
				clients[i].password = password;
				std::cout << "Password was succesfully changed" << std::endl;
			}
		}
	}
	else
	{

	}
}

void Ecommerce::change_stock(int id, int quantity) {
	products.erase(products.begin() + id);
}

bool Ecommerce::isStaff() {
	if (client->name == "Adam" && client->password == "1345") {
		return true;
	}
	else {
		return false;
	}
}

void Ecommerce::add_products() {
	


		Product product;
		std::cout << "Enter product name" << std::endl;
		std::cin >> product.name;
		std::cout << "Enter product price" << std::endl;
		std::cin >> product.price;
		std::cout << "Enter product quantity" << std::endl;
		std::cin >> product.quantity;
	
}

void Ecommerce::delete_product() {

	std::string product_name;
	std::cout << "Which product do you want to delete ?" << std::endl;

	/*for (std::vector<Product>::iterator it = products.begin(); 
		it != products.end(); it++) {
		std::cout << it->name << " /";
	}*/

	for (auto product : products) {
		std::cout << " /" << product.name;
	}

	std::cin >> product_name;

	for (auto product : products) {
		
		if (product.name == product_name) {
			products.erase(std::remove(products.begin(), products.end(), product), products.end());
		}
	}
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

		if (products.size() > id) {
		auto* product = &products[id];

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
	if (this->client) {
		offer_products();
		if (this->isStaff()) {
			add_products();	}
	}
	else {
		int choice;
		bool _continue  = true; // 

		while (_continue) {
			if (!client) {
				std::cout << "Register - 1/ Login - 3/ Quit - 5";
				std::cin >> choice;

				if (choice == 1) {
					this->register_user();
				}
				else if (choice == 3)
				{
					this->login_user();
				}
				else if (choice == 5)
				{
					_continue = false;
				}
			}
			else
			{
				std::cout << "1 - Make an order/ Change account/ Quit";
				std::cin >> choice;

				if (choice == 1) {
					this->register_user();
				}
				else if (choice == 3)
				{
					this->login_user();
				}
				else if (choice == 5)
				{
					_continue = false;
				}
			}
		}
	}
}

