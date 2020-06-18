// PriceCodeChildrens.h
#ifndef GEN_LABO5_PRICECODECHILDRENS_H
#define GEN_LABO5_PRICECODECHILDRENS_H

#include "PriceCode.h"

class PriceCodeChildrens : public PriceCode {
public:
    double getPrice(unsigned int daysRented) const override;
};


#endif //GEN_LABO5_PRICECODECHILDRENS_H
