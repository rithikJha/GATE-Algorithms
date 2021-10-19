#include <bits/stdc++.h>
using namespace std;

enum nature
{
    directed,
    undirected
};
enum status
{
    unvisited,
    visiting,
    visited
};

struct gNode
{
    int nodeNum;
    int weight;
};

class Graph
{
    vector<list<gNode>> adjList;
    int numVertices;
    int numEdges;
    nature n;
    vector<int> pred;
    vector<status> stat;
    vector<int> discovery;
    vector<int> finish;

public:
    Graph(int nVertices, nature nat) : adjList(nVertices),
                                       numVertices(nVertices), numEdges(0), n(nat),
                                       pred(nVertices, -1), stat(nVertices, unvisited),
                                       discovery(nVertices, -1), finish(nVertices, -1) {}

    void addEdge(int from, int to, int weight = 1)
    {
        adjList[from].push_back({to, weight});
        if (n == undirected)
            adjList[to].push_back({from, weight});
    }

    void display()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << "->";
            for (auto j : adjList[i])
            {
                cout << j.nodeNum << ",";
            }
            cout << endl;
        }
    }
    void DFS_visit(int node, int &time)
    {
        time++;
        discovery[node] = time;
        stat[node] = visiting;
        cout << node << ", ";
        for (auto nbr : adjList[node])
        {
            if (stat[nbr.nodeNum] == unvisited)
            {
                pred[nbr.nodeNum] = node;
                DFS_visit(nbr.nodeNum, time);
            }
        }
        time++;
        finish[node] = time;
        stat[node] = visited;
    }

    void dfs()
    {
        fill_n(pred.begin(), numVertices, -1);
        fill_n(stat.begin(), numVertices, unvisited);
        fill_n(discovery.begin(), numVertices, -1);
        fill_n(finish.begin(), numVertices, -1);
        int time = 0;
        for (int i = 0; i < numVertices; i++)
        {
            if (stat[i] == unvisited)
                DFS_visit(i, time);
        }
    }
    void bfs()
    {
        queue<int> helper;
        
        fill_n(pred.begin(), numVertices, -1);
        fill_n(stat.begin(), numVertices, unvisited);
        fill_n(discovery.begin(), numVertices, -1);
        fill_n(finish.begin(), numVertices, -1);
        int time = 0;
        for (int i = 0; i < numVertices; i++)
        {
            if (stat[i] == unvisited)
                DFS_visit(i, time);
        }
    }
};

int main()
{
    Graph g(4, directed);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 0);
    g.addEdge(3, 2);
    g.addEdge(3, 1);
    g.dfs();
}