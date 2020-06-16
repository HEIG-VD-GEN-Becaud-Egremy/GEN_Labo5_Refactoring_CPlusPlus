// Rental.cpp
#include "Rental.h"

Rental::Rental(Movie movie, int daysRented):
    _movie(std::move(movie)),
    _daysRented(daysRented) { }

double Rental::getPrice() const {
    return _movie.getPrice(_daysRented);
}

int Rental::getRenterPoints() const {
    return 1 + (_movie.getPriceCode() == NEW_RELEASE &&
                _daysRented > 1 ?
                1 : 0);
}

const Movie& Rental::getMovie() const {
    return _movie;
}