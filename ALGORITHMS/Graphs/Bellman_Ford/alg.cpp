/*
    Bellman-Ford with an Adjacency List
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

typedef vector< std::vector< std::pair<int,int> > > adj_list;

void bellman(const int start, const adj_list& graph, std::vector<int>& distances);

int main() {
    int n,m;
    cin >> n >> m;

    // adj-list using vector of size n holding a vector for
    // each vertex.
    adj_list graph(n);

    int f,s,w; // first, second, weight
    for (int i = 0; i < m; i++) {
        cin >> f >> s >> w;
        graph[f-1].push_back( make_pair(s-1,w) );
    }

    int start;
    cin >> start;

    vector<int> distances(n /* n = graph.size() */, numeric_limits<int>::max());
    bellman(start - 1, graph, distances);

    // print out the distances here
    for (int i = 0; i < n; i++)
    	cout << "The distance from " << start << " to "
    		<< i+1 << " is " << distances[i] << ".\n";

    return 0;
}

void bellman(const int start, const adj_list& graph, vector<int>& distances) {
	// setting to infinity is done in main;
	distances[start] = 0;

	// for later.
	vector<int> pred(graph.size());

	// visit every node
	// start with `start`
	// keep track of predecessors

	// do it V-1 times
	bool changes_made = true;
	for (int i = 1, n = graph.size(); i < n && changes_made; i++) {

		changes_made = false;

		// go through each node
		for (int j = 0; j < n; j++) {
			if (distances[j] == numeric_limits<int>::max())
				continue; // skip if we don't know how to reach a node yet.

			// go through a node's neighbors
			for (auto& neighbor : graph[j]) {
				if (distances[neighbor.first] > distances[j] + neighbor.second) {
					distances[neighbor.first] = distances[j] + neighbor.second;
					pred[neighbor.first] = j;
					changes_made = true;
				}
			}
		}
	}

	// now we do it one more time to find any negative cycles
	for (int i = 0, n = graph.size(); i < n; i++) {
		if (distances[i] == numeric_limits<int>::max())
			continue; // skip if we don't know how to reach a node yet.

		// go through a node's neighbors
		for (auto& neighbor : graph[i]) {
			if (distances[neighbor.first] > distances[i] + neighbor.second)
				cout << "Found negative cycle from " << i << " to " << neighbor.first << ".\n";
		}
	}
}
