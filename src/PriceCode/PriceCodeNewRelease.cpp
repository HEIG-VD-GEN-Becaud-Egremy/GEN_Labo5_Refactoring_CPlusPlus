// PriceCodeNewRelease.cpp
#include "PriceCodeNewRelease.h"

double PriceCodeNewRelease::getPrice(unsigned int daysRented) const {
    return daysRented * 3.;
}

unsigned int PriceCodeNewRelease::getRenterPoints(unsigned int daysRented) const {
    return PriceCode::getRenterPoints(daysRented) + (unsigned int) (daysRented > 1);
}
