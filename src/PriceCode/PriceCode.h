#ifndef GEN_LABO5_PRICECODE_H
#define GEN_LABO5_PRICECODE_H

class PriceCode {
public:
    virtual double getPrice(unsigned int daysRented) const = 0;
};

#endif //GEN_LABO5_PRICECODE_H
