#include <bits/stdc++.h>
using namespace std;
ifstream fin ("Data.in");

vector <vector <int> > Graf, Componente;
vector <bool> vizitate;
int n, m, CurrentIndex = 0;

void AddEdge(int a, int b) // pentru grafuri neorientate
{
	Graf[a].push_back(b);
	Graf[b].push_back(a);
}

void Read()
{
	fin >> n >> m;
	vizitate.assign(n + 1, false);
	Graf.assign(n + 1, vector<int>());// foarte important de folosit assign pentru ambi vectori de vectori
	Componente.assign(n + 1, vector<int>());
	for (int i = 0; i < m; i++)
	{
		int a, b;
		fin >> a >> b;
		AddEdge(a, b);
	}
}

void DFS (int nod)
{
	Componente[CurrentIndex].push_back(nod); // punem in coada in care stocam Componentele nodul de apel
	for (int i = 0; i < Graf[nod].size(); i++) // algoritmul clasic de DFS
		if (!vizitate[Graf[nod][i]])
		{
			vizitate[Graf[nod][i]] = true;
			DFS(Graf[nod][i]);
		}
}

void ComponenteConexe () // avem nevoie de o simpla parcurgere pentru ca graful nu este intotdeauna conex
{
	for (int i = 1; i <= n; i++)
		if (!vizitate[i])
		{
			CurrentIndex++;
			vizitate[i] = true; // marcam nodul de start pentru DFS ca vizitat
			DFS(i);
		}
}

void Write() // afisam componentele conexe ale grafului dat
{
	for (int i = 1; i <= CurrentIndex; i++)
	{
		for (int j = 0; j < Componente[i].size(); j++)
			cout << Componente[i][j] << ' ';
		cout << '\n';
	}
}

int main()
{
	Read();
	ComponenteConexe();
	Write();
	return 0;
}
