#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <map>
#include <set>

using namespace std;

namespace pandemic
{
    class Board
    {
    private:
        std::array<std::string, 48> cityName;
        map<City, Color> cityColor;
        map<City, int> diseaseLvl;
        std::array<std::string, 4> colorName;
        std::map<City, std::set<City>> neighbors;
        std::array<bool, 4> cures;
        std::map<City, bool> researchStation;

    public:
        Board();
        std::string getColorName(const Color a) const;
        Color getColor(const City city) const;
        bool hasNeighbor(const City origin, const City neighbor) const;
        inline bool hasResearchStation(const City city) const { return researchStation.at(city); }
        void BuildResearchStation(const City city);
        void discover_cure(const Color color);
        inline bool getCure(const Color c) { return cures.at(size_t(c)); };
        std::string getName(const City city) const;
        int operator[](const City city) const;
        int &operator[](const City city);
        bool is_clean();
        void remove_cures();
        void remove_stations();
        friend std::ostream &operator<<(std::ostream &out, const Board &b);
    };
}