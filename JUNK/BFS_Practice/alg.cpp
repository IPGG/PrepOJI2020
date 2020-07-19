#include <bits/stdc++.h>
using namespace std;
ifstream fin ("data.in");
vector <int> Graf[101];
int n, m;

void addEdge(int a, int b)
{
    Graf[a].push_back(b);
    Graf[b].push_back(a);
}

void BFS (int Node)
{
    queue <int> coada;
    coada.push(Node);
    vector <bool> vizitat;
    vizitat.assign (n + 1, false);
    vizitat[Node] = true;
    while (!coada.empty())
    {
        int first = coada.front();
        coada.pop();
        cout << first << ' ';
        for (int i = 0; i < Graf[first].size(); i++)
            if (!vizitat[Graf[first][i]])
            {
                coada.push(Graf[first][i]);
                vizitat[Graf[first][i]] = true;
            }

    }
}

int main ()
{
    fin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        fin >>a >> b;
        addEdge(a, b);
    }
    cout << "BFS : "; BFS(1);
    return 0;
}
