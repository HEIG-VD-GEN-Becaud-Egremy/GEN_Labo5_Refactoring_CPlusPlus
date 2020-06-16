#include "gtest/gtest.h"
#include "../src/Movie.h"

TEST(MovieGetPriceRegular, simple) {
    Movie regularMovie = Movie("Dream in the Gift");

    ASSERT_DOUBLE_EQ(regularMovie.getPrice(2), 2.);
    ASSERT_DOUBLE_EQ(regularMovie.getPrice(4), 5.);
}

TEST(MovieGetPriceNewRelease, simple) {
    Movie newReleaseMovie = Movie("Rainbow of Time", NEW_RELEASE);

    ASSERT_DOUBLE_EQ(newReleaseMovie.getPrice(2), 6.);
    ASSERT_DOUBLE_EQ(newReleaseMovie.getPrice(4), 12.);
}

TEST(MovieGetPriceChildrens, simple) {
    Movie childrensMovie = Movie("The Dream of the Legend", CHILDRENS);

    ASSERT_DOUBLE_EQ(childrensMovie.getPrice(2), 1.5);
    ASSERT_DOUBLE_EQ(childrensMovie.getPrice(4), 3.);
}

TEST(MovieGetPriceCode, simple) {
    Movie regularMovie    = Movie("Snake of Illusion");
    Movie newReleaseMovie = Movie("The Flame of the Ice", NEW_RELEASE);
    Movie childrensMovie  = Movie("The Weeping School", CHILDRENS);

    ASSERT_EQ(regularMovie.getPriceCode(),    REGULAR);
    ASSERT_EQ(newReleaseMovie.getPriceCode(), NEW_RELEASE);
    ASSERT_EQ(childrensMovie.getPriceCode(),  CHILDRENS);
}

TEST(MovieGetTitle, simple) {
    std::string title = "Frozen Serpents";
    Movie movie = Movie(title);
    ASSERT_EQ(movie.getTitle(), title);
}