#include "doctest.h"

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace std;
using namespace pandemic;


TEST_CASE("Researcher")
{
        Board board;
    board[City::NewYork] = 0;
    board[City::Montreal] = 1;

    Researcher player{board, City::NewYork};
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(Montreal);
    player.take_card(NewYork);

    CHECK_NOTHROW(player.drive(Montreal));
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
}
