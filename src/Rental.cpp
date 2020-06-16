// Rental.cpp
#include "Rental.h"

Rental::Rental(const Movie& movie, int daysRented):
    _movie(movie),
    _daysRented(daysRented) { }

double Rental::getPrice() const {
    return _movie.getPrice(_daysRented);
}

int Rental::getDaysRented() const {
    return _daysRented;
}

const Movie& Rental::getMovie() const {
    return _movie;
}