#include <bits/stdc++.h>
using namespace std;
ifstream fin ("galeti2.in"); ofstream fout ("galeti2.out");	
long long e, cre; int n, i, j, ind, st, a[100001];

int main ()	
{
	fin >> n >> e; // nr de galeti si efortul care trebuie depus pentru a obtine rezultatul dorit
	cre = (1LL * (n - 1) * n) / 2;
	for (i = 1; i <= n ; i++)
		a[i] = i - 1;
	for (i = n; i >= 1; i--)
	{
		if (cre - (a[i] - 1) > e)
		{
			cre -= (a[i] - 1);
			a[i] = 1;
		}
		else
		{
			a[i] = a[i] - (cre - e);
			if (cre == e)
				ind = i + 1;
			else
				ind = i;
			break;
		}
	}
	ind = max (ind, 2);
	st = ind;
	for (i = ind; i <= n; i++)
	{
		for (j = st - 1; j > a[i]; j--)
			fout << j << " " << j - 1 << '\n';
		st = a[i] + 1;
		fout << i << " " <<a[i] << '\n';
	}
	for (i = st - 1; i > 1; i--)
		fout << i << " " << i - 1 << '\n';
	fin.close();
	fout.close();
	return 0;	
}