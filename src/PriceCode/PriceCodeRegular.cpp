// PriceCodeRegular.cpp
#include "PriceCodeRegular.h"

double PriceCodeRegular::getPrice(unsigned int daysRented) const {
    return 2. + (daysRented > 2 ? (daysRented - 2.) * 1.5 : 0.);
}