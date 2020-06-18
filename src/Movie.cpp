//  PriceCode.cpp
#include "Movie.h"

#include <utility>

Movie::Movie(std::string title, Movie::PriceCode_ptr priceCode) :
    _title(std::move(title)), _priceCode(std::move(priceCode)) { }

Movie::Movie() = default;

std::string Movie::getTitle() const {
    return _title;
}

Movie::PriceCode_ptr Movie::getPriceCode() const {
    return _priceCode;
}

void Movie::setPriceCode(Movie::PriceCode_ptr priceCode) {
    _priceCode = std::move(priceCode);
}

double Movie::getPrice(unsigned int daysRented) const {
    return _priceCode->getPrice(daysRented);
}
