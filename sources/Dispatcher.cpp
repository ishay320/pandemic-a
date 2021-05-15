#include "Dispatcher.hpp"
#include "Player.hpp"

using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    if (cityNow == c)
    {
        throw invalid_argument("cannot fly to the city that you currently in");
    }
    if (board.hasResearchStation(cityNow))
    {
        cityNow = c;
        return *this;
    }
    //if is not in Research Station so normal
    auto it = cards.find(c);
    if (it == cards.end())
    {
        string e ;
        e.append(board.getName(cityNow)).append(" is not found in your cards");
        throw invalid_argument(e);
    }
    cards.erase(c);
    cityNow = c;
    return *this;
}
std::string Dispatcher::role() const
{
    return "Dispatcher";
}