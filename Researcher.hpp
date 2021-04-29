#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Researcher
    {
    private:
        /* data */
    public:
        void build();
        Researcher(Board board, City city);
        ~Researcher();
    };

}