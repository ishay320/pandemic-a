#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <string>

namespace pandemic
{
    class Medic : public Player
    {

    public:
        Medic(Board &b, City c) : Player(b, c) {}
        Player &drive(City c) override;
        Player &fly_direct(City c) override;
        Player &fly_charter(City c) override;
        Player &fly_shuttle(City c) override;
        Player &treat(City c) override;
        std::string role() const override;
    };
}