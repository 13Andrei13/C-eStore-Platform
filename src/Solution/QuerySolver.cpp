#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver() 
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr) 
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
  
  list<Product*> EspressorDiscounted;

  for(auto const& i : server ->getProductsList())
  {
    if(  i->getCategory() == "espressor" )
      if ( i->getProductType() == "DiscountedProduct") 
    
         EspressorDiscounted.push_back(i);
    
  }
  return EspressorDiscounted;
  //throw("undefined");
}

list<User*> QuerySolver::Query_3b(){
  
  list<User*> NonPremiumUser;
  
  for(auto const& i : server->getUsersList())
  {
    if( i->getUserType() == "BasicUser")
      
      if( i->getTransportCost() <= 11.5)
       
        NonPremiumUser.push_back(i);
  }
  return NonPremiumUser;
  //throw("undefined");
}

list<Product*> QuerySolver::Query_3c(){
  
  list<Product*>Returned_lipsa_accesorii;
  for(auto const& i : server->getProductsList() )
  {
    if( i->getProductType() ==  "ResealedProduct")
      if(dynamic_cast<ResealedProduct*>(i)->getReason() == "lipsa_accesorii")
        Returned_lipsa_accesorii.push_back(i);
 
  } 
  Returned_lipsa_accesorii.sort( Utility::ResealedProductComparePrice ) ;
  
  return Returned_lipsa_accesorii;
  //throw("undefined");
}

list<Product*> QuerySolver::Query_3d(){
  
  list<Product*>Produse_Alimentare;
  for(auto const& i :server->getProductsList() )
  {
    if(i->getProductType() == "FoodProduct")
      Produse_Alimentare.push_back(i);

  }

  Produse_Alimentare.sort(Utility::FoodProductCompareNTP);
  return Produse_Alimentare;
  //throw("undefined");
}

list<User*> QuerySolver::Query_3e(){
  list<User*> utilizatori_speciali;
  
  map<string, int> orase;
  for(auto const& i :server->getUsersList() )
  { 
      if(i->getBillingData().getCounty() != i->getDeliveryData().getCounty())
        continue;
      
      map<string, int>::iterator it = orase.find(i->getBillingData().getCounty());
      if(it == orase.end())
        orase.insert(make_pair(i->getBillingData().getCounty(), 1));
      else
        it->second++;
  }

  using pair_type = decltype(orase)::value_type;
  auto pr = max_element
  (
    begin(orase), std::end(orase),
    [] (const pair_type & p1, const pair_type & p2) {
        return p1.second < p2.second;
    }
  );

  for(auto const& i :server->getUsersList())
  {
    if(i->getBillingData().getCounty() != i->getDeliveryData().getCounty())
        continue;

    if(i->getBillingData().getCounty() != pr->first)
        continue;

    if(i->getDeliveryData().getBlock() != "-" &&
      i->getBillingData().getBlock() != "-")
        continue;

    if(i->getBillingData().getApartment() != 0 &&
      i->getDeliveryData().getApartment() != 0)
        continue;

    utilizatori_speciali.push_back(i);
  }

  utilizatori_speciali.sort([](User* first, User* second) {
    return first->getUserID() < second->getUserID();
  });

  return utilizatori_speciali;
  //throw("undefined");
}

list<User*> QuerySolver::Query_3f()
{
  list<User*> premium_speciali;
  map<int, string> filter;

  for(auto const& i : server->getProductsList())
  {
    if(i->getCategory() != "telefon" && i->getCategory() != "imprimanta")
      continue;
    
    filter.insert(make_pair(i->getId(), i->getCategory()));
  }

  for(auto const& i : server->getUsersList())
  {
    if(i->getUserType() != "Premium user")
      continue;

    auto _map =dynamic_cast<PremiumUser*>(i)->getDiscounts();
    
    for(auto const& j : _map)
    {
      auto it = filter.find(j.first);
      if(it == filter.end())
        continue;
      
      premium_speciali.push_back(i);
      break;
    }
  }

  return premium_speciali;
  //throw("undefined");
}
