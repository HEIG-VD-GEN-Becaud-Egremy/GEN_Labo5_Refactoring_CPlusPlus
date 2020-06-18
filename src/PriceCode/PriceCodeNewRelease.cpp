// PriceCodeNewRelease.cpp
#include "PriceCodeNewRelease.h"

double PriceCodeNewRelease::getPrice(unsigned int daysRented) const {
    return daysRented * 3.;
}

unsigned int PriceCodeNewRelease::getRenderPoints(unsigned int daysRented) const {
    return PriceCode::getRenderPoints(daysRented) + (unsigned int) (daysRented > 1);
}
