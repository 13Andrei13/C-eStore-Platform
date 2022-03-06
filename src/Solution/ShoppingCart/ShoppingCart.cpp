#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	if(payMethod.empty())
		throw("invalid param");
	
	this->payMethod = payMethod;
}

string &ShoppingCart::getPayMethod()
{
	return this->payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	if(payMethod.empty())
		throw("invalid param");
	
	this->payMethod = payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	/*std::map<int,int>::iterator it = shoppingCart.find(id);
  	if (it != shoppingCart.end())
		it->second += quantity;
	else*/
		this->shoppingCart.insert(make_pair(id, quantity));
	//throw("undefined");
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	if(quantity < 0)
		throw("invalid argument");

	std::map<int,int>::iterator it = shoppingCart.find(id);
  	if (it != shoppingCart.end())
		it->second += quantity;
	//throw("undefined");
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	if(quantity < 0)
		throw("invalid argument");
		
	std::map<int,int>::iterator it = shoppingCart.find(id);
  	if (it != shoppingCart.end())
		it->second -= quantity;

	//throw("undefined");
}

int ShoppingCart::getQuantity(int productID)
{
	std::map<int,int>::iterator it = shoppingCart.find(productID);
  	if (it != shoppingCart.end())
		return it->second;
	
	return -1;
	//throw("undefined");
}

void ShoppingCart::deleteProduct(int productID)
{
	this->shoppingCart.erase(productID);
	//throw("undefined");
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	return this->shoppingCart;
	//throw("undefined");
}

void ShoppingCart::displayShoppingCart()
{
	throw("undefined");
}

json ShoppingCart::toJSON()
{
  return json(*this);
}