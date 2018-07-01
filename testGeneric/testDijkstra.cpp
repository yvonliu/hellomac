#include <iostream>
#include <cstdint>
#include <vector>

const int v = 9;
int findMinDistance(const std::vector<uint32_t> & distance, const std::vector<bool> & isInSet)
{
    uint32_t minDist = UINT32_MAX; 
    int index = -1;
    for (int i = 0; i < distance.size(); ++i)
    {
        if (isInSet[i] == false && minDist >= distance[i])
        {
            minDist = distance[i];
            index = i;
        }
   }
    return index;
}
void dijkstras(int graph[v][v], int numVertice, int source)
{
    using namespace std;
    vector<bool> isInSet(numVertice, false);
    vector<uint32_t> distance(numVertice, UINT32_MAX);

    distance[source] = 0;

    for (int c = 0; c < numVertice; c++)
    {
        int idx = findMinDistance(distance, isInSet);
        isInSet[idx] = true;

        // update adj
        for (int i = 0; i < numVertice; ++i)
        {
            if (isInSet[i] == false && graph[idx][i] != 0)
            {
                uint32_t newDist = distance[idx] + graph[idx][i];
                if (distance[i]==UINT32_MAX || newDist < distance[i])
                    distance[i] = distance[idx] + graph[idx][i];
            }
        }
    }
    
    for (auto o: distance)
    {
        cout << o << " ";
    }
    cout << endl;
}
void testDijkstras()
{
    using namespace std;

    int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstras(graph, v, 0);
}
