#include <bits/stdc++.h>
/*#include <algorithm>
#include <vector>
#include <iostream>*/
using namespace std;
int BinarySearch(const vector <int> &arr, int l, int r, int q)
{
    while (l <= r)
    {
        int mid = l + (r-l)/2;
        if (arr[mid] == q) return mid;

        if (q < arr[mid]) { r = mid - 1; }
        else              { l = mid + 1; }
    }
    return -1;
}

int main()
{
    int query, arr[100], n;
    cout << "Introduce-ti nr elementelor din sir ";cin >> n;
    cout << "Introduce-ti sirul ";
    for (int i = 0; i < n; i++)
    	cin >> arr[i];
    vector<int> v(arr, arr + n);
    sort(v.begin(), v.end());
    cout << "Sorted array is :";
    for (int i = 0; i < n; i++)
    cout << v[i] << ' ';
    cout << '\n';
    cout << "Introduce-ti numarul cautat "; cin >> query;
    int idx;
    idx = BinarySearch(v, 0, v.size(), query);
    if (idx != -1)
        cout << "custom binary_search: found at index " << idx + 1;
    else
        cout << "custom binary_search: not found";    return 0;
}
