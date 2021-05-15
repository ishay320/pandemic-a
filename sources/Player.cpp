#include "Player.hpp"
#include "City.hpp"
#include <exception>
#include <iostream>

using namespace pandemic;

Player &Player::take_card(City c)
{
    cards.insert(c);
    return *this;
}
Player &Player::drive(City c)
{
    if (board.hasNeighbor(cityNow, c))
    {
        cityNow = c;
        return *this;
    }
    string e;
    e.append(board.getName(cityNow)).append(" is not connected to ").append(board.getName(c));
    throw invalid_argument(e);
}
Player &Player::fly_direct(City c)
{
    if (cityNow == c)
    {
        throw invalid_argument("cannot fly to the city that you currently in");
    }
    auto it = cards.find(c);
    if (it == cards.end())
    {
        string e;
        e.append(board.getName(c)).append(" is not found in your cards(player class)");
        throw invalid_argument(e);
    }
    cityNow = c;
    cards.erase(c);
    return *this;
}
Player &Player::fly_charter(City c)
{
    if (cityNow == c)
    {
        throw invalid_argument("cannot fly to the city that you currently in");
    }
    auto it = cards.find(cityNow);
    if (it == cards.end())
    {
        string e;
        e.append(board.getName(cityNow)).append(" is not found in your cards");
        throw invalid_argument(e);
    }
    cards.erase(cityNow);
    cityNow = c;
    return *this;
}
Player &Player::fly_shuttle(City c)
{
    if (cityNow == c)
    {
        throw invalid_argument("cannot fly to the city that you currently in");
    }
    if (!board.hasResearchStation(cityNow))
    {
        string e;
        e.append(board.getName(cityNow)).append(" (your city) dont have a Research Station");
        throw invalid_argument(e);
    }
    if (!board.hasResearchStation(c))
    {
        string e;
        e.append(board.getName(c)).append(" dont have a Research Station");
        throw invalid_argument(e);
    }
    cityNow = c;
    return *this;
}
Player &Player::build()
{
    auto it = cards.find(cityNow);
    if (it == cards.end())
    {
        string e;
        e.append(board.getName(cityNow)).append(" is not found in your cards");
        throw invalid_argument(e);
    }
    cards.erase(cityNow);
    board.BuildResearchStation(cityNow);
    return *this;
}
Player &Player::discover_cure(Color c)
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

    //check 5 cards with same color
    size_t count = 0;
    const int cardNum = 5;
    array<City, cardNum> tmp = {};
    for (const auto &it : cards)
    {
        if (board.getColor(it) == c)
        {
            tmp.at(count) = it;
            count++;
            if (count == cardNum)
            {
                break;
            }
        }
    }
    if (count < cardNum)
    {
        string e;
        // e.append("your cards are :");
        // for (const auto &it : cards)
        // {
        //     e.append(board.getName(it)).append(to_string((int)board.getColor(it))).append(",");
        // }
        // e.append("}").append(to_string((int)c));
        e.append("you dont have enough ").append(board.getColorName(c)).append(" cards, you have ").append(to_string(count));
        throw invalid_argument(e);
    }
    board.discover_cure(c);
    //remove 5 first cards with c color
    for (auto it : tmp)
    {
        cards.erase(it);
    }
    return *this;
}
Player &Player::treat(City c)
{
    if (cityNow != c)
    {
        throw invalid_argument("you are not in the same city");
    }
    if (board[c] == 0)
    {
        throw invalid_argument("the city is cured already");
    }
    if (board.getCure(board.getColor(c)))
    {
        board[c] = 0;
        return *this;
    }
    board[c]--;
    return *this;
}
void Player::remove_cards()
{
    cards.clear();
}

string Player::print_cards(string e ,Color c)
{
    e.append("your cards are :");
    for (const auto &it : cards)
    {
        e.append(board.getName(it)).append(to_string((int)board.getColor(it))).append(",");
    }
    e.append("}").append(to_string((int)c)).append("\n").append("city now:").append(board.getName(cityNow));
    if (board.hasResearchStation(cityNow))
    {
       e.append(" hasResearchStation ");
    }else{
               e.append(" NOThasResearchStation ");

    }
    
    return e;
}