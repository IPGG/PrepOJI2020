#include <bits/stdc++.h>
using namespace std;
int a[100], n;

void LIS()
{
    int DP[n + 1];
    for (int i = 1; i <= n; i++)
        DP[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j] && DP[i] < DP[j] + 1) DP[i] = DP[j] + 1;
    int maxIndex, max = 0;
    for (int i = 1; i <= n; i++)
        if (max < DP[i])
        {
            max = DP[i];
            maxIndex = i;
        }
    int lis[max + 1];
    int currentLength = max;
    for (int i = maxIndex; i>= 1; i--)
        if (DP[i] == currentLength)
        {
            lis[currentLength] = a[i];
            currentLength--;
        }
    cout << max << '\n';
    for (int i = 1; i <= max; i++)
        cout << lis[i] << ' ';
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    LIS();
    return 0;
}
