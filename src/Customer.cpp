// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Movie.h"
#include "Rental.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    vector< Rental >::iterator iter = _rentals.begin();
    vector< Rental >::iterator iter_end = _rentals.end();
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        double thisAmount = 0;
        Rental each = *iter;

        thisAmount += each.getPrice();

        // add frequent renter points
        frequentRenterPoints += each.getRenterPoints();

        // show figures for this rental
        result << "\t" << each.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

Customer::Customer() = default;

Customer::Customer(string name) : _name(move(name)) { }

void Customer::addRental(const Rental& arg) {
    _rentals.push_back( arg );
}

string Customer::getName() const {
    return _name;
}