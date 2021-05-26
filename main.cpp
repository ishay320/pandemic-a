#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <random>

#include "sources/Board.hpp"
#include "sources/City.hpp"
#include "sources/Color.hpp"
#include "sources/Researcher.hpp"
#include "sources/Scientist.hpp"
#include "sources/FieldDoctor.hpp"
#include "sources/GeneSplicer.hpp"
#include "sources/OperationsExpert.hpp"
#include "sources/Dispatcher.hpp"
#include "sources/Medic.hpp"
#include "sources/Virologist.hpp"
#include "sources/Player.hpp"
#include <queue>
using namespace pandemic;
using namespace std;
const int cityCount = 48;

City randomCity(int seed)
{
    srand((u_int)seed);
    return static_cast<City>(rand() % 48);
}
void fillDeck(queue<City> deck)
{
    srand(1); //needs to be random himself
    const int cityCount = 48;
    array<int, 48> tmp;
    while (deck.size() < cityCount)
    {
        bool haveIt = false;
        int randomCity = rand() % 48;
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if (tmp.at(i) == randomCity)
            {
                haveIt = true;
                break;
            }
        }
        if (!haveIt)
        {
            deck.push(static_cast<City>(randomCity));
        }
    }
}

City getNeighborCity(Board b, City cityNow)
{
    cout << "choose city:\n";
    int lines = 0;
    for (size_t i = 0; i < cityCount; i++)
    {
        if (b.hasNeighbor(cityNow, static_cast<City>(i)))
        {
            cout << i << "-" << b.getName(static_cast<City>(i)) << "        ";
            if (lines++ % 3 == 0)
                cout << endl;
        }
    }
    int tmp;
    cin >> tmp;
    return static_cast<City>(tmp);
}
City getCity(Board b)
{
    cout << "choose city:\n";
    for (size_t i = 0; i < cityCount; i++)
    {
        cout << i << "-" << b.getName(static_cast<City>(i)) << "        ";
        if (i % 3 == 0)
            cout << endl;
    }
    int tmp;
    cin >> tmp;
    return static_cast<City>(tmp);
}
int main(int argc, char const *argv[])
{

    //start game board
    Board board;
    //add Research Stations
    for (size_t i = 0; i < 16; i++)
    {
        board.BuildResearchStation(randomCity(i));
    }

    //add players to the board
    cout << "how many players?" << endl;
    int playerCount = 1;
    cin >> playerCount;
    queue<Player *> players;
    for (size_t i = 0; i < playerCount; i++)
    {
        cout << "what role?" << endl;
        cout << "1-Dispatcher" << endl;
        cout << "2-FieldDoctor" << endl;
        cout << "3-GeneSplicer" << endl;
        cout << "4-Medic" << endl;
        cout << "5-OperationsExpert" << endl;
        cout << "6-Researcher" << endl;
        cout << "7-Scientist" << endl;
        cout << "8-Virologist" << endl;
        int choice;
        cin >> choice;
        int seed = rand();
        if (choice == 1)
        {
            Dispatcher *dispatcher = new Dispatcher(board, randomCity(seed));
            players.push(dispatcher);
        }
        else if (choice == 2)
        {
            FieldDoctor *fieldDoctor = new FieldDoctor(board, randomCity(seed));
            players.push(fieldDoctor);
        }
        else if (choice == 3)
        {
            GeneSplicer *geneSplicer = new GeneSplicer(board, randomCity(seed));
            players.push(geneSplicer);
        }
        else if (choice == 4)
        {
            Medic *medic = new Medic(board, randomCity(seed));
            players.push(medic);
        }
        else if (choice == 5)
        {
            OperationsExpert *operationsExpert = new OperationsExpert(board, randomCity(seed));
            players.push(operationsExpert);
        }
        else if (choice == 6)
        {
            Researcher *researcher = new Researcher(board, randomCity(seed));
            players.push(researcher);
        }
        else if (choice == 7)
        {
            int n;
            cout << "Scientist number:" << endl;
            cin >> n;
            Scientist *scientist = new Scientist(board, randomCity(seed), n);
            players.push(scientist);
        }
        else if (choice == 8)
        {
            Virologist *virologist = new Virologist(board, randomCity(seed));
            players.push(virologist);
        }
        else
        {
            cout << "wrong option" << endl;
            i--;
        }
    }
    //cards setup
    queue<City> deck;
    fillDeck(deck);
    //board set random levels
    int randomSeed = 1; //need to be random
    srand((u_int)randomSeed);
    for (int i = 0; i < cityCount; i++)
    {
        board[randomCity(rand())] = rand() % 5;
    }
    //start game
    bool gameOn = true;
    int playerNow = 0;

    while (gameOn)
    {
        cout << endl
             << "player num " << playerNow % playerCount << " -role- " << players.front()->role() << endl;
        cout << "choose move:" << endl;

        cout << "0-take_card+end_turn" << endl;
        cout << "1-drive" << endl;
        cout << "2-fly_direct" << endl;
        cout << "3-fly_charter" << endl;
        cout << "4-fly_shuttle" << endl;
        cout << "5-build" << endl;
        cout << "6-discover_cure" << endl;
        cout << "7-treat" << endl;
        cout << "8-print_cards" << endl;
        cout << "9-print_board" << endl;
        cout << "10-end_turn" << endl;

        int choice;
        cin >> choice;
        int seed = 1;
        if (choice == 0) //take_card
        {
            City randCity = randomCity(rand());
            cout << "the card is: " << board.getName(randCity);
            Player *tmp = players.front();
            tmp->take_card(randCity);
            players.pop();
            players.push(tmp);
            playerNow++;
        }
        else if (choice == 1) //drive
        {
            cout << "where to drive?" << endl;
            City city = getNeighborCity(board, players.front()->getCityNow());
            Player *tmp = players.front();
            try
            {
                tmp->drive(city);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                cout << "try again\n";
            }
        }
        else if (choice == 2) //fly_direct
        {
            cout << "where to fly_direct?" << endl;
            City city = getCity(board);
            Player *tmp = players.front();
            try
            {
                tmp->fly_direct(city);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                cout << "try again\n";
            }
        }
        else if (choice == 3) //fly_charter
        {
            cout << "where to fly_charter?" << endl;
            City city = getCity(board);
            Player *tmp = players.front();
            try
            {
                tmp->fly_charter(city);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                cout << "try again\n";
            }
        }
        else if (choice == 4) //fly_shuttle
        {
            cout << "where to fly_shuttle?" << endl;
            City city = getCity(board);
            Player *tmp = players.front();
            try
            {
                tmp->fly_shuttle(city);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                cout << "try again\n";
            }
        }
        else if (choice == 5) //build
        {
            cout << "building..." << endl;
            Player *tmp = players.front();
            try
            {
                tmp->build();
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                cout << "try again" << endl;
            }
        }
        else if (choice == 6) //discover_cure
        {
            cout << "what color?" << endl;
            cout << "0-Blue" << endl;
            cout << "1-Yellow" << endl;
            cout << "2-Black" << endl;
            cout << "3-Red" << endl;

            int color;
            cin >> color;
            Player *tmp = players.front();
            try
            {
                tmp->discover_cure(static_cast<Color>(color));
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                cout << "try again\n";
            }
        }
        else if (choice == 7) //treat
        {
            cout << "where to treat?" << endl;
            City city = getCity(board);
            Player *tmp = players.front();
            try
            {
                tmp->treat(city);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                cout << "try again\n";
            }
        }
        else if (choice == 8) //print_cards
        {
            Player *tmp = players.front();
            string strTmp;
            strTmp = tmp->print_cards(strTmp);
            cout << strTmp << endl;
        }
        else if (choice == 9) //print_board
        {
            cout << board << endl;
        }
        else if (choice == 10) //end turn
        {
            Player *tmp = players.front();
            players.pop();
            players.push(tmp);
            playerNow++;
        }
        else
        {
            cout << "wrong option" << endl;
        }
    }
}
