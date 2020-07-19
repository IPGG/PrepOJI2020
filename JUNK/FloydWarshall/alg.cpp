#include <bits/stdc++.h>
using namespace std;
#define INF 9999
int Graf[100][100];
int n, m;
int paths[100][100];

void printPath(int i, int j);

void FloydWarshall()
{
    int aux[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
       for (int j = 1;j <= m; j++)
           aux[i][j] = Graf[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++ )
            if (i == j) paths[i][j] = 0; else paths[i][j] = j + 1;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (aux[i][k] + aux[k][j] < aux[i][j]) {aux[i][j] = aux[i][k] + aux[k][j]; paths[i][j] = paths[k][j];}
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1;j <= n; j++)
            cout << Graf[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1;j <= n; j++)
            cout << aux[i][j] << ' ';
        cout << '\n';
    }
    printPath (1, 5);
}

void printPath(int i, int j)
{
    if (i != j) printPath(i, paths[i][j]);
    cout << j << ' ';
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1;j <= n; j++)
            Graf[i][j] = INF;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Graf[a][b] = c;
    }
    FloydWarshall();
    return 0;
}
