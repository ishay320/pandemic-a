#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <map>
using namespace std;

namespace pandemic
{
    class Board
    {
    private:
        map<City, int> lvl_of_disease;

    public:
        Board() {}
        void remove_cures();
        bool is_clean();
        int &operator[](City city);
        friend std::ostream &operator<<(std::ostream &out, const Board &b);
    };
}