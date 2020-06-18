// PriceCodeChildrens.cpp
#include "PriceCodeChildrens.h"

double PriceCodeChildrens::getPrice(unsigned int daysRented) const {
    return 1.5 + (daysRented > 3 ? (daysRented - 3.) * 1.5 : 0);
}