#include <bits/stdc++.h>
#define dim 105
using namespace std;
ifstream fin ("conexidad.in"); ofstream fout ("conexidad.out");

vector <int> graph[dim], Componente[dim], Izolate;
vector <pair <int, int> > muchiiAdaugate;
int n, m, Conex, Conex1, extra[dim], vizitate[dim], Max;

void Read()
{
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void DFSUtil (int node)
{
    Componente[Conex].push_back(node);
    for (int i = 0; i < graph[node].size(); i++)
        if (!vizitate[graph[node][i]])
        {
            vizitate[graph[node][i]] = 1;
            DFSUtil (graph[node][i]);
        }
}

void ComponenteConexe ()
{
    for (int i = 1; i <= n; i++)
        if (!vizitate[i] && graph[i].size() != 0)
        {
            Conex++;
            DFSUtil(i);
        } else if (!vizitate[i])
        {
            Conex1++;
            vizitate[i] = 2;
            Izolate.push_back (i);
        }
}

void Write()
{
    Max = 1;
    for (int i = 1; i < Conex; i++) // legatura componentelor conexe care au 
    {// mai mult de un nod este destul de simplu de realizat si valoarea lui Max nu
        muchiiAdaugate.push_back({Componente[i][0], Componente[i+1][1]}); // e > 2
        extra[Componente[i][0]]++;
        extra[Componente[i+1][1]]++;
    }
    int i;
    int ok;
    for (i = 0; i < Conex1; i++)
    {
        int k = Izolate[i];
        ok = 0;
        for (int j = 1; j <= n; j++)
            if (extra[j] == 0 && vizitate[j] != 2 && j != k)
            {
                extra[j]++;
                extra[k]++;
                ok = 1;
                Max = max(Max, extra[j]);
                muchiiAdaugate.push_back({j, k});
                break;
            }
        if (ok == 0) break;
    }
    if (ok == 0)
    {
        for (i = i; i < Conex1; i++)
        {
            int k = Izolate[i];
            if (extra[k] == 0)
            {
                for (int j = 1; j <= n; j++)
                    if (extra[j] < 2 && k != j)
                    {
                        extra[j]++;
                        extra[k]++;
                        Max = max(Max, extra[j]);
                        muchiiAdaugate.push_back({k, j});
                        break;
                    }
            }
        }
    }
    fout << Max << '\n' << Conex1 + Conex  - 1 << '\n';
    for (i = 0 ; i < muchiiAdaugate.size(); ++i)
        fout << muchiiAdaugate[i].first << ' '
             << muchiiAdaugate[i].second << '\n';
}

int main()
{
    Read();
    ComponenteConexe();
    Write();
    return 0;
}
