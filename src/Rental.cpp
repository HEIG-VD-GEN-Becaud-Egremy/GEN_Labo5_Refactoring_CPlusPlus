// Rental.cpp
#include "Rental.h"

Rental::Rental(Movie* movie, int daysRented):
    _movie(movie),
    _daysRented(daysRented) { }

double Rental::getPrice() const {
    return (*_movie).getPrice(_daysRented);
}

int Rental::getRenterPoints() const {
    return (int) (*_movie).getPriceCode()->getRenderPoints(_daysRented);
}

const Movie& Rental::getMovie() const {
    return *_movie;
}