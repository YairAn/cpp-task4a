#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include "DemoGame.hpp"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>




TEST_CASE("Snipers 4x4") {
    WarGame::Board board(4,4);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new Sniper(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
	board[{3,1}] = new Sniper(2);
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}
TEST_CASE("FootSoliders 4x4") {
    WarGame::Board board(4,4);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
	board[{3,1}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Right);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(2,{3,1},WarGame::Board::MoveDIR::Left);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(2,{3,1},WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2,{3,1},WarGame::Board::MoveDIR::Down));
    CHECK_THROWS(board.move(2,{3,1},WarGame::Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{3,1},WarGame::Board::MoveDIR::Right));
    CHECK_THROWS(board.move(2,{1,2},WarGame::Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{1,2},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{3,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{2,2},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{3,1},WarGame::Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(2,{2,0},WarGame::Board::MoveDIR::Right);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
     board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
     board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
     board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{2,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(!board.has_soldiers(1)); // player 2 win
    
}


TEST_CASE("Paramedic && FootCommander") {
    WarGame::Board board(4,4);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    board[{0,2}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{3,1}] = new Paramedic(2);
	board[{3,0}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK(board[{3,0}]->health == 90);
    board.move(2,{3,1},WarGame::Board::MoveDIR::Right);
    board.move(2,{3,2},WarGame::Board::MoveDIR::Left);
    CHECK(board[{3,0}]->health == 100);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{0,2},WarGame::Board::MoveDIR::Left);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK(board[{3,0}]->health == 90);
    board.move(1,{0,1},WarGame::Board::MoveDIR::Right);
    board.move(1,{0,2},WarGame::Board::MoveDIR::Left);
    CHECK(board[{3,0}]->health == 70);
    board.move(2,{3,1},WarGame::Board::MoveDIR::Right);
    board.move(2,{3,2},WarGame::Board::MoveDIR::Left);
    CHECK(board[{3,0}]->health == 100);
    board.move(1,{0,1},WarGame::Board::MoveDIR::Right);
    board.move(1,{0,2},WarGame::Board::MoveDIR::Left);
     CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{0,1},WarGame::Board::MoveDIR::Right);
    board.move(1,{0,2},WarGame::Board::MoveDIR::Left);
     CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{0,1},WarGame::Board::MoveDIR::Right);
    board.move(1,{0,2},WarGame::Board::MoveDIR::Left);
     CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{0,1},WarGame::Board::MoveDIR::Right);
    board.move(1,{0,2},WarGame::Board::MoveDIR::Left);
     CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{0,1},WarGame::Board::MoveDIR::Right);
    board.move(1,{0,2},WarGame::Board::MoveDIR::Left);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}
