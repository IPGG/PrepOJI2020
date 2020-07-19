#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], n, m;

void lcs()
{
    int DP[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0) DP[i][j] = 0;
            else if (a[i - 1] == b[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
            else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    cout << DP[n][m] << '\n';
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1]) {cout << a[i - 1] << ' '; i--; j--;}
        else if (DP[i - 1][j] > DP[i][j - 1]) i --;
        else j--;
    }
}

int main ()
{
    cout << "Introduceti lungimea primului sir : "; cin >> n;
    cout << "Introduceti primul sir : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Introduceti lungimea celui de-al doilea sir : "; cin >> m;
    cout << "Introduceti al doilea sir : ";
    for (int i = 0; i < m; i++)
        cin >> b[i];
    lcs();
    return 0;
}
