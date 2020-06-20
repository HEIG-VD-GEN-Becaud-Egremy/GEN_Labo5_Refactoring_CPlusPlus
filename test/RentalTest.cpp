#include "gtest/gtest.h"
#include <memory>

#include "../src/Rental.h"
#include "mock/MovieMock.hpp"
#include "mock/PriceCodeRegularMock.hpp"
#include "mock/PriceCodeNewReleaseMock.hpp"

using ::testing::Return;

TEST(RentalGetPrice, unit) {
    std::shared_ptr<MovieMock> movieMock = std::make_shared<MovieMock>();

    EXPECT_CALL(*movieMock, getPrice(2)).WillRepeatedly(Return(2.));
    EXPECT_CALL(*movieMock, getPrice(4)).WillRepeatedly(Return(5.));

    Rental rental2Days = Rental(movieMock, 2);
    Rental rental4Days = Rental(movieMock, 4);

    ASSERT_DOUBLE_EQ(rental2Days.getPrice(), 2.);
    ASSERT_DOUBLE_EQ(rental4Days.getPrice(), 5.);
}

TEST(RentalGetRenterPoints, simple) {
    std::shared_ptr<MovieMock> regularMovieMock = std::make_shared<MovieMock>();
    std::shared_ptr<MovieMock> newReleaseMovie1Mock = std::make_shared<MovieMock>();
    std::shared_ptr<MovieMock> newReleaseMovie2Mock = std::make_shared<MovieMock>();

    std::shared_ptr<PriceCodeRegularMock>    pcRegularMockPtr    = std::make_shared<PriceCodeRegularMock>();
    std::shared_ptr<PriceCodeNewReleaseMock> pcNewReleaseMockPtr = std::make_shared<PriceCodeNewReleaseMock>();

    EXPECT_CALL(*regularMovieMock,     getPriceCode()).WillRepeatedly(Return(pcRegularMockPtr));
    EXPECT_CALL(*newReleaseMovie1Mock, getPriceCode()).WillRepeatedly(Return(pcNewReleaseMockPtr));
    EXPECT_CALL(*newReleaseMovie2Mock, getPriceCode()).WillRepeatedly(Return(pcNewReleaseMockPtr));

    EXPECT_CALL(*pcRegularMockPtr,    getRenterPoints(1u)).WillRepeatedly(Return(1u));
    EXPECT_CALL(*pcNewReleaseMockPtr, getRenterPoints(1u)).WillRepeatedly(Return(1u));
    EXPECT_CALL(*pcNewReleaseMockPtr, getRenterPoints(2u)).WillRepeatedly(Return(2u));

    Rental rentalRegularMovie     = Rental(regularMovieMock,     1);
    Rental rentalNewReleaseMovie1 = Rental(newReleaseMovie1Mock, 1);
    Rental rentalNewReleaseMovie2 = Rental(newReleaseMovie2Mock, 2);

    ASSERT_EQ(rentalRegularMovie.getRenterPoints(), 1);
    ASSERT_EQ(rentalNewReleaseMovie1.getRenterPoints(), 1);
    ASSERT_EQ(rentalNewReleaseMovie2.getRenterPoints(), 2);
}

TEST(RentalGetMovie, simple) {
    const std::string TITLE = "The Trembling Window";
    std::shared_ptr<MovieMock> movieMock = std::make_shared<MovieMock>();

    EXPECT_CALL(*movieMock, getTitle()).WillRepeatedly(Return(TITLE));

    Rental rental = Rental(movieMock, 2);

    ASSERT_EQ(rental.getMovie()->getTitle(), TITLE);
}
