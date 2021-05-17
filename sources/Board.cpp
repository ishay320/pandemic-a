#include "Board.hpp"
#include <iostream>

namespace pandemic
{
    Board::Board() : cures({false, false, false, false})
    {
        //fill the colors
        const int blue = 12;
        const int yellow = 24;
        const int black = 36;
        const int cityNum = 48;
        for (int i = 0; i < cityNum; ++i)
        {
            City city = static_cast<City>(i);
            if (i < blue)
            {
                cityColor[city] = Color::Blue;
            }
            else if (i < yellow)
            {
                cityColor[city] = Color::Yellow;
            }
            else if (i < black)
            {
                cityColor[city] = Color::Black;
            }
            else
            {
                cityColor[city] = Color::Red;
            }
        }
        //connect the cities
        neighbors[City::NewYork] = {City::Madrid, City::London, City::Washington, City::Montreal};
        neighbors[City::Montreal] = {City::Washington, City::Chicago, City::NewYork};
        neighbors[City::Chicago] = {City::SanFrancisco, City::Atlanta, City::Montreal, City::MexicoCity, City::LosAngeles};
        neighbors[City::SanFrancisco] = {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila};
        neighbors[City::Atlanta] = {City::Washington, City::Chicago, City::Miami};
        neighbors[City::Washington] = {City::NewYork, City::Montreal, City::Atlanta, City::Miami};
        neighbors[City::London] = {City::Madrid, City::Paris, City::NewYork, City::Essen};
        neighbors[City::Madrid] = {City::London, City::Paris, City::NewYork, City::SaoPaulo, City::Algiers};
        neighbors[City::Paris] = {City::Milan, City::Essen, City::London, City::Madrid, City::Algiers};
        neighbors[City::Milan] = {City::Istanbul, City::Paris, City::Essen};
        neighbors[City::Essen] = {City::Milan, City::Paris, City::London, City::StPetersburg};
        neighbors[City::StPetersburg] = {City::Moscow, City::Istanbul, City::Essen};
        neighbors[City::Moscow] = {City::Tehran, City::StPetersburg, City::Istanbul};
        neighbors[City::Istanbul] = {City::Moscow, City::StPetersburg, City::Milan, City::Algiers, City::Cairo, City::Baghdad};
        neighbors[City::Algiers] = {City::Madrid, City::Paris, City::Istanbul, City::Cairo};
        neighbors[City::Cairo] = {City::Algiers, City::Istanbul, City::Baghdad, City::Riyadh, City::Khartoum};
        neighbors[City::Baghdad] = {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi};
        neighbors[City::Tehran] = {City::Moscow, City::Baghdad, City::Karachi, City::Delhi};
        neighbors[City::Riyadh] = {City::Karachi, City::Baghdad, City::Cairo};
        neighbors[City::Karachi] = {City::Delhi, City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai};
        neighbors[City::Delhi] = {City::Kolkata, City::Chennai, City::Mumbai, City::Karachi, City::Tehran};
        neighbors[City::Mumbai] = {City::Karachi, City::Delhi, City::Chennai};
        neighbors[City::Kolkata] = {City::Delhi, City::Chennai, City::Bangkok, City::HongKong};
        neighbors[City::Chennai] = {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta};
        neighbors[City::MexicoCity] = {City::LosAngeles, City::Miami, City::Bogota, City::Lima, City::Chicago};
        neighbors[City::Miami] = {City::MexicoCity, City::Bogota, City::Atlanta, City::Washington};
        neighbors[City::LosAngeles] = {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney};
        neighbors[City::Bogota] = {City::Miami, City::MexicoCity, City::Lima, City::BuenosAires, City::SaoPaulo};
        neighbors[City::Lima] = {City::Bogota, City::MexicoCity, City::Santiago};
        neighbors[City::Santiago] = {City::Lima};
        neighbors[City::BuenosAires] = {City::Bogota, City::SaoPaulo};
        neighbors[City::SaoPaulo] = {City::Madrid, City::Lagos, City::BuenosAires, City::Bogota};
        neighbors[City::Lagos] = {City::SaoPaulo, City::Kinshasa, City::Khartoum};
        neighbors[City::Khartoum] = {City::Kinshasa, City::Johannesburg, City::Lagos, City::Cairo};
        neighbors[City::Kinshasa] = {City::Lagos, City::Khartoum, City::Johannesburg};
        neighbors[City::Johannesburg] = {City::Khartoum, City::Kinshasa};
        neighbors[City::Beijing] = {City::Shanghai, City::Seoul};
        neighbors[City::Seoul] = {City::Tokyo, City::Beijing, City::Shanghai};
        neighbors[City::Tokyo] = {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco};
        neighbors[City::HongKong] = {City::Shanghai, City::Taipei, City::Manila, City::HoChiMinhCity, City::Bangkok, City::Kolkata};
        neighbors[City::Shanghai] = {City::Beijing, City::Seoul, City::Tokyo, City::Taipei, City::HongKong};
        neighbors[City::Taipei] = {City::Osaka, City::Shanghai, City::HongKong, City::Manila};
        neighbors[City::Osaka] = {City::Tokyo, City::Taipei};
        neighbors[City::Bangkok] = {City::HongKong, City::HoChiMinhCity, City::Jakarta, City::Chennai, City::Kolkata};
        neighbors[City::Jakarta] = {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney};
        neighbors[City::HoChiMinhCity] = {City::Jakarta, City::Bangkok, City::HongKong, City::Manila};
        neighbors[City::Manila] = {City::HongKong, City::HoChiMinhCity, City::Taipei, City::Sydney, City::SanFrancisco};
        neighbors[City::Sydney] = {City::Jakarta, City::Manila, City::LosAngeles};

        //disease = 0
        for (int i = 0; i < cityNum; ++i)
        {
            City city = static_cast<City>(i);
            diseaseLvl[city] = 0;
        }

        //research = false
        for (int i = 0; i < cityNum; ++i)
        {
            City city = static_cast<City>(i);
            researchStation[city] = false;
        }
        //color names
        colorName = {
            "Blue", "Yellow", "Black", "Red"};

        //city names by order
        cityName = {
            "NewYork", "Montreal", "Chicago", "SunFrancisco", "Atlanta", "Washington", "London", "Madrid", "Paris", "Milan", "Essen", "ST_Petersburg",
            "MexicoCity", "Miami", "LosAngeles", "Bogota", "Lima", "Santiago", "BuenosAires", "SaoPaulo", "Lagos", "Khartoum", "Kinshasa", "Johannesburg",
            "Moscow", "Istanbul", "Algiers", "Cairo", "Baghdad", "Tehran", "Riyadh", "Karachi", "Delhi", "Mumbai", "Kolcata", "Chennai",
            "Beijing", "Seoul", "Tokyo", "HongKong", "Shanghai", "Taipei", "Osaka", "Bangkok", "Jakarta", "HoChiMinhCity", "Manila", "Sydney"};
    }
    std::string Board::getColorName(const Color a) const
    {
        return colorName.at(a);
    }
    Color Board::getColor(const City city) const
    {
        return cityColor.at(city);
    }
    bool Board::hasNeighbor(const City origin, const City neighbor) const
    {
        return neighbors.at(origin).find(neighbor) != neighbors.at(origin).end();
    }
    void Board::BuildResearchStation(const City city)
    {
        researchStation[city] = true;
    }
    void Board::discover_cure(const Color color)
    {
        cures.at((size_t)color) = true;
    }
    std::string Board::getName(const City city) const
    {
        return cityName.at((size_t)city);
    }
    int Board::operator[](const City city) const
    {
        return diseaseLvl.at(city);
    }
    int &Board::operator[](const City city)
    {
        return diseaseLvl[city];
    }
    bool Board::is_clean()
    {
        for (auto i : diseaseLvl)
        {
            if (i.second != 0)
            {
                return false;
            }
        }
        return true;
    }
    void Board::remove_cures()
    {
        cures.fill(false);
    }
    void Board::remove_stations()
    {
        for (auto i : researchStation)
        {
            researchStation.at(i.first) = false;
        }
    }

    ostream &operator<<(ostream &out, const Board &b)
    {
        out << "Board:  ";
        int i = 0;
        const int lineJumps = 5;
        for (const auto &iter : b.cityName)
        {
            out << iter << "{RS=" << b.hasResearchStation(static_cast<City>(i)) << "}"
                <<"{diseaseLvl:"<<b.diseaseLvl.at(static_cast<City>(i))<< "}, ";
            i++;

            if (i % lineJumps == 0)
            {
                out << endl;
            }
        }
        return out;
    }
}