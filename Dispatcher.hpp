#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Dispatcher
    {
    private:
        /* data */
    public:
        void build();
        Dispatcher(Board board, City city);
        ~Dispatcher();
    };

}