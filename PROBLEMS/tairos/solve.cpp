#include <bits/stdc++.h>
using namespace std;
ifstream fin ("tairos.in");
vector < vector <int> > Graf;
int n, d, nivele[10001];

struct frunze
{
	int poz, nr;
} frunza[10001];

void AddEdge(int a , int b)
{
	Graf[a].push_back(b);
}

int main ()
{
	fin >> n;
	fin >> d;
	Graf.assign (n + 1, vector <int>());
	nivele[0] = 1;
	while (!fin.eof())
	{
		int a, b;
		fin >> a >> b;
		AddEdge (a, b);
	}
	while
	return 0;
}