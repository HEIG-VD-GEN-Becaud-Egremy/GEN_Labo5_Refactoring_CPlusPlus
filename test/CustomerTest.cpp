#include "gtest/gtest.h"
#include <memory>

#include "../src/Customer.h"
#include "mock/MovieMock.hpp"
#include "mock/RentalMock.hpp"
#include "mock/PriceCodeRegularMock.hpp"
#include "mock/PriceCodeNewReleaseMock.hpp"
#include "mock/PriceCodeChildrensMock.hpp"

using ::testing::Return;

TEST(CustomerTestGetName, unit) {
    const std::string name = "Nicholas Hoult";
    Customer customer(name);
    ASSERT_EQ(customer.getName(), name);
}


TEST(CustomerTestStatement, unit) {
    const std::string EXPECTED_STATEMENT = "Rental Record for Olivier\n"
                                           "\tKarate Kid\t9.5\n"
                                           "\tAvengers: Endgame\t15\n"
                                           "\tSnow White\t1.5\n"
                                           "Amount owed is 26\n"
                                           "You earned 4 frequent renter points";

    std::shared_ptr<RentalMock> rentalMock1 = std::make_shared<RentalMock>();
    std::shared_ptr<RentalMock> rentalMock2 = std::make_shared<RentalMock>();
    std::shared_ptr<RentalMock> rentalMock3 = std::make_shared<RentalMock>();

    std::shared_ptr<Rental> rental1 = rentalMock1;
    std::shared_ptr<Rental> rental2 = rentalMock2;
    std::shared_ptr<Rental> rental3 = rentalMock3;

    std::shared_ptr<MovieMock> movieMock1 = std::make_shared<MovieMock>();
    std::shared_ptr<MovieMock> movieMock2 = std::make_shared<MovieMock>();
    std::shared_ptr<MovieMock> movieMock3 = std::make_shared<MovieMock>();

    EXPECT_CALL(*movieMock1, getTitle()).WillRepeatedly(Return("Karate Kid"));
    EXPECT_CALL(*movieMock2, getTitle()).WillRepeatedly(Return("Avengers: Endgame"));
    EXPECT_CALL(*movieMock3, getTitle()).WillRepeatedly(Return("Snow White"));

    EXPECT_CALL(*rentalMock1, getPrice()).WillRepeatedly(Return(9.5));
    EXPECT_CALL(*rentalMock2, getPrice()).WillRepeatedly(Return(15.));
    EXPECT_CALL(*rentalMock3, getPrice()).WillRepeatedly(Return(1.5));

    EXPECT_CALL(*rentalMock1, getRenterPoints()).WillRepeatedly(Return(1));
    EXPECT_CALL(*rentalMock2, getRenterPoints()).WillRepeatedly(Return(2));
    EXPECT_CALL(*rentalMock3, getRenterPoints()).WillRepeatedly(Return(1));

    EXPECT_CALL(*rentalMock1, getMovie()).WillRepeatedly(Return(movieMock1));
    EXPECT_CALL(*rentalMock2, getMovie()).WillRepeatedly(Return(movieMock2));
    EXPECT_CALL(*rentalMock3, getMovie()).WillRepeatedly(Return(movieMock3));

    Customer customer("Olivier");
    customer.addRental(rental1);
    customer.addRental(rental2);
    customer.addRental(rental3);

    ASSERT_EQ(customer.statement(), EXPECTED_STATEMENT);
}
