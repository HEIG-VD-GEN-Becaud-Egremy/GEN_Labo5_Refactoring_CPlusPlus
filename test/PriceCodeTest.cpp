#include "gtest/gtest.h"

#include "../src/PriceCode/PriceCode.h"
#include "mock/PriceCodeRegularMock.hpp"
#include "mock/PriceCodeNewReleaseMock.hpp"
#include "mock/PriceCodeChildrensMock.hpp"

using ::testing::Return;

TEST(PriceCodeGetPrice, unit) {
    PriceCodeRegularMock    pcRegular;
    PriceCodeNewReleaseMock pcNewRelease;
    PriceCodeChildrensMock  pcChildrens;

    EXPECT_CALL(pcRegular,    getPrice(1)).WillRepeatedly(Return(2.));
    EXPECT_CALL(pcRegular,    getPrice(3)).WillRepeatedly(Return(3.5));
    EXPECT_CALL(pcRegular,    getPrice(6)).WillRepeatedly(Return(8.));

    EXPECT_CALL(pcNewRelease, getPrice(1)).WillRepeatedly(Return(3.));
    EXPECT_CALL(pcNewRelease, getPrice(3)).WillRepeatedly(Return(9.));

    EXPECT_CALL(pcChildrens,  getPrice(1)).WillRepeatedly(Return(1.5));
    EXPECT_CALL(pcChildrens,  getPrice(4)).WillRepeatedly(Return(3.));
    EXPECT_CALL(pcChildrens,  getPrice(6)).WillRepeatedly(Return(6.));

    PriceCode* pcRegularPtr    = &pcRegular;
    PriceCode* pcNewReleasePtr = &pcNewRelease;
    PriceCode* pcChildrensPtr  = &pcChildrens;

    ASSERT_DOUBLE_EQ(pcRegularPtr->getPrice(1), 2.);
    ASSERT_DOUBLE_EQ(pcRegularPtr->getPrice(3), 3.5);
    ASSERT_DOUBLE_EQ(pcRegularPtr->getPrice(6), 8.);

    ASSERT_DOUBLE_EQ(pcNewReleasePtr->getPrice(1), 3.);
    ASSERT_DOUBLE_EQ(pcNewReleasePtr->getPrice(3), 9.);

    ASSERT_DOUBLE_EQ(pcChildrensPtr->getPrice(1), 1.5);
    ASSERT_DOUBLE_EQ(pcChildrensPtr->getPrice(4), 3.);
    ASSERT_DOUBLE_EQ(pcChildrensPtr->getPrice(6), 6.);
}

TEST(PriceCodeGetRenderPoints, unit) {
    PriceCodeRegularMock    pcRegular;
    PriceCodeNewReleaseMock pcNewRelease;
    PriceCodeChildrensMock  pcChildrens;

    EXPECT_CALL(pcRegular,    getRenderPoints(1)).WillRepeatedly(Return(1));
    EXPECT_CALL(pcRegular,    getRenderPoints(3)).WillRepeatedly(Return(1));

    EXPECT_CALL(pcNewRelease, getRenderPoints(1)).WillRepeatedly(Return(1));
    EXPECT_CALL(pcNewRelease, getRenderPoints(3)).WillRepeatedly(Return(2));

    EXPECT_CALL(pcChildrens,  getRenderPoints(1)).WillRepeatedly(Return(1));
    EXPECT_CALL(pcChildrens,  getRenderPoints(3)).WillRepeatedly(Return(1));

    PriceCode* pcRegularPtr    = &pcRegular;
    PriceCode* pcNewReleasePtr = &pcNewRelease;
    PriceCode* pcChildrensPtr  = &pcChildrens;

    ASSERT_EQ(pcRegularPtr->getRenderPoints(1), 1);
    ASSERT_EQ(pcRegularPtr->getRenderPoints(3), 1);

    ASSERT_EQ(pcNewReleasePtr->getRenderPoints(1), 1);
    ASSERT_EQ(pcNewReleasePtr->getRenderPoints(3), 2);

    ASSERT_EQ(pcChildrensPtr->getRenderPoints(1), 1);
    ASSERT_EQ(pcChildrensPtr->getRenderPoints(3), 1);
}