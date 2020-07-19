#include <bits/stdc++.h>
using namespace std;
ifstream fin ("data.in");
vector<int> sir;
int n;

int binarySearch(int Target)
{
	int l, r, mid;
	l = 0; r = sir. size() - 1;
	mid = (l + r) / 2;
	while (l != r)
	{
		if (sir[mid] == Target) return mid;
		else if (sir[mid] > Target)
		{
			r = mid - 1; mid = (l + r) / 2;
		} else
		{
			l = mid + 1; mid = (l + r) / 2;
		}
	}
	return mid;
}

int main ()
{
    fin >> n ;
    for (int i = 1; i <= n; i++)
    {
        int a;
        fin >> a;
        sir.push_back(a);
    }
    int target;
    fin >> target;
    /*vector<int>::iterator it;
    it = find (sir.begin(), sir.end(), target);
    if (it != sir.end()) cout << "element found in sir :" << *it << '\n';
    else cout << "Element not found!";*/
    sort (sir.begin(), sir.end());
    for (int i = 0; i < sir.size(); i++)
        cout << sir[i] << ' ';
    cout << '\n';
    /*if (binary_search(sir.begin(), sir.end(), target)) cout << "DA";
    else cout << "NU";*/
    cout << binarySearch(target);
    return 0;
}
