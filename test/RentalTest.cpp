#include "gtest/gtest.h"

#include "../src/Rental.h"
#include "mock/MovieMock.hpp"

using ::testing::Return;

TEST(RentalGetPrice, unit) {
    MovieMock movie;

    EXPECT_CALL(movie, getPrice(2)).WillRepeatedly(Return(2.));
    EXPECT_CALL(movie, getPrice(4)).WillRepeatedly(Return(5.));

    Rental rental2Days = Rental(&movie, 2);
    Rental rental4Days = Rental(&movie, 4);

    ASSERT_DOUBLE_EQ(rental2Days.getPrice(), 2.);
    ASSERT_DOUBLE_EQ(rental4Days.getPrice(), 5.);
}

TEST(RentalGetRenderPoints, simple) {
    MovieMock regularMovie;
    MovieMock newReleaseMovie1;
    MovieMock newReleaseMovie2;

    EXPECT_CALL(regularMovie,     getPriceCode()).WillRepeatedly(Return(REGULAR));
    EXPECT_CALL(newReleaseMovie1, getPriceCode()).WillRepeatedly(Return(NEW_RELEASE));
    EXPECT_CALL(newReleaseMovie2, getPriceCode()).WillRepeatedly(Return(NEW_RELEASE));

    Rental rentalRegularMovie     = Rental(&regularMovie,     1);
    Rental rentalNewReleaseMovie1 = Rental(&newReleaseMovie1, 1);
    Rental rentalNewReleaseMovie2 = Rental(&newReleaseMovie2, 2);

    ASSERT_EQ(rentalRegularMovie.getRenterPoints(),    1);
    ASSERT_EQ(rentalNewReleaseMovie1.getRenterPoints(),1);
    ASSERT_EQ(rentalNewReleaseMovie2.getRenterPoints(),2);
}

TEST(RentalGetMovie, simple) {
    const std::string TITLE = "The Trembling Window";
    MovieMock movie;

    EXPECT_CALL(movie, getTitle()).WillRepeatedly(Return(TITLE));

    Rental rental = Rental(&movie, 2);

    ASSERT_EQ(rental.getMovie().getTitle(), TITLE);
}
