#include "utility.h"

bool Utility::FoodProductCompareNTP(Product* first, Product* second)
{
    if(dynamic_cast<FoodProduct*>(first)->getName() < dynamic_cast<FoodProduct*>(second)->getName())
        return true;
   else
   {
       if(dynamic_cast<FoodProduct*>(first)->getName() == dynamic_cast<FoodProduct*>(second)->getName())
       {
           if(dynamic_cast<FoodProduct*>(first)->getCountryOfOrigin() < dynamic_cast<FoodProduct*>(second)->getCountryOfOrigin())
           return true;
           else
           {
               if(dynamic_cast<FoodProduct*>(first)->getCountryOfOrigin() == dynamic_cast<FoodProduct*>(second)->getCountryOfOrigin())
               {
                   if(dynamic_cast<FoodProduct*>(first)->getLeiPerKg() < dynamic_cast<FoodProduct*>(second)->getLeiPerKg())
                   return true;
                   else 
                   return false;
               }
           }
           
       }
   }
   
    
    
        return false;
}

bool Utility::ResealedProductComparePrice(Product* first , Product* second)
{
    if(dynamic_cast<ResealedProduct*>(first)->getPrice()
    <= dynamic_cast<ResealedProduct*>(second)->getPrice())
    {
        return true;

    }else
    {
        return false;
    }
    
}
bool Utility::UserCompareID(User * first , User* second)
{
    if( first->getUserID() < second->getUserID())
        return true;
    
    return false;

}