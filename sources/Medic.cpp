#include "Medic.hpp"
#include "Player.hpp"
#include "Color.hpp"

using namespace pandemic;

Player &Medic::drive(City c)
{
    Player::drive(c);
    if (board.getCure(board.getColor(cityNow)))
    {
        board[cityNow] = 0;
    }
    return *this;
}
Player &Medic::fly_direct(City c)
{
    Player::fly_direct(c);
    if (board.getCure(board.getColor(cityNow)))
    {
        board[cityNow] = 0;
    }
    return *this;
}
Player &Medic::fly_charter(City c)
{
    Player::fly_charter(c);
    if (board.getCure(board.getColor(cityNow)))
    {
        board[cityNow] = 0;
    }
    return *this;
}
Player &Medic::fly_shuttle(City c)
{
    Player::fly_shuttle(c);
    if (board.getCure(board.getColor(cityNow)))
    {
        board[cityNow] = 0;
    }
    return *this;
}
Player &Medic::treat(City c)
{
    if (cityNow != c)
    {
        throw invalid_argument("you are not in the same city");
    }
    if (board[c] == 0)
    {
        throw invalid_argument("the city is cured already");
    }

    board[c] = 0;
    return *this;
}
std::string Medic::role() const
{
    return "Medic";
}