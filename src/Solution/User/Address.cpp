#include "Address.h"

using namespace std;

Address::Address()
{	
	this->county="";
	this->locality="";
	this->street="";
	this->number =0;
	this->block ="";
	this->apartment =0;
	//throw("undefined");
}

Address::Address(const Address &address)
{	
	this->county=address.county;
	this->locality=address.locality;
	this->street=address.street;
	this->number=address.number;
	this->block=address.block;
	this->apartment=address.apartment;
	//throw("undefined");
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap)
{	
	this->county=jud;
	this->locality=loc;
	this->street=str;
	this->number=nr;
	this->block=bl;
	this->apartment=ap;
	//throw("undefined");
}

const Address &Address::operator=(const Address &adr)
{
	this->county=adr.county;
	this->locality=adr.locality;
	this->street=adr.street;
	this->number=adr.number;
	this->block=adr.block;
	this->apartment=adr.apartment;

	return *this;
	//throw("undefined");
}

void Address::setStrada(const string &str)
{
	this->street=str;
	//throw("undefined");
}

void Address::setNumber(int nr)
{
	this->number=nr;
	//throw("undefined");
}

void Address::setBlock(const string &bl)
{
	this->block = bl;
	//throw("undefined");
}

void Address::setApartment(int ap)
{
	this->apartment=ap;
	
	//throw("undefined");
}

void Address::setCounty(const string &jud)
{
	this->county=jud;
	
	//throw("undefined");
}

void Address::setLocality(const string &loc)
{
	this->locality=loc;
	//throw("undefined");
}

string &Address::getStreet()
{
	return this->street;
	//throw("undefined");
}

int Address::getNumber()
{
	return this->number;
	//throw("undefined");
}
string &Address::getBlock()
{
	return this->block;
	//throw("undefined");
}

int Address::getApartment()
{
	return this->apartment;
	//throw("undefined");
}

string &Address::getCounty()
{
	return this->county;
	//throw("undefined");
}

string &Address::getLocality()
{
	return this->locality;
	//throw("undefined");
}

bool Address::operator==(const Address &address)
{
	if(this->county != address.county)
		return false;
	if(this->locality != address.locality)
		return false;
	if(this->street != address.street)
		return false;
	if(this->number != address.number)
		return false;
	if(this->block != address.block)
		return false;
	if(this->apartment != address.apartment)
		return false;
	
	return true;
	//throw("undefined");
}

bool Address::operator!=(const Address &address)
{
	/*if(this->county == address.county)
		return false;
	if(this->locality == address.locality)
		return false;
	if(this->street == address.street)
		return false;
	if(this->number == address.number)
		return false;
	if(this->block == address.block)
		return false;
	if(this->apartment == address.apartment)
		return false;
	*/

	if(this->county != address.county || this->locality != address.locality ||
		this->street != address.street || this->number != address.number ||
		this->block != address.block || this->apartment != address.apartment)
			return true;
	
	return false;
	//throw("undefined");
}

ostream &operator<<(ostream &os, const Address &a)
{	
	os << "Adresa" << endl;
	os << "County : " << a.county << endl;
	os << "Locality : " << a.locality << endl;
	os << "Street : " << a.street << endl;
	os << "Number : " << a.number << endl;
	os << "Block : " << a.block << endl;
	os << "Apartment : " << a.apartment << endl;
	os << endl;

	return os;

	
	//throw("undefined");
}

json Address::toJSON()
{
	return json(*this);
}