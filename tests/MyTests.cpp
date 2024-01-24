#include <gtest/gtest.h>
#include "../include/play.hpp"

TEST(Play, SanityTest) {
  Play game;
  EXPECT_EQ(game.checkGameEnd(), true);
}