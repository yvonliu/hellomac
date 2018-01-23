#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <memory>

using namespace std;

struct AnInt 
{
    unsigned int b0     : 1;
    unsigned int b12    : 2;
    unsigned int bA     : 7;
    unsigned int bOth   : 22;
};

int main()
{
    unsigned int i = 99;
    AnInt * p = reinterpret_cast<AnInt*>(&i);

    cout << hex << p-> b0 << ":" << p->b12 << ":" << p->bA << ":" << p->bOth << endl;

    return 0;
}