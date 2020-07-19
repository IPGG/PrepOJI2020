#include <bits/stdc++.h>
using namespace std;
ifstream fin ("graf.in");
int n, m;
vector < pair <int, int> > Graf[100];

int main()
{
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        fin >> a >> b >> cost;
        Graf[a - 1]. push_back(make_pair (b - 1, cost));
    }
    int source = 0;
    priority_queue <pair <int,int>, vector < pair <int,int> >, greater < pair <int,int> > > PQ;
    vector <int> distTO (n, INT_MAX);
    distTO[source] = 0;
    PQ.push (make_pair(0, source));
    while (!PQ.empty())
    {
        int dist = PQ.top().first;
        int prev = PQ.top().second;
        PQ.pop();
        vector< pair <int, int> >::iterator it;
        for (it = Graf[prev].begin(); it != Graf[prev].end(); it++)
        {
            int next = it -> first;
            int nextDist = it -> second;
            if (distTO[next] > distTO[prev] + nextDist)
            {
                distTO[next] = distTO[prev] + nextDist;
                PQ.push(make_pair (distTO[next], next));
            }
        }
    }
    cout << "Distantele de la 4 sunt : ";
    for (int i = 0 ; i < n; i++)
        if (distTO[i] == INT_MAX) cout <<"INF "; else cout << distTO[i] << ' ';
    return 0;
}
