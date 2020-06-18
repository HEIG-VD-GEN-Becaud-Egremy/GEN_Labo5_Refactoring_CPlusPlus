// PriceCodeNewRelease.h
#ifndef GEN_LABO5_PRICECODENEWRELEASE_H
#define GEN_LABO5_PRICECODENEWRELEASE_H

#include "PriceCode.h"

class PriceCodeNewRelease : public PriceCode {
public:
    double getPrice(unsigned int daysRented) const override;
    unsigned int getRenderPoints(unsigned int daysRented) const override;
};

#endif //GEN_LABO5_PRICECODENEWRELEASE_H
