#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class GeneSplicer
    {
    private:
        /* data */
    public:
        void build();
        GeneSplicer(Board board, City city);
        ~GeneSplicer();
    };

}