#include "Product.h"
using namespace std;

Product::~Product() {}

bool Product::checkQuantity(int requestedQuantity)
{
	if(this->quantity < requestedQuantity)
		return false;
	return true;
	//throw("undefined");
}

Product::Product(const string &category, int id, const string &name, int quantity)
{
	this->category=category;
	this->id=id;
	this->name=name;
	this->quantity=quantity;

	//throw("undefined");
}

Product::Product(const Product &p)
{
	this->name=p.name;
	this->quantity=p.quantity;
	this->category=p.category;
	this->id=p.id;
	//throw("undefined");
}

Product::Product()
{
	this->name ="";
	this->quantity =0;
	this->category ="";
	this->id =0;
	//throw("undefined");
}

void Product::decreaseQuantity(int requestedQuantity)
{
	this->quantity -= requestedQuantity;
	//throw("undefined");
}

void Product::increaseQuantity(int requestedQuantity)
{
	this->quantity += requestedQuantity;
	//throw("undefined");
}

void Product::setCategory(const string &category)
{	
	this->category=category;
	//throw("undefined");
}

void Product::setId(int id)
{
	this->id=id;
	//throw("undefined");
}

void Product::setQuantity(int quantity)
{
	this->quantity=quantity;
	//throw("undefined");
}

void Product::setName(const string & name)
{
	this->name=name;
	//throw("undefined");
}

string &Product::getCategory()
{
	return this->category;
	//throw("undefined");
}

int Product::getQuantity()
{
	return this->quantity;
	//throw("undefined");
}

int Product::getId()
{
	return this->id;
	//throw("undefined");
}

string &Product::getName()
{
	return this->name;
	//throw("undefined");
}

const Product &Product::operator=(const Product &a)
{
	this->name=a.name;
	this->quantity=a.quantity;
	this->category=a.category;
	this->id=a.id;

	return *this;
	
	//throw("undefined");
}

json Product::toJSON()
{
	return json(*this);
}
