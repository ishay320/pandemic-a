#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <string>

namespace pandemic
{
    class OperationsExpert : public Player
    {

    public:
        OperationsExpert(Board &b, City c) : Player(b, c) {}
        Player &build() override;
        std::string role() const override;
    };
}