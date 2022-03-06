#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	for(auto const& u : usr) {
		ShoppingCart* cart = new ShoppingCart();
		this->__UserID__ProductsCart__.insert(make_pair(u->getUserID(), cart));
	}
	//throw("undefined");
}

list<Product *> &Server::getProductsList()
{
	return this->prod;
	//throw("undefined");
}

list<User *> &Server::getUsersList()
{
	return this->usr;
	//throw("undefined");
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return this->__UserID__ProductsCart__;
	//throw("undefined");
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{
	if(quantity <= 0)
		return false;

	Product* prod = nullptr;
	for(auto const& i : this->prod)
	{
		if(i->getId() == productID) {
			prod = i;
			break;
		}
	}

	if(prod == nullptr)
		return false;

	if(!prod->checkQuantity(quantity))
		return false;

	std::map<int,ShoppingCart*>::iterator it = this->__UserID__ProductsCart__.find(userID);
  	if (it != this->__UserID__ProductsCart__.end())
	{
		prod->decreaseQuantity(quantity);
		
		if(it->second->getShoppingCart().find(productID) == it->second->getShoppingCart().end())
			it->second->addProduct(productID, quantity);
		else
			it->second->raiseQuantity(productID, quantity);
		return true;
	}

	return false;
	
	//throw("undefined");
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	if(quantity <= 0)
		return false;

	std::map<int,ShoppingCart*>::iterator it = this->__UserID__ProductsCart__.find(userID);
  	if (it != this->__UserID__ProductsCart__.end())
	{
		if(it->second->getQuantity(productID) < quantity)
			return false;
		
		if(it->second->getQuantity(productID) == quantity)
			it->second->deleteProduct(productID);
		else
			it->second->lowerQuantity(productID, quantity);

		return true;
	}
	
	return false;
	
	//throw("undefined");
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}