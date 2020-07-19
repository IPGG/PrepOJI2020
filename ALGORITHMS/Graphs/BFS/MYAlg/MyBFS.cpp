#include <bits/stdc++.h>
using namespace std;
ifstream fin ("Datas.in");
vector<bool> vizitat;
vector<vector<int> > Graf;

void AddEdge(int a, int b)
{
	Graf[a].push_back(b);
    Graf[b].push_back(a);
}

void BFS(int u)
{
	queue<int> coada;
	coada.push(u); // primul pas este sa punem nodul de start in coada
	vizitat[u] = true; // si sa il marcam ca vizitat
	while (!coada.empty())
	{
		int f = coada.front();
		coada.pop();
		cout << f << " "; // f este nodul din fata al cozii, cel care se af
		vector <int>::iterator i; // pentru a parcurge acest vector avem nevoie
		for (i = Graf[f].begin(); i != Graf[f].end(); i++) // de un iterator special
		{	// aici punem toate adiacentele nodului curent in coada
			if (!vizitat[*i])
			{
				coada.push(*i);
				vizitat[*i] = true; // si le marcam ca si vizitate
			}
		}
	}
}

int main()
{
	int n, e;
	fin >> n >> e;
	vizitat.assign(n + 1, false);
	Graf.assign(n + 1, vector<int>());
	for (int i = 0; i < e; i++)
	{
		int a, b;
		fin >> a >> b;
		AddEdge(a, b);
	}
	BFS (2);
	return 0;
}
