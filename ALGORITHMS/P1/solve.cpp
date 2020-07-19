#include <bits/stdc++.h>
using namespace std;
int n, a[100], m, b[100];

void LCS(int (&secventa)[100], int &lungime)
{
    int D[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0) D[i][j] = 0;
            else if (a[i - 1] == b[j - 1]) D[i][j] = D[i - 1][j - 1] + 1;
            else D[i][j] = max (D[i - 1][j], D[i][j - 1]);
        }
    lungime = D[n][m];
    int currentLength = lungime;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j]) {secventa[currentLength] = a[i]; i--; j--; currentLength--;}
        else if (D[i-1][j] > D[i][j - 1]) i--; else j--;
    }
}

int main ()
{
    cout << "Nr el primul sir : "; cin >> n;
    cout << "El primului sir : ";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << "Nr el al doilea sir : "; cin >> m;
    cout << "el celui de-al doilea sir : ";
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int lcs[100]; int l = 0;
    LCS(lcs, l);
    cout << l << '\n';
    for (int i = 1; i <= l; i++)
        cout << lcs[i] << ' ';
    cout << '\n';
    for (int i = 2; i <= l; i++)
        for (int j = 1; j < i; j++)
            if (lcs[i] < lcs[j]) {int aux = lcs[i]; lcs[i] = lcs[j]; lcs[j] = aux;}
    for (int i = 1; i <= l; i++)
        cout << lcs [i] << ' ';
    return 0;
}
