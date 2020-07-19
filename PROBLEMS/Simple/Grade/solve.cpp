#include <bits/stdc++.h>
using namespace std;
ifstream fin ("Data.in");
vector <vector <int> > Graf;
vector <int> Grade;
int n, m;

void AddEdge(int a, int b)
{
    Graf[a].push_back(b);
    Graf[b].push_back(a);
}

void Read()
{
    fin >> n >> m;
    Graf.assign (n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
        AddEdge(a, b);
    }
}

void Degree()
{
    Grade.assign (n + 1, 0);
    for (int i = 1; i <= n; i++)
        Grade[i] = Graf[i].size();
}

void Afisare()
{
    for (int i = 1; i <= n; i++)
        cout << Grade[i] << ' ';
}

int main ()
{
    Read();
    Degree();
    Afisare();
    return 0;
}
