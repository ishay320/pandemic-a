#include "City.hpp"
#include "Color.hpp"

#include <string>

namespace pandemic
{
    class Player
    {
    private:
        /* data */
    public:
        Player take_card(City city);
        std::string role();
        std::string can_discover_cure(Player player, Color color);
        void drive(City city);
        void discover_cure(Color color);        
        Player(/* args */);
        ~Player();
    };

}