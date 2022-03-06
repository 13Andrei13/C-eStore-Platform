#include "BasicUser.h"

using namespace std;

BasicUser::BasicUser()
{
	this->costTransport = 0;
	//throw("undefined");
}

BasicUser::BasicUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int id, const string &nume, const string &prenume, const string &email, float costTransport) : User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
	this->costTransport = costTransport;
	//throw("undefined");
}

BasicUser::BasicUser(const BasicUser &unp) : User(unp)
{
	this->costTransport = unp.costTransport;
	//throw("undefined");
}

BasicUser &BasicUser::operator=(const BasicUser &unp)
{
	User::operator=(unp);
	this->costTransport = unp.costTransport;

	return *this;
	//throw("undefined");
}

void BasicUser::setTransportCost(int cost)
{
	this->costTransport = cost;

	//throw("undefined");
}

float BasicUser::getTransportCost()
{
	return this->costTransport;
	//throw("undefined");
}

void BasicUser::displayUser()
{
	throw("undefined");
}

string BasicUser::getUserType()
{
	return "BasicUser";
	//throw("undefined");
}

json BasicUser::toJSON()
{
	return json(*this);
}
