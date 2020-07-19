#include <bits/stdc++.h>
using namespace std;
ifstream fin ("datas.in");
vector <int> Graf[100];
int n, m;

void AddEdge(int a, int b)
{
    Graf[a].push_back(b);
    Graf[b].push_back(a);
}

bool BFS(int src, int dest, int pred[], int dist[])
{
    queue <int> coada;
    vector <bool> visited;
    visited.assign (n + 1, false);
    for (int i = 0; i < n; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}
    visited[src] = true;
    dist[src] = 0;
    coada.push (src);
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
                if (Graf[f][i] == dest) return true;
            }
    }
    return false;
}

void printShortestDistance (int s, int dest)
{
    int pred[n + 1], dist[n + 1];
    if (!BFS(s, dest, pred, dist)){cout << "Cele doua noduri nu sunt conexe"; return;}

    vector <int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl]!= -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    cout << "Shortest path length: " << dist[dest];
    cout << "\nPath is : ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';
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
    int sursa = 1, dest = 4;
    printShortestDistance (sursa, dest);
    return 0;
}
