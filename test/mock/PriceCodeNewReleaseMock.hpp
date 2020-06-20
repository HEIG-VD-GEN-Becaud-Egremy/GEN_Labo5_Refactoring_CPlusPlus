#ifndef PRICECODENEWRELEASEMOCK_HPP
#define PRICECODENEWRELEASEMOCK_HPP

#include <gmock/gmock.h>

#include "../../src/PriceCode/PriceCodeNewRelease.h"

class PriceCodeNewReleaseMock : public PriceCodeNewRelease {
public:
    MOCK_METHOD(double,       getPrice,        (unsigned int), (const));
    MOCK_METHOD(unsigned int, getRenterPoints, (unsigned int), (const));
};

#endif //PRICECODENEWRELEASEMOCK_HPP