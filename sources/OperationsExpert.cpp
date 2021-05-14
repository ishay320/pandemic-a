#include "OperationsExpert.hpp"
#include "Player.hpp"

using namespace pandemic;

Player &OperationsExpert::build()
{
    board.BuildResearchStation(cityNow);
    return *this;
}
std::string OperationsExpert::role() const
{
    return "OperationsExpert";
}