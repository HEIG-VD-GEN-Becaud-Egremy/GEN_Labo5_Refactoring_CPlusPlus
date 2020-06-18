// PriceCode.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <memory>
#include "PriceCode/PriceCode.h"
#include "PriceCode/PriceCodeRegular.h"

class Movie {
public:

    typedef std::shared_ptr<PriceCode> PriceCode_ptr;

    explicit Movie(std::string title,
          PriceCode_ptr priceCode = std::make_shared<PriceCodeRegular>());
    Movie();

    virtual std::string getTitle() const;
    virtual Movie::PriceCode_ptr getPriceCode() const;
    virtual void setPriceCode(Movie::PriceCode_ptr priceCode);
    virtual double getPrice(unsigned int daysRented) const;

private:
    std::string   _title;
    PriceCode_ptr _priceCode;
};

#endif // MOVIE_H