// problema https://www.infoarena.ro/problema/bfs
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("bfs.in"); ofstream fout ("bfs.out");
#define maxn 100010
int n,m,l,Start;
vector <int> a[maxn];
int g[maxn], s[maxn], Cost[maxn];

void BFS(int nod) // parametrul intreg nod este varful din care plecam.
{
    int i,j;
    memset(Cost, -1, sizeof(Cost)); //	Marchez toate nodurile ca fiind nevizitat
    //	Introduc nodul de start in coada
    l = 1;
    Cost[nod] = 0;
    s[l] = nod;
    for (i = 1; i <= l; i++) //	Elimin pe rand nodurile din coada
        for (j = 0; j < g[s[i]]; j++) // Parcurg vecinii nodului ce urmeaza sa fie eliminat
        {

            if (Cost[a[s[i]][j]] == -1) //	Adaug vecinii nevizitati in coada si le calculez distanta
            {
                s[++l] = a[s[i]][j];
                Cost[s[l]] = Cost[s[i]] + 1;
            }

        }
}

int main()
{
    int i, x, y;
    fin >> n >> m >> Start;
    for (i = 1; i <= m; i++)
    {
        fin >> x >> y;
        a[x].push_back(y);
    }
    for (i = 1; i <= n; i++)
        g[i] = a[i].size();
    BFS(Start);
    for (i = 1; i <= n; i++)
        fout << Cost[i] << ' ';
    fout << '\n';
    return 0;
}
