#include <bits/stdc++.h>	
using namespace std;
const int NMAX = 50005;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> G[NMAX];	
int dist[NMAX];

int main() 	
{
    ifstream fin("dijkstra.in");	
    ofstream fout("dijkstra.out");
    int n, m;
    fin >> n >> m;
    assert(1 <= n && n <= 50000);
    assert(1 <= m && m <= 250000);
    for (int i = 0; i < m; ++i) 
    {
        int from, to, cost;
        fin >> from >> to >> cost;
        assert(1 <= from && from <= n);
        assert(1 <= to && to <= n);
        assert(0 <= cost && cost <= 20000);
        G[from].push_back(make_pair(to, cost));
    }
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    set<pair<int, int>> h;
    h.insert(make_pair(0, 1));
    while (!h.empty()) 
    {
        int node = h.begin()->second;
        int d = h.begin()->first;
        h.erase(h.begin());
        for (vector<pair<int, int>>::iterator it = G[node].begin(); it != G[node].end(); ++it) 
        {
            int to = it->first;
            int cost = it->second;
            if (dist[to] > dist[node] + cost) 
            {
                if (dist[to] != INF) 
                {
                    h.erase(h.find(make_pair(dist[to], to)));
                }
                dist[to] = dist[node] + cost;
                h.insert(make_pair(dist[to], to));
            }
        }	
    }
    for (int i = 2; i <= n; ++i) 
    {
        if (dist[i] == INF) 
        {
            dist[i] = 0;
        }
        fout << dist[i] << ' ';
    }
    fout << '\n';
    fin.close();
    fout.close();
}