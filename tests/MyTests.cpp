#include <gtest/gtest.h>
#include "play.hpp"

TEST(Play, checkGameEnd) {
	Play game;

	EXPECT_EQ(game.checkGameEnd(), true);

	game.board[0][0] = "X";
	game.board[1][1] = "X";
	game.board[2][2] = "X";
	EXPECT_EQ(game.checkGameEnd(), false);
}