#include "gtest/gtest.h"

#include "../src/PriceCode/PriceCodeChildrens.h"

TEST(PriceCodeChildrensGetPrice, unit) {
    PriceCodeChildrens pcChildrens = PriceCodeChildrens();

    ASSERT_DOUBLE_EQ(pcChildrens.getPrice(1), 1.5);
    ASSERT_DOUBLE_EQ(pcChildrens.getPrice(4), 3.);
    ASSERT_DOUBLE_EQ(pcChildrens.getPrice(6), 6.);
}

TEST(PriceCodeChildrensGetRenderPoints, unit) {
    PriceCodeChildrens pcChildrens = PriceCodeChildrens();

    ASSERT_EQ(pcChildrens.getRenderPoints(1), 1);
    ASSERT_EQ(pcChildrens.getRenderPoints(3), 1);
}
