#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Medic
    {
    private:
        /* data */
    public:
        void build();
        Medic(Board board, City city);
        ~Medic();
    };

}