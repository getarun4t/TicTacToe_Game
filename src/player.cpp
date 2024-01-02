#include "player.hpp"

Player::Player() : my_turn(false) {}

bool Player::getTurn() {
    return my_turn;
}

void Player::setTurn() {
    my_turn = true;
}

void Player::resetTurn() {
    my_turn = false;
}