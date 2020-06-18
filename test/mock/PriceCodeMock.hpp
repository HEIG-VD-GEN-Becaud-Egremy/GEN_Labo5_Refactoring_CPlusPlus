#ifndef PRICECODEMOCK_HPP
#define PRICECODEMOCK_HPP

#include <gmock/gmock.h>
#include "../../src/PriceCode/PriceCode.h"

class PriceCodeMock : public PriceCode {
public:
    MOCK_METHOD(double,       getPrice,        (unsigned int), (const));
    MOCK_METHOD(unsigned int, getRenderPoints, (unsigned int), (const));
};

#endif //PRICECODEMOCK_HPP