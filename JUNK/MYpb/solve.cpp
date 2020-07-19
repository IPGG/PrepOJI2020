#include <bits/stdc++.h>
using namespace std;
int n, a[100];

void LIS(int (&lis)[100], int &lis_length)
{
    int mm[n];
    for (int i = 1; i <= n; i++)
        mm[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j] && mm[i] < mm[j] + 1) mm[i] = mm[j] + 1;
    int maxIndex = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << mm[i] << ' ';
        if (mm[i] > lis_length)
        {
            lis_length = mm[i];
            maxIndex = i;
        }
    }
    cout << '\n';
    int currentLength = lis_length;
    for (int i = maxIndex; i >= 1; i--)
        if (mm[i] == currentLength) {lis[currentLength] = a[i]; currentLength--;}
}

void BinarySearch(int t, int lungime, int sir[])
{
    int l = 1, r = lungime;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (sir[mid] == t) cout << mid << ' '<< t;
        if (sir[mid] > t) r = mid - 1; else l = mid + 1;
    }
}

int main ()
{
    cout << "Length of first aray : "; cin >> n;
    cout << "The first array : ";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int lis[100], lis_length = 0;
    LIS(lis, lis_length);
    cout << lis_length << '\n';
    for (int i = 1; i <= lis_length; i++)
        cout << lis[i] << ' ';
    int target;
    cin >> target;
    BinarySearch (target, lis_length, lis);
    return 0;
}
