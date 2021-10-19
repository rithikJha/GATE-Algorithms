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

class Graph
{
    vector<vector<int>> adjMatrix;
    int numVertices;
    int numEdges;
    nature n;
    vector<int> pred;
    vector<status> stat;
    vector<int> discovery;
    vector<int> finish;

public:
    Graph(int nVertices, nature nat) : adjMatrix(nVertices, vector<int>(nVertices, 0)), numVertices(nVertices),
                                       numEdges(0), n(nat), pred(nVertices, INT_MIN), stat(nVertices, unvisited),
                                       discovery(nVertices, -1), finish(nVertices, -1) {}

    void addEdge(int from, int to, int weight = 1)
    {
        adjMatrix[from][to] = weight;
        if (n == undirected)
            adjMatrix[to][from] = weight;
    }

    void display()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << "-> ";
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] != 0)
                    cout << j << ", ";
            }
            cout << endl;
        }
    }
    void dfs()
    {
        fill_n(stat.begin(), numVertices, unvisited);
        fill_n(pred.begin(), numVertices, INT_MIN);
        int time = 0;
        for (int i = 0; i < numVertices; i++)
        {
            if (stat[i] == unvisited)
                dfs_visit(i, time);
        }
    }

    void dfs_visit(int node, int &time)
    {
        time++;
        discovery[node] = time;
        cout << node << ", ";
        stat[node] = visiting;
        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[node][i] != 0)
            {
                if (stat[i] == unvisited)
                {
                    pred[i] = node;
                    dfs_visit(i, time);
                }
            }
        }
        stat[node] = visited;
        time++;
        finish[node] = time;
    }

    void bfs(int start)
    {
        queue<int> helper;
        int dist_from_start[numVertices];
        fill_n(stat.begin(), numVertices, unvisited);
        fill_n(dist_from_start, numVertices, INT_MAX);
        fill_n(pred.begin(), numVertices, INT_MIN);

        stat[start] = visiting;
        dist_from_start[start] = 0;
        pred[start] = start;

        helper.push(start);

        while (helper.size() != 0)
        {
            int currNode = helper.front();
            helper.pop();

            cout << "[n=" << currNode << ", dist=" << dist_from_start[currNode]
                 << ", pred=" << pred[currNode] << "], ";
            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[currNode][i] != 0)
                    if (stat[i] == unvisited)
                    {
                        stat[i] = visiting; // pushed in queue
                        dist_from_start[i] = dist_from_start[currNode] + 1;
                        pred[i] = currNode;
                        helper.push(i);
                    }
            }
            stat[currNode] = visited; //all children processed
        }
    }
};

int main()
{
    Graph g(8, undirected);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 7);
    //g.addEdge(3, 5);
    //g.addEdge(3, 6);
    g.dfs();
    cout << endl;
    g.display();
}