#include "FieldDoctor.hpp"
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
    if (cityNow != c)
    {
        if (!board.hasNeighbor(cityNow,c))
        {
            throw invalid_argument("the city "+board.getName(cityNow)+" is not connected to "+board.getName(c));
        }
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
std::string FieldDoctor::role() const
{
    return "FieldDoctor";
}