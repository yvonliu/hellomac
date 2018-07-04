#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <queue>



int main(int argc, char** argv)
{
    using namespace std;

    set<pair<int, string>> s;
    s.insert( make_pair( 10, "test") );
    s.insert( make_pair( 0, "test") );
    s.insert( make_pair( 15, "test15") );
    s.insert( make_pair( 5, "test5") );

    for (auto p : s)
    {
        cout << p.first << ": " << p.second << endl;
    }

    priority_queue<pair<int, string>> pq;
    pq.push( make_pair( 10, "test") );
    pq.push( make_pair( 0, "test") );
    pq.push( make_pair( 15, "test15") );
    pq.push( make_pair( 5, "test5") );

    while (!pq.empty())
    {
        auto p = pq.top(); pq.pop();
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}