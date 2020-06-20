#include "gtest/gtest.h"
#include "../src/Movie.h"
#include "mock/PriceCodeRegularMock.hpp"
#include "mock/PriceCodeNewReleaseMock.hpp"
#include "mock/PriceCodeChildrensMock.hpp"

using ::testing::Return;

TEST(MovieGetPriceRegular, unit) {
    Movie regularMovie = Movie("Dream in the Gift");

    ASSERT_DOUBLE_EQ(regularMovie.getPrice(2), 2.);
    ASSERT_DOUBLE_EQ(regularMovie.getPrice(4), 5.);
}

TEST(MovieGetPriceNewRelease, unit) {
    std::shared_ptr<PriceCodeNewReleaseMock> pcNewReleasePtr = std::make_shared<PriceCodeNewReleaseMock>();

    EXPECT_CALL(*pcNewReleasePtr, getPrice(2)).WillRepeatedly(Return(6.));
    EXPECT_CALL(*pcNewReleasePtr, getPrice(4)).WillRepeatedly(Return(12.));

    Movie newReleaseMovie = Movie("Rainbow of Time", pcNewReleasePtr);

    ASSERT_DOUBLE_EQ(newReleaseMovie.getPrice(2), 6.);
    ASSERT_DOUBLE_EQ(newReleaseMovie.getPrice(4), 12.);
}

TEST(MovieGetPriceChildrens, unit) {
    std::shared_ptr<PriceCodeChildrensMock> pcChildrensPtr = std::make_shared<PriceCodeChildrensMock>();

    EXPECT_CALL(*pcChildrensPtr, getPrice(2)).WillRepeatedly(Return(1.5));
    EXPECT_CALL(*pcChildrensPtr, getPrice(4)).WillRepeatedly(Return(3.));

    Movie childrensMovie = Movie("The Dream of the Legend", pcChildrensPtr);

    ASSERT_DOUBLE_EQ(childrensMovie.getPrice(2), 1.5);
    ASSERT_DOUBLE_EQ(childrensMovie.getPrice(4), 3.);
}

TEST(MovieGetPriceCode, unit) {
    std::shared_ptr<PriceCodeRegularMock>    pcRegularPtrMock    = std::make_shared<PriceCodeRegularMock>();
    std::shared_ptr<PriceCodeNewReleaseMock> pcNewReleasePtrMock = std::make_shared<PriceCodeNewReleaseMock>();
    std::shared_ptr<PriceCodeChildrensMock>  pcChildrensPtrMock  = std::make_shared<PriceCodeChildrensMock>();

    Movie::PriceCode_ptr pcRegularPtr    = pcRegularPtrMock;
    Movie::PriceCode_ptr pcNewReleasePtr = pcNewReleasePtrMock;
    Movie::PriceCode_ptr pcChildrensPtr  = pcChildrensPtrMock;

    Movie regularMovie    = Movie("Snake of Illusion",    pcRegularPtr);
    Movie newReleaseMovie = Movie("The Flame of the Ice", pcNewReleasePtr);
    Movie childrensMovie  = Movie("The Weeping School",   pcChildrensPtr);

    ASSERT_EQ(regularMovie.getPriceCode(),    pcRegularPtr);
    ASSERT_EQ(newReleaseMovie.getPriceCode(), pcNewReleasePtr);
    ASSERT_EQ(childrensMovie.getPriceCode(),  pcChildrensPtr);
}

TEST(MovieGetTitle, unit) {
    std::string title = "Frozen Serpents";
    Movie movie = Movie(title);
    ASSERT_EQ(movie.getTitle(), title);
}