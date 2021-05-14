#include "Virologist.hpp"
using namespace pandemic;

Player &Virologist::treat(City c)
{
    if (cityNow != c)
    {
        //check for card
        if (cards.find(c) == cards.end())
        {
            throw invalid_argument("dont have card for the city " + board.getName(c));
        }
        cards.erase(c);
        if (board.getCure(board.getColor(c)))
        {
            board[c] = 0;
            return *this;
        }
        board[c]--;
        return *this;
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
std::string Virologist::role() const
{
    return "Virologist";
}