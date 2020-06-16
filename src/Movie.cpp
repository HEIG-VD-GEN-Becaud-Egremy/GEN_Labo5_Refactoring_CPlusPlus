#include "Movie.h"
#include <utility>


Movie::Movie(std::string  title, int priceCode) :
        _title(std::move( title )),
        _priceCode( priceCode ) { }

double Movie::getPrice(unsigned int daysRented) const {

    double price = 0.;

    switch (_priceCode) {
        case REGULAR:
            price += 2;
            if (daysRented > 2) {
                price += (daysRented - 2) * 1.5 ;
            }
            break;

        case NEW_RELEASE:
            price += daysRented * 3;
            break;

        case CHILDRENS:
            price += 1.5;
            if (daysRented > 3) {
                price += (daysRented - 3) * 1.5;
            }
            break;
    }

    return price;
}
int Movie::getPriceCode() const {
    return _priceCode;
}

void Movie::setPriceCode(int arg) {
    _priceCode = arg;
}

std::string Movie::getTitle() const {
    return _title;
}