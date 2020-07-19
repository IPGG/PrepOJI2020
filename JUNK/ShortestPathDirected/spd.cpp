#include <bits/stdc++.h>
using namespace std;
ifstream fin ("graf.in");
int n, m;
vector<int> Graf[100];

void AddEdge(int a, int b)
{
    Graf[a].push_back(b);
}

bool BFS(int s, int d, int pred[], int dist[])
{
    queue<int> coada;
    vector <bool> visited;
    visited.assign (n + 1, false);
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    coada.push(s);
    dist[s] = 0;
    visited[s] = true;
    while (!coada.empty())
    {
        int f = coada.front();
        coada.pop();
        for (int i = 0; i < Graf[f].size(); i++)
            if (!visited[Graf[f][i]])
            {
                visited[Graf[f][i]] = true;
                dist[Graf[f][i]] = dist[f] + 1;
                pred[Graf[f][i]] = f;
                coada.push(Graf[f][i]);
                if (Graf[f][i] == d) return true;
            }
    }
    return false;
}

void PrintShortestPath(int source, int dest)
{
    int pred[n + 1], dist[n + 1];
    if (!BFS(source, dest, pred, dist)) {cout << "Nu se poate ajunge din "<<source<<" in " << dest; return;}
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    cout << "Distanta este: "<< dist[dest] << '\n';
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i]<< ' ';
}

void PrintAdj()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < Graf[i]. size(); j++)
            cout << Graf[i][j] << ' ';
        cout << '\n';
    }
}

int main ()
{
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
        AddEdge (a, b);
    }
    PrintAdj();
    PrintShortestPath (1, 3);
    return 0;
}
