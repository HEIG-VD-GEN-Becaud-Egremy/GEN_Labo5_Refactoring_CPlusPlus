#include "gtest/gtest.h"

#include "../src/PriceCode/PriceCodeNewRelease.h"

TEST(PriceCodeNewReleaseGetPrice, unit) {
    PriceCodeNewRelease pcNewRelease = PriceCodeNewRelease();

    ASSERT_DOUBLE_EQ(pcNewRelease.getPrice(1), 3.);
    ASSERT_DOUBLE_EQ(pcNewRelease.getPrice(3), 9.);
}

TEST(PriceCodeNewReleaseGetRenderPoints, unit) {
    PriceCodeNewRelease pcRegular = PriceCodeNewRelease();

    ASSERT_EQ(pcRegular.getRenderPoints(1), 1);
    ASSERT_EQ(pcRegular.getRenderPoints(3), 2);
}
