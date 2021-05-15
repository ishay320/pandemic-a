#include "Scientist.hpp"
#include "Color.hpp"
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{
    if (board.getCure(c))
    {
        return *this;
    }
    //check for research station
    if (!board.hasResearchStation(cityNow))
    {
        throw invalid_argument("you dont have research station in your city");
    }

    //check n cards with same color
    int count = 0;
    set<City> tmp;
    for (auto it : cards)
    {
        if (board.getColor(it) == c)
        {
            tmp.insert(it);
            count++;
        }
    }
    if (count < number)
    {
        string e;
        e.append("you dont have enough ").append(board.getColorName(c)).append(" cards, you have only ").append(to_string(count));
        throw invalid_argument(e);
    }
    board.discover_cure(c);
    //remove n first cards with c color
    auto it = tmp.begin();
    for (int i = 0; i < number; i++)
    {
        cards.erase(*it);
        ++it;
    }
    return *this;
}

std::string Scientist::role() const
{
    return "Scientist";
}