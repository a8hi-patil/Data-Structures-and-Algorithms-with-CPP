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

    void shortestBellmanFord(int src, int nodes)
    {
        vector<int> dist(nodes, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < nodes - 1; i++)
        {
            for (auto childs : this->nbrs)
            {
                // childs list<pair<int, int>>
                int u = childs.first;
                for (auto nbr : childs.second)
                {
                    // nbr pair<int, int>
                    int v = nbr.first;
                    int w = nbr.second;
                    if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        bool isNegativeCycle = false;
        for (auto childs : this->nbrs)
        {
            // childs list<pair<int, int>>
            int u = childs.first;
            for (auto nbr : childs.second)
            {
                // nbr pair<int, int>
                int v = nbr.first;
                int w = nbr.second;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        if (isNegativeCycle)
        {
            cout << "Negative Cycle Present ";
            return;
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
    g.addEdge(0, 1, -1, 1);
    g.addEdge(1, 4, 2, 1);
    g.addEdge(0, 2, 4, 1);
    g.addEdge(3, 2, 5, 1);
    g.addEdge(4, 3, -3, 1);
    g.addEdge(1, 2, 3, 1);
    g.addEdge(1, 3, 2, 1);
    g.addEdge(3, 1, 1, 1);

    g.printNbrs(6);
    g.shortestDistanceDijkstra(0, 5);

    return 0;
}