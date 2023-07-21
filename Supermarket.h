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
	std::vector<Order> orders;
	int balance;
};

struct Product {
	std::string name;
	int price;
	int quantity;
};


class Order {
public:
	Order(Product product, int quantity): 
		product(product), quantity(quantity) {
		get_total();
	}

	bool get_total() {
		this->total = product.price * quantity;
	}
private:
	Product product;
	int quantity;
	int total;
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
	bool isStaff();
	bool isAdmin();

public:				// Main functionality
	void user_interface();
	void offer_products();
	bool make_order(int id, int quantity); // check whether order is placed successfully or not
	bool cancel_order();

private:
	void change_stock(int id, int n);
private:
	Client* client = nullptr;
	std::vector<Client> clients;
	std::vector<Product> products;
};

