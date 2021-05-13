#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <string>

namespace pandemic
{
    class Virologist : public Player
    {

    public:
        Virologist(Board &b, City c) : Player(b, c) {}
        Player &treat(City c) override;
        std::string role() const override;
    };
}