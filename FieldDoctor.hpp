#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class FieldDoctor
    {
    private:
        /* data */
    public:
        void build();
        FieldDoctor(Board board, City city);
        ~FieldDoctor();
    };

}