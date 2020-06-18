// PriceCodeNewRelease.cpp
#include "PriceCodeNewRelease.h"

double PriceCodeNewRelease::getPrice(unsigned int daysRented) const {
    return daysRented * 3.;
}