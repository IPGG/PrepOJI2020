#include <bits/stdc++.h>
using namespace std;
int A[100], B[100], n, m;

void lcs()
{
    int L[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (A[i - 1] == B[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    cout << L[n][m] << '\n';
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            cout << A[i - 1];
            i--;j--;
        } else if (L[i - 1][j] > L[i][j - 1]) i--;
        else j--;
    }
}

int main ()
{
    cin >> n;
    cout << "Introduceti primul sir : ";
    for (int i = 0; i < n; i++)
        cin  >> A[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> B[i];
    lcs();
    return 0;
}
