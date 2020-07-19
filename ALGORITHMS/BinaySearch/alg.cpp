#include <bits/stdc++.h>
using namespace std;
int n, a[100];

void BinarySearch (int e)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == e) {cout << mid << ' ' << a[mid]; return;}
        if (e < a[mid]) r = mid - 1;
        else l = mid + 1;
    }
}

int main ()
{
    cout << "introduceti numarul de elemente ale sirului : "; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << "Introdu valoarea care trebuie gasita : "; int target; cin >> target;
    BinarySearch(target);
    return 0;
}
