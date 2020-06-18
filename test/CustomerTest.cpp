#include "gtest/gtest.h"

#include "../src/Customer.h"
#include "../src/Movie.h"
#include "../src/Rental.h"
#include "../src/PriceCode/PriceCode.h"
#include "../src/PriceCode/PriceCodeRegular.h"
#include "../src/PriceCode/PriceCodeNewRelease.h"
#include "../src/PriceCode/PriceCodeChildrens.h"

TEST(CustomerTest, simple) {

    const std::string EXPECTED_STATEMENT = "Rental Record for Olivier\n"
                                           "\tKarate Kid\t9.5\n"
                                           "\tAvengers: Endgame\t15\n"
                                           "\tSnow White\t1.5\n"
                                           "Amount owed is 26\n"
                                           "You earned 4 frequent renter points";

    Customer customer("Olivier");
    customer.addRental(Rental(new Movie("Karate Kid"), 7));
    customer.addRental(Rental(new Movie("Avengers: Endgame", std::make_shared<PriceCodeNewRelease>()), 5));
    customer.addRental(Rental(new Movie("Snow White", std::make_shared<PriceCodeChildrens>()), 3));

    ASSERT_EQ(customer.statement(), EXPECTED_STATEMENT);
}

