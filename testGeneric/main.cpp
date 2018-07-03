#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <cmath>

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
    const double D_INF = -1.0;
    struct vertex
    {
        double _f;  // = g+h
        double _g;
        double _h;
        Pos _parent;
        bool _closed;
        vertex() 
        : _f(D_INF), _g(D_INF), _h(D_INF),
         _parent(std::make_pair(-1,-1)), _closed(false)
         {
         }
    };
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
    std::vector<Pos> findNeighborsOnMap(Pos v)
    {
        using namespace std;
        vector<Pos> neighbors;
        for (int r = -1; r <= 1; ++r)
        {
            for (int c = -1; c <= 1; ++c)
            {
                if (!(0 == r && 0 == c))
                {
                    int next_r = v.first + r;
                    int next_c = v.second + c;
                    if (next_r >= 0 && next_r < R &&
                        next_c >= 0 && next_c < C &&
                        map[next_r][next_c] == 0)
                    {
                        neighbors.push_back(make_pair(next_r, next_c));
                        // cerr << "next r,c: " << next_r << "," << next_c << endl;
                    }
                }
            }
        }
        return neighbors;
    }
    double calculateH(Pos v, Pos dst)
    {
        return std::sqrt((v.first - dst.first) * (v.first - dst.first) 
            + (v.second - dst.second) * ( v.second - dst.second));
    }
    void aStar(Pos src, Pos dst)
    {
        using namespace std;

        std::set<Pos> openSet;
        openSet.insert(src);

        vertex detail[R][C];

        detail[src.first][src.second]._f = 0.0;
        detail[src.first][src.second]._g = 0.0;
        detail[src.first][src.second]._h = 0.0;

        while (!openSet.empty())
        {
            Pos v = *(openSet.begin());
            openSet.erase(openSet.begin());

            detail[v.first][v.second]._closed = true;

            auto neighbors = findNeighborsOnMap(v);
            for (auto n : neighbors)
            {
                double next_g = detail[v.first][v.second]._g + 1.0;
                double next_h = calculateH(n, dst);
                double next_f = next_g + next_h;

                //auto itor = openSet.find(n);
                if (detail[n.first][n.second]._f == D_INF ||
                    detail[n.first][n.second]._f > next_f)
                {
                    detail[n.first][n.second]._g = next_g;
                    detail[n.first][n.second]._h = next_h;
                    detail[n.first][n.second]._f = next_f;
                    openSet.insert(n);
                }
            }
        }
    }
    
    void testAStar()
    {
        using namespace std;
        aStar(make_pair(0, 1), make_pair(4,12));
    }
}
int main(int argc, char** argv)
{
    using namespace std;
    aStar::testAStar();
    return 0;
}