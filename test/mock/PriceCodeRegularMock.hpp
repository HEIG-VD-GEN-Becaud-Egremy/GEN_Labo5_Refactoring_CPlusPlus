#ifndef PRICECODEREGULARMOCK_HPP
#define PRICECODEREGULARMOCK_HPP

#include <gmock/gmock.h>
#include "../../src/PriceCode/PriceCodeRegular.h"

class PriceCodeRegularMock : public PriceCodeRegular {
public:
    MOCK_METHOD(double,       getPrice,        (unsigned int), (const));
    MOCK_METHOD(unsigned int, getRenderPoints, (unsigned int), (const));
};

#endif //PRICECODEREGULARMOCK_HPP