#include "DiscountedProduct.h"
using namespace std;

DiscountedProduct::DiscountedProduct() : NonFoodProduct()
{	
	this->discountPercentage =0;
	//throw("undefined");
}

DiscountedProduct::DiscountedProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int discountPercentage, int quantity)
	: NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity)
{
	this->discountPercentage=discountPercentage;
	//throw("undefined");
}

DiscountedProduct::DiscountedProduct(const DiscountedProduct &discountedProduct) : NonFoodProduct(discountedProduct)
{
	this->discountPercentage= discountedProduct.discountPercentage;
	//throw("undefined");
}

float DiscountedProduct::priceAfterDiscount() const
{
	return this->price * (100 - this->discountPercentage);
	//throw("undefined");
}

float DiscountedProduct::getDiscountPercentage()
{
	return this->discountPercentage;
	//throw("undefined");
}

const DiscountedProduct &DiscountedProduct::operator=(const DiscountedProduct &a)
{
	NonFoodProduct::operator=(a);
	this->discountPercentage = a.discountPercentage;
	return *this;
	//throw("undefined");
}

void DiscountedProduct::setDiscountPercentage(int discountPercentage)
{
	this->discountPercentage=discountPercentage;
	//throw("undefined");
}

string DiscountedProduct::getProductType()
{
	return "DiscountedProduct";
	//throw("undefined");
}

json DiscountedProduct::toJSON()
{
	return json(*this);
}

void DiscountedProduct::display()
{
	cout << "Product Redus" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent reducere : " << this->discountPercentage << endl
		 << endl;
}