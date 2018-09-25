#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;
string trim(const string & s)
{
    size_t start = s.find_first_not_of(" ");
    size_t end = s.find_last_not_of(" ");
    return (start != string::npos) ? s.substr(start, end-start+1) : "";
}
string subtract(const string & s, size_t pos, size_t length)
{
    if (pos == 0)
        return trim(s.substr(pos+length));
    if (pos + length == s.length())
        return trim(s.substr(0, pos));
    
    string a = trim(s.substr(0, pos));
    string b = trim(s.substr(pos+length));
    return a + " " + b;
}
int main(int argc, char** argv)
{
    cout << subtract("abcdef", 3, 2) << endl;
    cout << subtract("abcdef", 3, 3) << "<" << endl;
    cout << subtract("abcdef", 0, 2) << "<" << endl;
    cout << subtract("abcdef", 5, 1) << "<" << endl;
    cout << subtract("abcdef", 1, 2) << "<" << endl;
    return 0;
}