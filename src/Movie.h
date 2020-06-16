// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "PriceCode.h"

class Movie {
public:
    explicit Movie(std::string title, int priceCode = REGULAR);
    Movie();

    virtual std::string getTitle() const;
    virtual int getPriceCode() const;
    virtual double getPrice(unsigned int daysRented) const;

private:
    std::string _title;
    int _priceCode;
};

#endif // MOVIE_H