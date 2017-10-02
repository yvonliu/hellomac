#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace std::chrono_literals;

string doNaive(string source, vector<int> rotations)
{
    for (auto r : rotations)
    {
        for (int i = 0; i < r; ++i)
        {
            source[i] = (source[i] - 'a' + 1) % 26 + 'a';
        }
    }
    return source;
}
string doFast(string source, vector<int> rotations)
{
    sort(rotations.begin(), rotations.end());

    for (int i = 0; i < source.length(); ++i)
    {
        int count = distance(lower_bound(rotations.begin(), rotations.end(), i + 1), rotations.end());
        source[i] = (source[i] - 'a' + count) % 26 + 'a';
    }

    return source;
}

void doCompare(string source, vector<int> rotations)
{
    auto startNaive = chrono::high_resolution_clock::now();
    string sNaive = doNaive(source, rotations);
    auto endNaive = chrono::high_resolution_clock::now();

    auto startFast = chrono::high_resolution_clock::now();
    string sFast = doFast(source, rotations);
    auto endFast = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> elapseNaive = endNaive - startNaive;
    chrono::duration<double, std::milli> elapseFast = endFast - startFast;

    cout << "HASH naive:fast " << hex << hash<string>{}(sNaive) << ":" << hash<string>{}(sFast) << dec << endl;
    cout << "NAIVE:"  << elapseNaive.count() << " ms" << endl;
    cout << "FAST: "  << elapseFast.count() << " ms" << endl;
}
int main()
{
    doCompare(
        "thisisaverylongstringforencodethisisaverylongstringforencode",
        {1,2,1}
    );
    doCompare(
        "thisisaverylongstringforencodethisisaverylongstringforencodethisisaverylongstringforencodethisisaverylongstringforencodethisisaverylongstringforencodethisisaverylongstringforencodethisisaverylongstringforencodethisisaverylongstringforencode",
        {1,2,9,2,20,1,23,15}
    );
    doCompare(
        "thisisaverylongstringforencodethisisaverylongstringforencode", 
        {
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5,
            11,20,33,14,22,1,6,5,20,33,14,22,1,6,5,20,33,14,22,1,6,5
        }
    ); 
    return 0;
}
