#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class OperationsExpert
    {
    private:
        /* data */
    public:
        OperationsExpert(Board board, City city);
        void build();
        OperationsExpert take_card(City city);
        void drive(City city);
        void fly_direct(City city);
        void treat(City city);
        void fly_shuttle(City city);
        void discover_cure(Color color);
        ~OperationsExpert();
    };

}