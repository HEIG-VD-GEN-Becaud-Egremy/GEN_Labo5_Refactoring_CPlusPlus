// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.h"

class Rental {
public:
    Rental(Movie* movie, int daysRented);

    double getPrice() const;
    int getRenterPoints() const;
    const Movie& getMovie() const;

private:
    Movie* _movie;
    int _daysRented;
};

#endif // RENTAL_H