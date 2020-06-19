#ifndef LABO5_MOVIEMOCK_HPP
#define LABO5_MOVIEMOCK_HPP

#include <gmock/gmock.h>
#include "../../src/Movie.h"

class MovieMock : public Movie {
public:
    MOCK_METHOD(std::string,          getTitle,     (),            (const));
    MOCK_METHOD(double,               getPrice,     (unsigned int),(const));
    MOCK_METHOD(Movie::PriceCode_ptr, getPriceCode, (),            (const));
};


#endif //LABO5_MOVIEMOCK_HPP