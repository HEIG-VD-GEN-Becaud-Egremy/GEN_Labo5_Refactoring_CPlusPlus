// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "PriceCode.h"

class Movie {
public:
    Movie(std::string  title, int priceCode = REGULAR);

    double getPrice(unsigned int daysRented) const;
    int getPriceCode() const;
    std::string getTitle() const;

private:
    std::string _title;
    int _priceCode;
};

#endif // MOVIE_H