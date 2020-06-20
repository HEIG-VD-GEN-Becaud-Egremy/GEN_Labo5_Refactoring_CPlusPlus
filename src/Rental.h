// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.h"

class Rental {
public:

    typedef std::shared_ptr<Movie> Movie_ptr;

    Rental(Movie_ptr movie, int daysRented);
    Rental();

    virtual double getPrice() const;
    virtual int getRenterPoints() const;
    virtual Movie_ptr getMovie() const;

private:
    Movie_ptr _movie;
    int _daysRented;
};

#endif // RENTAL_H