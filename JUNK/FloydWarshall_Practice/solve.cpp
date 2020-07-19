#include <bits/stdc++.h>
using namespace std;
ifstream fin ("data.in");
#define INF 999

void printMatrix(int A[5][5], int n);

void FloydWarshall (int Graf[5][5], int dim)
{
    int DP[5][5], i, j, k;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            DP[i][j] = Graf[i][j];
    for (k = 0; k < dim; k++)
        for (i = 0; i < dim; i++)
            for (j = 0; j < dim; j++)
            {
                if (DP[i][k] + DP[k][j] < DP[i][j]) DP[i][j] = DP[i][k] + DP[k][j];
            }
    printMatrix(DP, dim);
}

void printMatrix(int A[][5], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == INF) cout << "INF ";
            else cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main ()
{
    int n;
    fin >> n;
    int Graf[5][5];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> Graf[i][j];
    FloydWarshall (Graf, n);
    return 0;
}
