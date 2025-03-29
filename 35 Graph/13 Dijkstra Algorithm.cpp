#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> nbrs;

    void addEdge(int src, int des, int wt, bool dir)
    {
        if (dir)
        {
            this->nbrs[src].push_back({des, wt});
        }
        else
        {
            this->nbrs[src].push_back({des, wt});
            this->nbrs[des].push_back({src, wt});
        }
    }
    void printNbrs(int nodes)
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << i << " ->";
            for (auto nbr : this->nbrs[i])
            {
                cout << "{ " << nbr.first << ", " << nbr.second << " },";
            }
            cout << endl;
        }
    }
    void shortestDistanceDijkstra(int src, int nodes)
    {
        vector<int> dist(nodes + 1, INT_MAX);
        set<pair<int, int>> st;
        st.insert({0, src});
        dist[src] = 0;
        while (!st.empty())
        {
            auto top = *(st.begin());
            st.erase(st.begin());

            int topNode = top.second;
            int topNodeDist = top.first;
            // Travel to nbrs
            for (auto nbr : this->nbrs[topNode])
            {
                int nbrNode = nbr.first;
                int nbrNodeDist = nbr.second;
                if (dist[topNode] + nbrNodeDist < dist[nbrNode])
                {
                    // 2 Kam krne hai
                    // 1 set ko update krna hai
                    auto res = st.find({dist[nbrNode], nbrNode});
                    if (res != st.end())
                    {
                        st.erase(res);
                    }
                    // 2 dist array ko update krna hai
                    dist[nbrNode] = dist[topNode] + nbrNodeDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        cout << endl;
        for (auto ds : dist)
        {
            cout << ds << " ,";
        }
    }
};
int main()
{
    system("cls");
    Graph g;
    g.addEdge(0, 5, 9, 0);
    g.addEdge(0, 3, 6, 0);
    g.addEdge(5, 4, 2, 0);
    g.addEdge(5, 1, 14, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(3, 2, 15, 0);
    g.addEdge(4, 1, 9, 0);
    g.addEdge(4, 2, 10, 0);
    g.addEdge(1, 2, 7, 0);
    g.printNbrs(6);
    g.shortestDistanceDijkstra(0, 6);

    return 0;
}