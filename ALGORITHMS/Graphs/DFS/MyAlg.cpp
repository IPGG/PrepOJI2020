#include <bits/stdc++.h>
#define dim 100
using namespace std;
ifstream fin ("Datas.in");

vector<int> Graph[dim];
int n, m;
vector<bool> vizitate;

void Read()
{
	fin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		fin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
}

void DFS (int node)
{
	vizitate[node] = true;
	cout << node << ' ';
	for (int i = 0; i < Graph[node].size(); i++)
		if (!vizitate[Graph[node][i]]) DFS(Graph[node][i]);
}

int main()
{
	Read();
	vizitate.assign(n + 1, false);
	DFS(1);
	return 0;
}
