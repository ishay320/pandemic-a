#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <string>

namespace pandemic
{
    class Researcher : public Player
    {

    public:
        Researcher(Board &b, City c) : Player(b, c) {}
        Player &discover_cure(Color c) override;
        std::string role() const override;
    };
}