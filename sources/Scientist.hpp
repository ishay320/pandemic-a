#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <string>

namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int number;

    public:
        Scientist(Board &b, City c, int n) : Player(b, c), number(n < 5 ? n : 5) {}
        Player &discover_cure(Color c) override;
        std::string role() const override;
    };
}