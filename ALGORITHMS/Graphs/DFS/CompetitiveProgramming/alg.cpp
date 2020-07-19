#include <bits/stdc++.h>
using namespace std;
ifstream fin ("Datas.in");
vector<vector<int> > ListeAdiacenta;
int n, m;
vector<bool> vizitate;

void DFS(int Nod)
{
	vizitate[Nod] = true;
	cout << Nod << ' ';
	for (int u = ListeAdiacenta[Nod]. begin(); u <= ListeAdiacenta[Nod].end(); u++)
		if (!vizitate[u]) DFS(u);
}

void Citeste()
{
	fin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		fin >> a >> b;
		ListeAdiacenta[a].push_back(b);
		ListeAdiacenta[b].push_back(a);
	}
}

int main ()
{
	Citeste();
	return 0;
}
