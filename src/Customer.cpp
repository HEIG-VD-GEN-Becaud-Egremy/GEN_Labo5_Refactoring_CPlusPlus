// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Movie.h"
#include "Rental.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement() {

    ostringstream result;
    double        thisAmount;
    double        totalAmount          = 0;
    int           frequentRenterPoints = 0;

    result << "Rental Record for " << getName() << "\n";

    for (const Rental_ptr& rental : _rentals) {

        // get rental price and increment render points
        thisAmount = rental->getPrice();
        frequentRenterPoints += rental->getRenterPoints();

        // show figures for this rental
        result << "\t" << rental->getMovie()->getTitle()
               << "\t" << thisAmount << "\n";

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

void Customer::addRental(Rental_ptr& arg) {
    _rentals.push_back( arg );
}

string Customer::getName() const {
    return _name;
}