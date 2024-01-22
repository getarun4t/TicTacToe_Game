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

TEST(Play, PositiveTest) {
	Play game;
	game.setBoardValue(0, 0, "X");
	game.setBoardValue(1, 1, "X");
	game.setBoardValue(2, 2, "X");
	EXPECT_EQ(game.checkGameEnd(), false);
}