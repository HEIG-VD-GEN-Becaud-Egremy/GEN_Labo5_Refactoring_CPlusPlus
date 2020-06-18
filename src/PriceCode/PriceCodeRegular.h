// PriceCodeRegular.h
#ifndef GEN_LABO5_PRICECODEREGULAR_H
#define GEN_LABO5_PRICECODEREGULAR_H

#include "PriceCode.h"

class PriceCodeRegular : public PriceCode {
public:
    double getPrice(unsigned int daysRented) const override;
};


#endif //GEN_LABO5_PRICECODEREGULAR_H
