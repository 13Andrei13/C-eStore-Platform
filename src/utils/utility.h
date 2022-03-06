#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/Product/ResealedProduct.h"
#include "../Solution/User/User.h"



class Utility{

public:

static bool ResealedProductComparePrice(Product* first , Product* second);
static bool FoodProductCompareNTP(Product* first, Product* second);
static bool UserCompareID(User * first , User* second);
};