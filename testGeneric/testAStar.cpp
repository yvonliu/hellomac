#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>

namespace aStar
{
    using Pos = std::pair<int, int>;

    int map[15][15] =
    {
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0},
        {0,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0},
        {0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0},
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
    void visualize()
    {
        using namespace std;
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
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
        return 2 * std::sqrt((v.first - dst.first) * (v.first - dst.first) 
            + (v.second - dst.second) * ( v.second - dst.second));
    }
    void aStar(Pos src, Pos dst)
    {
        using namespace std;
        using setElement = std::pair<double, Pos>;
        using setElementContainer = std::vector<setElement>;

        auto v_compar = [](setElement left, setElement right) { return left.first > right.first; };

        std::priority_queue<setElement, setElementContainer, decltype(v_compar)> openSet(v_compar);

        openSet.push(make_pair(0.0, src));

        vertex detail[R][C];

        detail[src.first][src.second]._f = 0.0;
        detail[src.first][src.second]._g = 0.0;
        detail[src.first][src.second]._h = 0.0;
        detail[src.first][src.second]._parent = src;

        while (!openSet.empty())
        {
            Pos v = openSet.top().second;
            openSet.pop();

            detail[v.first][v.second]._closed = true;

            auto neighbors = findNeighborsOnMap(v);
            for (auto n : neighbors)
            {
                if (dst == n)
                {
                    cout << "found dst: " <<  endl;
                    detail[n.first][n.second]._parent = v;
                    
                    while(!openSet.empty()) 
                        openSet.pop();

                    break;
                }
                else if (detail[n.first][n.second]._closed == false)
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
                        detail[n.first][n.second]._parent = v;
                        openSet.push(make_pair(next_f,n));
                    }
                }
            }
            ////
            for (int i = 0; i < R; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    if (0.0 == detail[i][j]._f)
                        cout << "-ss- ";
                    else if (i == dst.first && j == dst.second)
                        cout << "-dd- ";
                    else if (i == v.first && j == v.second)
                        cout << "-XD- ";
                    else if (-1.0 == detail[i][j]._f)
                        cout << ".... ";
                    else
                        cout << std::fixed << std::setw(3) << std::setprecision(1) << detail[i][j]._f << " ";
                }
                cout << endl;
                for (int j = 0; j < C; ++j)
                {
                    if (0.0 == detail[i][j]._f)
                        cout << "     ";
                    else if (make_pair(-1,-1) == detail[i][j]._parent)
                        cout << "  x  ";
                    else
                        cout << setw(5) << detail[i][j]._parent.first * 15 + detail[i][j]._parent.second;
                }
                cout << endl;            }
            cout << endl;
        }
        // backTrace

        Pos trace = dst;
        while (trace != src)
        {
            map[trace.first][trace.second] = 9;
            cout << "trace: " << trace.first << ", " << trace.second << endl;
            trace = detail[trace.first][trace.second]._parent;
        }
        visualize();
    }
    
    void testAStar()
    {
        using namespace std;
        aStar(make_pair(3, 3), make_pair(13,13));
    }
}