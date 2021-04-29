#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Scientist
    {
    private:
        /* data */
    public:
        void build();
        Scientist(Board board, City city);
        ~Scientist();
    };

}