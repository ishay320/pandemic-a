#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
class Scientist : public Player {
    private:
        int number;
    public:
        Scientist(Board& b, City c, int n): Player(b, c, "Scientist") 
        {
            number = n;
        }
        Player& discover_cure(Color c) override;
};
}