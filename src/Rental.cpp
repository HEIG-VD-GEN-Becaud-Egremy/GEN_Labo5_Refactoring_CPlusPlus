// Rental.cpp
#include "Rental.h"

Rental::Rental(Movie_ptr movie, int daysRented):
    _movie(movie),
    _daysRented(daysRented) { }

Rental::Rental() = default;

double Rental::getPrice() const {
    return (*_movie).getPrice(_daysRented);
}

int Rental::getRenterPoints() const {
    return (int) (*_movie).getPriceCode()->getRenterPoints(_daysRented);
}

Rental::Movie_ptr Rental::getMovie() const {
    return _movie;
}
