#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

void print(const deque<int> & q)
{
    for (int i : q)
    {
        cout << i << " ";
    }
    cout << endl;
}

int findCombinition(vector<int> lego, int target)
{
    deque<int> nextTarget;
    using intPair = pair<int, int>;
    auto lambdaHasher = [](const intPair & i)
    {
        return i.first + 32 * i.second; 
    };
    unordered_set<intPair, decltype(lambdaHasher)> cache(0, lambdaHasher);

    nextTarget.push_back(target);
    int layer = 0;
    const int EOL = -1;
    nextTarget.push_back(EOL);

    while (!nextTarget.empty())
    {
        //print(nextTarget);
        int t = nextTarget.front(); nextTarget.pop_front();

        if (t == EOL)
        {
            layer++;
            if (!nextTarget.empty())
                nextTarget.push_back(EOL);
        }
        for (auto i : lego)
        {
            if (t - i == 0)
            {
                // cout << "found" << layer << endl;
                return layer+1;
            }
            else if (t - i > 0)
            {
                auto what = cache.find(make_pair(layer, t-i));

                if (what == cache.end())
                {
                    nextTarget.push_back(t - i);
                    cache.insert(make_pair(layer, t-i));
                }
            }
        }
    }
    return 0;
}
void testBFS()
{
    vector<int> lego = {1, 2, 4, 5, 6};
    cout << findCombinition(lego, 9) << endl;;
    cout << findCombinition(lego, 10) << endl;;
    cout << findCombinition(lego, 0) << endl;;
    cout << findCombinition(lego, 50) << endl;;
    cout << findCombinition(lego, 2) << endl;;
    cout << findCombinition(lego, 1000) << endl;;
    cout << findCombinition(lego, 4000) << endl;;
}

