#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <sstream>

const char INPUT[] = "sample.in";

using namespace std;
void gbus()
{
    ifstream input(INPUT);

    int testSet = 0;

    input >> testSet;
    cerr << "number of test set: " << testSet << endl;

    for (int i = 0; i < testSet; ++i)
    {
        int buses = 0;
        input >> buses;
        cerr << buses << " buses." << endl;

        int maxCityNumber = 0;
        vector<pair<int, int>> busRoute;

        for (int j = 0; j < buses; ++j)
        {
            pair<int, int> route;
            input >> route.first >> route.second;
            cerr << "route " << j << ": " << route.first << "<>" << route.second << endl;
            if (route.second > maxCityNumber) maxCityNumber = route.second;
            busRoute.push_back(route);
        }
        cerr << "max city:" << maxCityNumber << endl;
        vector<int> solution(maxCityNumber, 0);

        for (auto r : busRoute)
        {
            for (int x = r.first; x <= r.second; x++)
                solution[x]++;
        }

        int testCases = 0;
        input >> testCases;
        cerr << testCases << " test cases." << endl;

        cout << "Case #" << i+1 << ":";

        for (int k = 0; k < testCases; k++)
        {
            int cityId = 0;
            input >> cityId;
            if (cityId >0 && cityId <= maxCityNumber)
            {
                cerr << "city " << cityId << ": " << solution[cityId] << endl;
                cout << " " << solution[cityId];
            }
            else
            {
                cerr << "city " << cityId << "(out of range): " << 0 << endl;
                cout << " 0";

            }

        }
        cout << endl;
    } 
}

uint64_t findPivot(uint64_t index)
{
    int i = 0;
    uint64_t pivot = 1;
    while (index > 1)
    {
        i++;
        index >>= 1;
    }
    pivot <<= i;
    cerr << "pivot(" << i << "):" << pivot << endl;
    return pivot;
}
int findGS(uint64_t index)
{
    cerr << "findgs::" << index << endl;
    uint64_t p = findPivot(index);

    if (index > p)
    {
        return 1 ^ findGS(p - (index - p));
    }
    else if (index == p)
    {
        return 0;
    }
    else
    {
        cerr << "!?" << endl;
    }


    return 0;
}
void findGoggolString()
{
    ifstream input(INPUT);

    int testSet = 0;

    input >> testSet;
    cerr << "number of test set: " << testSet << endl;
 
    for (int i = 0; i < testSet; ++i)
    {
        uint64_t index=0;
        input >> index;
        cout << "Case #" << i+1 << ": " << findGS(index) << endl;;
    }
}
class ticket
{
public:
    string origin;
    string destination;
    ticket * nextTicket;

    ticket(string ori, string dest) : origin(ori), destination(dest), nextTicket(nullptr) {}
};
void sortTicket(std::vector<ticket*> tickets)
{
    using namespace std;

    unordered_map<string, ticket *> destMap;
    unordered_map<string, ticket *> originMap;
 
    // build maps
    for (auto t : tickets)
    {
        destMap[t->destination] = t;
        originMap[t->origin] = t;
    }

    ticket * pHead = tickets[0];
    while (true)
    {
        auto prev = destMap.find(pHead->origin);
        if (prev != destMap.end())
        {
            prev->second->nextTicket = pHead;
            pHead = prev->second;
        }
        else
        {
            break;
        }
    }
    ticket * pTail = tickets[0];
    while (true)
    {
        auto next = originMap.find(pTail->destination);
        if (next != originMap.end())
        {
            pTail->nextTicket = next->second;
            pTail = next->second;
        }
        else
        {
            pTail->nextTicket = nullptr;
            break;
        }
    }
    while (pHead != nullptr)
    {
        cout << pHead->origin << "-" << pHead->destination << " "; 
        pHead = pHead->nextTicket;
    }
    
}
void sortTicketMain()
{
   using namespace std;

    vector<ticket *> tickets;

    ifstream input(INPUT);

    int testSet = 0;

    input >> testSet;
    cerr << "number of test set: " << testSet << endl;
 
    for (int i = 0; i < testSet; ++i)
    {
        int numTickets =0;
        input >> numTickets;
        for (int j = 0; j < numTickets; j++)
        {
            string o, d;
            input >> o; input >> d;

            tickets.push_back(new ticket(o, d));
        }
        cout << "Case #" << i+1 << ": ";
        sortTicket(tickets);
        cout << endl;
        for (auto t : tickets)
        {
            delete t;
        }
        tickets.clear();
    } 

}
int main(int argc, char** argv)
{
    using namespace std;
    std::stringstream ss;

    ss << "hello world" << std::ends;

    char c;

    while (ss >> c)
    {
        cout << ":" << c << endl;
    }

    
    
    return 0;
}