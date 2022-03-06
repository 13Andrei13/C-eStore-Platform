#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct()
{	
	this->producer ="";
	this->yearsOfWarranty=0;
	this->price =0;
	//throw("undefined");
}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)
{
	this->producer=producer;
	this->yearsOfWarranty=yearsOfWarranty;
	this->price=price;
	//throw("undefined");
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
	this->producer=pn.producer;
	this->yearsOfWarranty=pn.yearsOfWarranty;
	this->price=pn.price;
	//throw("undefined");
}

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	this->yearsOfWarranty=garantieAni;
	//throw("undefined");
}

void NonFoodProduct::setPrice(float price)
{	
	this->price=price;
	//throw("undefined");
}

void NonFoodProduct::setProducer(const string &producer)
{
	this->producer=producer;
	//throw("undefined");
}

int NonFoodProduct::getYearsOfWarranty()
{
	return this->yearsOfWarranty;
	//throw("undefined");
}

float NonFoodProduct::getPrice()
{
	return this->price;
	//throw("undefined");
}

string &NonFoodProduct::getProducer()
{
	return this->producer;
	//throw("undefined");
}

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{
	if(this->producer != obj.producer)
		return false;
	if(this->yearsOfWarranty != obj.yearsOfWarranty)
		return false;
	if(this->price != obj.price)
		return false;
				
	return true;

	//throw("undefined");
}

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{	
	Product::operator=(a);
	this->producer=a.producer;
	this->yearsOfWarranty=a.yearsOfWarranty;
	this->price=a.price;

	return *this;
	//throw("undefined");
}

string NonFoodProduct::getProductType()
{	
	return "NonFoodProduct";
	//throw("undefined");
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}
