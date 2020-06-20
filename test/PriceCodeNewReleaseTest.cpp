#include "gtest/gtest.h"

#include "../src/PriceCode/PriceCodeNewRelease.h"

TEST(PriceCodeNewReleaseGetPrice, unit) {
    PriceCodeNewRelease pcNewRelease = PriceCodeNewRelease();

    ASSERT_DOUBLE_EQ(pcNewRelease.getPrice(1), 3.);
    ASSERT_DOUBLE_EQ(pcNewRelease.getPrice(3), 9.);
}

TEST(PriceCodeNewReleaseGetRenterPoints, unit) {
    PriceCodeNewRelease pcRegular = PriceCodeNewRelease();

    ASSERT_EQ(pcRegular.getRenterPoints(1), 1);
    ASSERT_EQ(pcRegular.getRenterPoints(3), 2);
}
