#include "GeneSplicer.hpp"
using namespace pandemic;

Player &GeneSplicer::discover_cure(Color c)
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

    //check for 5 cards
    int count = 0;
    set<City> tmp;
    const int cardNum = 5;
    for (auto it : cards)
    {

        tmp.insert(it);
        count++;

        if (count == cardNum)
        {
            break;
        }
    }
    if (count < cardNum)
    {
        string e;
        e.append("you dont have enough cards, you have only ").append(to_string(count));
        throw invalid_argument(e);
    }
    board.discover_cure(c);
    //remove 5 first cards with c color
    auto it = tmp.begin();
    for (int i = 0; i < cardNum; i++)
    {
        cards.erase(*it);
        ++it;
    }
    return *this;
}
std::string GeneSplicer::role() const
{
    return "GeneSplicer";
}