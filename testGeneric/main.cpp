#include <iostream>
#include <utility>
#include <set>
#include <map>

namespace aStar
{
    using Pos = std::pair<int, int>;

    const int map[5][15] =
    {
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
    };
    const int R = sizeof(map)/sizeof(map[0]);
    const int C = sizeof(map[0])/sizeof(map[0][0]);

    void visualize(Pos pos, Pos src, Pos dst)
    {
        using namespace std;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (pos.first == i && pos.second == j)
                    cout << "*";
                else if (src.first == i && src.second == j)
                    cout << "S";
                else if (dst.first == i && dst.second == j)
                    cout << "E";
                else
                    cout << ".";
            }
            cout << endl;
        }
    }
    void findPath(Pos src, Pos dst)
    {
        using namespace std;
        std::map<Pos, int> openSet, closeSet;
        openSet[src] = 0;
        closeSet.clear();

        
        
    }
    void testAStar()
    {
        using namespace std;
        findPath(make_pair(1, 1), make_pair(4,12));
    }
}
int main(int argc, char** argv)
{
    using namespace std;
    aStar::testAStar();
    return 0;
}