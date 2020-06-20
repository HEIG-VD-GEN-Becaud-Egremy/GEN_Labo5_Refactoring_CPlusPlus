// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <utility>
#include <vector>
#include "Rental.h"

class Customer {
public:

    typedef std::shared_ptr<Rental> Rental_ptr;

    Customer();
    explicit Customer(std::string name);

    void addRental(Rental_ptr& arg);
    std::string getName() const;
    std::string statement();

private:
    std::string _name;
    std::vector<Rental_ptr> _rentals;
};

#endif // CUSTOMER_H