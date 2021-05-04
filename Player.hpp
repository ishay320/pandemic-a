#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <string>

namespace pandemic
{
    class Player
    {
    private:
        Board board;
        City city;
        std::string job;

    public:
        Player(Board &b, City c, std::string r)
        {
            board = b;
            city = c;
            job = r;
        }
        Player &drive(City c);
        virtual Player &fly_direct(City c);
        Player &fly_charter(City c);
        Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        string role()
        {
            return job;
        }
        Player &take_card(City c);
    };
}