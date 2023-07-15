#pragma once
#include <iostream>
#include <vector>


class Client
{
public:

	friend class Ecommerce;
	Client(std::string name, std::string password, int balance):
		name(name), password(password), balance(balance){}

private:
	std::string name;
	std::string password;
	int balance;
};

struct Product {
	std::string name;
	int price;
	int quantity;
};

class Ecommerce
{	
public:					// Account functionality
	bool register_user(); 
	bool login_user();
	bool change_account();
public:				// Administrative functionality
	void add_products();
	void delete_product();

public:				// Main functionality
	void user_interface();
	void offer_products();
	bool make_order(int id, int quantity); // check whether order is placed successfully or not

private:
	void change_stock(int id, int n);
private:
	Client* client = nullptr;
	std::vector<Client> clients;
	std::vector<Product> products;
};

