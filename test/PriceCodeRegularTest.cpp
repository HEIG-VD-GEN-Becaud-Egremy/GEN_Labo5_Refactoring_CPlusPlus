#include "gtest/gtest.h"

#include "../src/PriceCode/PriceCodeRegular.h"

TEST(PriceCodeRegularGetPrice, unit) {
    PriceCodeRegular pcRegular = PriceCodeRegular();

    ASSERT_DOUBLE_EQ(pcRegular.getPrice(1), 2.);
    ASSERT_DOUBLE_EQ(pcRegular.getPrice(3), 3.5);
    ASSERT_DOUBLE_EQ(pcRegular.getPrice(6), 8.);
}

TEST(PriceCodeRegularGetRenderPoints, unit) {
    PriceCodeRegular pcRegular = PriceCodeRegular();

    ASSERT_EQ(pcRegular.getRenderPoints(1), 1);
    ASSERT_EQ(pcRegular.getRenderPoints(3), 1);
}
