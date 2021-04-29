#include "City.hpp"

#include <iostream>
namespace pandemic
{
    class Board
    {
    private:
        /* data */
    public:
        Board(/* args */);
        bool is_clean();
        void operator[](City city);
        void operator=(int num);
        friend std::ostream &operator<<(std::ostream &os, Board &board);
        ~Board();
    };

}