#include <gtest/gtest.h>
#include "../include/play.hpp"

TEST(Play, Demo) {
	int demo_int = 2;
	ASSERT_EQ(demo_int, 2);
}

TEST(Play, TestFile) {
  Play game;

  EXPECT_EQ(game.checkGameEnd(), true);

  game.board[0][0] = "X";
  game.board[1][1] = "X";
  game.board[2][2] = "X";
  EXPECT_EQ(game.checkGameEnd(), false);
}