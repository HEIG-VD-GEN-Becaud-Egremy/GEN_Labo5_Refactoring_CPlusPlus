#ifndef RENTALMOCK_HPP
#define RENTALMOCK_HPP

#include <gmock/gmock.h>
#include "../../src/Rental.h"

class RentalMock : public Rental {
public:
    MOCK_METHOD(double,            getPrice,        (), (const));
    MOCK_METHOD(int,               getRenterPoints, (), (const));
    MOCK_METHOD(Rental::Movie_ptr, getMovie,        (), (const));
};


#endif //RENTALMOCK_HPP