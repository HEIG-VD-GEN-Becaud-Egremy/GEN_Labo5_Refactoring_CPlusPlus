#ifndef PRICECODECHILDRENSMOCK_HPP
#define PRICECODECHILDRENSMOCK_HPP

#include <gmock/gmock.h>

#include "../../src/PriceCode/PriceCodeChildrens.h"

class PriceCodeChildrensMock : public PriceCodeChildrens {
public:
    MOCK_METHOD(double,       getPrice,        (unsigned int), (const));
    MOCK_METHOD(unsigned int, getRenterPoints, (unsigned int), (const));
};

#endif //PRICECODECHILDRENSMOCK_HPP