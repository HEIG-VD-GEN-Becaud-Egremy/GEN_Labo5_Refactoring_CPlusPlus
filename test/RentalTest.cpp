#include "gtest/gtest.h"
#include <memory>

#include "../src/Rental.h"
#include "mock/MovieMock.hpp"
#include "mock/PriceCodeRegularMock.hpp"
#include "mock/PriceCodeNewReleaseMock.hpp"

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
    MovieMock regularMovieMock;
    MovieMock newReleaseMovie1Mock;
    MovieMock newReleaseMovie2Mock;

    Movie* regularMovie     = &regularMovieMock;
    Movie* newReleaseMovie1 = &newReleaseMovie1Mock;
    Movie* newReleaseMovie2 = &newReleaseMovie2Mock;

    std::shared_ptr<PriceCodeRegularMock>    pcRegularMockPtr    = std::make_shared<PriceCodeRegularMock>();
    std::shared_ptr<PriceCodeNewReleaseMock> pcNewReleaseMockPtr = std::make_shared<PriceCodeNewReleaseMock>();

    EXPECT_CALL(regularMovieMock,     getPriceCode()).WillRepeatedly(Return(pcRegularMockPtr));
    EXPECT_CALL(newReleaseMovie1Mock, getPriceCode()).WillRepeatedly(Return(pcNewReleaseMockPtr));
    EXPECT_CALL(newReleaseMovie2Mock, getPriceCode()).WillRepeatedly(Return(pcNewReleaseMockPtr));

    EXPECT_CALL(*pcRegularMockPtr,    getRenderPoints(1u)).WillRepeatedly(Return(1u));
    EXPECT_CALL(*pcNewReleaseMockPtr, getRenderPoints(1u)).WillRepeatedly(Return(1u));
    EXPECT_CALL(*pcNewReleaseMockPtr, getRenderPoints(2u)).WillRepeatedly(Return(2u));

    Rental rentalRegularMovie     = Rental(regularMovie,     1);
    Rental rentalNewReleaseMovie1 = Rental(newReleaseMovie1, 1);
    Rental rentalNewReleaseMovie2 = Rental(newReleaseMovie2, 2);

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
