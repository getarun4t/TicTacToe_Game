#include <gtest/gtest.h>
#include "../include/play.hpp"

TEST(Play, Demo) {
	int demo_int = 2;
	ASSERT_EQ(demo_int, 2);
}

TEST(Play, TestFile) {
  Play game;

  EXPECT_EQ(game.checkGameEnd(), true);
}