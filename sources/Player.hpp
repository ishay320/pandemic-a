#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <string>
#include <set>
namespace pandemic
{
    class Player
    {
    protected:
        Board &board;
        City cityNow;
        std::set<City> cards;

    public:
        Player(Board &b, City c) : cityNow(c), board(b) {}

        Player &take_card(City c);
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        virtual std::string role() const = 0;
        void remove_cards();
        /**
         * @brief prints all the cards of the player
         * (for debug)
         * @param out 
         * @param p 
         * @return std::ostream& 
         */
        friend std::ostream &operator<<(std::ostream &out, const Player &p);
        string print_cards(string);
        std::set<string> getCards() const;
        inline City getCityNow() { return cityNow; }
    };
}