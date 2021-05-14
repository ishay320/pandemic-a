#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <ctime>

#include "sources/Board.hpp"
#include "sources/City.hpp"
#include "sources/Color.hpp"
#include "sources/Researcher.hpp"
#include "sources/Scientist.hpp"
#include "sources/FieldDoctor.hpp"
#include "sources/GeneSplicer.hpp"
#include "sources/OperationsExpert.hpp"
#include "sources/Dispatcher.hpp"
#include "sources/Medic.hpp"
#include "sources/Virologist.hpp"

using namespace pandemic;
using namespace std;

int main(int argc, char const *argv[])
{
    Board board;
    OperationsExpert default_player{board, City::Algiers};
    board.BuildResearchStation(City::Algiers);
    default_player.take_card(City::Algiers);
    default_player.take_card(City::Atlanta);
    default_player.take_card(City::Baghdad);
    default_player.take_card(City::Chennai);
    default_player.take_card(City::Essen);
    default_player.take_card(City::Kolkata);
    default_player.take_card(City::Lima);
    default_player.take_card(City::Manila);
    default_player.discover_cure(Color::Black);

    return 0;
}
