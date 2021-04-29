#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Virologist
    {
    private:
        /* data */
    public:
        void build();
        Virologist(Board board, City city);
        ~Virologist();
    };

}