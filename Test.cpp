#include "doctest.h"
#include <stdexcept>
#include <cassert>
#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;
using namespace WarGame;

Board board(8, 8);


TEST_CASE("Add soldiers for players")
{
    // Add soldiers for player 1:
    CHECK(!board.has_soldiers(1));

    CHECK_NOTHROW((board[{0, 1}] = new FootSoldier(1)));
    CHECK_NOTHROW((board[{0, 3}] = new FootCommander(1)));
    CHECK_NOTHROW((board[{0, 5}] = new FootSoldier(1)));
    CHECK_NOTHROW((board[{0, 7}] = new Sniper(1)));
    CHECK_NOTHROW((board[{1, 0}] = new SniperCommander(1)));
    CHECK_NOTHROW((board[{1, 2}] = new Paramedic(1)));
    CHECK_NOTHROW((board[{1, 4}] = new ParamedicCommander(1)));
    CHECK_NOTHROW((board[{1, 6}] = new FootCommander(1)));

    CHECK(board.has_soldiers(1));

    // Add soldiers for player 2:
    CHECK(!board.has_soldiers(2));

    CHECK_NOTHROW((board[{7, 1}] = new FootSoldier(2)));
    CHECK_NOTHROW((board[{7, 3}] = new FootCommander(2)));
    CHECK_NOTHROW((board[{7, 5}] = new FootSoldier(2)));
    CHECK_NOTHROW((board[{7, 7}] = new Sniper(2)));
    CHECK_NOTHROW((board[{6, 0}] = new SniperCommander(2)));
    CHECK_NOTHROW((board[{6, 2}] = new Paramedic(2)));
    CHECK_NOTHROW((board[{6, 4}] = new ParamedicCommander(2)));
    CHECK_NOTHROW((board[{6, 6}] = new FootCommander(2)));

    CHECK(board.has_soldiers(2));
}

TEST_CASE("Soldiers of player 1 moves forward and attacks.")
{
    CHECK_NOTHROW(board.move(1, { 0, 1 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 0, 3 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 0, 5 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 0, 7 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 1, 0 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 1, 2 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 1, 4 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 1, 6 }, Board::MoveDIR::Up));
}

TEST_CASE("Soldiers of player 2 moves forward and attacks.")
{
    CHECK_NOTHROW(board.move(2, { 7, 1 }, Board::MoveDIR::Down));
    CHECK_NOTHROW(board.move(2, { 7, 3 }, Board::MoveDIR::Down));
    CHECK_NOTHROW(board.move(2, { 7, 5 }, Board::MoveDIR::Down));
    CHECK_NOTHROW(board.move(2, { 7, 7 }, Board::MoveDIR::Down));
    CHECK_NOTHROW(board.move(2, { 6, 0 }, Board::MoveDIR::Down));
    CHECK_NOTHROW(board.move(2, { 6, 2 }, Board::MoveDIR::Down));
    CHECK_NOTHROW(board.move(2, { 6, 4 }, Board::MoveDIR::Down));
    CHECK_NOTHROW(board.move(2, { 6, 6 }, Board::MoveDIR::Down));
}
TEST_CASE("Check points of player 2")
{
    CHECK((board[{6, 1}]->health ) == 100);
    CHECK((board[{6, 3}]->health) == 150);
    CHECK((board[{6, 5}]->health) == 100);
    CHECK((board[{6, 7}]->health) == 100);
    CHECK((board[{5, 0}]->health) == 90);
    CHECK((board[{5, 2}]->health) == 80);
    CHECK((board[{5, 4}]->health) == 120);
    CHECK((board[{5, 6}]->health) == 30);

    CHECK(board.has_soldiers(2));
}
TEST_CASE("Check points of player 1")
{
    CHECK((board[{1, 1}]->health) == 100);
    CHECK((board[{1, 3}]->health) == 50);
    CHECK((board[{1, 5}]->health) == 100);
    CHECK((board[{1, 7}]->health) == 100);
    CHECK((board[{2, 0}]->health) == 90);
    CHECK((board[{2, 2}]->health) == 80);
    CHECK((board[{2, 4}]->health) == 120);
    CHECK((board[{2, 6}]->health) == 80);

   CHECK(board.has_soldiers(1));
}
TEST_CASE("Soldiers of player 1 moves right or left and attacks.")
{
    CHECK_NOTHROW(board.move(1, { 1, 1 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(1, { 1, 3 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(1, { 1, 5 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(1, { 1, 7 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(1, { 2, 0 }, Board::MoveDIR::Right));
    CHECK_NOTHROW(board.move(1, { 2, 2 }, Board::MoveDIR::Right));
    CHECK_NOTHROW(board.move(1, { 2, 4 }, Board::MoveDIR::Right));
    CHECK_NOTHROW(board.move(1, { 2, 6 }, Board::MoveDIR::Right));
}

TEST_CASE("Check points of player 2.")
{
    CHECK((board[{6, 1}]->health) == 50);
    CHECK((board[{6, 3}]->health) == 100);
    CHECK((board[{6, 5}]->health) == 100);
    CHECK((board[{6, 7}]->health) == 100);
    CHECK((board[{5, 0}]->health) == 60);
    CHECK((board[{5, 2}]->health) == 50);
    CHECK((board[{5, 6}]->health) == 10);

    CHECK(board.has_soldiers(2));
}
TEST_CASE("Soldiers of player 2 moves right or left and attacks.")
{
    CHECK_NOTHROW(board.move(2, { 6, 1 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(2, { 6, 3 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(2, { 6, 5 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(2, { 6, 7 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(2, { 5, 0 }, Board::MoveDIR::Right));
    CHECK_NOTHROW(board.move(2, { 5, 2 }, Board::MoveDIR::Right));
    CHECK_NOTHROW(board.move(2, { 5, 6 }, Board::MoveDIR::Right));
}
TEST_CASE("Check points of player 1.")
{
    CHECK((board[{1, 0}]->health) == 100);
    CHECK((board[{1, 2}]->health) == 50);
    CHECK((board[{1, 4}]->health) == 100);
    CHECK((board[{1, 6}]->health) == 100);
    CHECK((board[{2, 1}]->health) == 40);
    CHECK((board[{2, 3}]->health) == 60);
    CHECK((board[{2, 5}]->health) == 90);
    CHECK((board[{2, 7}]->health) == 60);

    CHECK(board.has_soldiers(1));
}

TEST_CASE("Soldiers of player 1 moves right or left and attacks.")
{
    CHECK_NOTHROW(board.move(1, { 1, 0 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 1, 2 }, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, { 1, 4 }, Board::MoveDIR::Up));

    CHECK(board.has_soldiers(2));
}
TEST_CASE("Check points of player 1.")
{
    CHECK((board[{2, 0}]->health) == 100);
    CHECK((board[{2, 2}]->health) == 50);
    CHECK((board[{2, 4}]->health) == 100);

    CHECK(board.has_soldiers(1));
}

TEST_CASE("Soldiers of player 2 moves right or left and attacks.")
{
    CHECK_NOTHROW(board.move(2, { 6, 4 }, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(2, { 6, 6 }, Board::MoveDIR::Left));

    CHECK(board.has_soldiers(1));
}
TEST_CASE("Check points of player 2.")
{
    CHECK((board[{6, 3}]->health) == 100);
    CHECK((board[{6, 5}]->health) == 100);

    CHECK(board.has_soldiers(2));
}

TEST_CASE("Delete soldiers.") {
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Soldier* soldier = board[{i, j}];
            if (soldier)
                delete soldier;
        }
    }
}