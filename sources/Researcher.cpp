#include "Researcher.hpp"
using namespace pandemic;

Player &Researcher::discover_cure(Color c)
{
    if (board.getCure(c))
    {
        return *this;
    }

    //check 5 cards with same color
    int count = 0;
    const int cardNum = 5;

    set<City> tmp;
    for (auto it : cards)
    {
        if (board.getColor(it) == c)
        {
            tmp.insert(it);
            count++;
        }
    }
    if (count < cardNum)
    {
        string e;
        e.append("you dont have enough ").append(board.getColorName(c)).append(" cards, you have only ").append(to_string(count));

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
std::string Researcher::role() const
{
    return "Researcher";
}