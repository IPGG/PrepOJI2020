#include <bits/stdc++.h>
using namespace std;
ifstream fin ("data.in");
vector <int> Graf[101];
vector <bool> vizitate;
int n, m;

void addEdge(int a, int b)
{
    Graf[a].push_back(b);
    Graf[b].push_back(a);
}

void DFS (int Node)
{
    vizitate[Node] = true;
    cout << Node << ' ';
    for (int i = 0; i < Graf[Node].size(); i++)
    {
        if (!vizitate[Graf[Node][i]]) DFS (Graf[Node][i]);
    }
}

int main ()
{
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >>b;
        addEdge(a, b);
    }
    vizitate.assign (n + 1, false);
    cout << "DFS from root 1 : ";DFS(1); cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < Graf[i].size(); j++)
            cout << Graf[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
