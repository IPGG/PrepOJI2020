#include<bits/stdc++.h>
using namespace std;
ifstream fin ("graph.in");

int main()
{
	int n, m, source;
	fin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// lista de adiacenta cu tot cu costul muchiilor
	int a, b, cost;
	for(int i = 0; i<m ; i++)
    {
		fin >> a >> b >> cost;
		g[a].push_back(make_pair(b, cost));
	}
	fin >> source;

	// algoritmul lui Dijkstra
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths;

	distTo[source] = 0; // distanta la nodul sursa este 0
	pq.push(make_pair(0,source));	// (dist,from)
	while( !pq.empty() )
    {
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++)
        {
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist)
			{
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	return 0;
}
