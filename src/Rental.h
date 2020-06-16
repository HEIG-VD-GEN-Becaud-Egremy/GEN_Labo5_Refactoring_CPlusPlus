// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    double getPrice() const;
    int getRenterPoints() const;
    int getDaysRented() const;
    const Movie& getMovie() const;

private:
    Movie _movie;
    int _daysRented;
};

#endif // RENTAL_H