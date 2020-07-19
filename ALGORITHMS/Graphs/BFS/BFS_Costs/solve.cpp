// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices 
// reachable from s. 
#include<iostream> 
#include <list> 

using namespace std; 

// clasa pentru listele de adiacenta.
class Graph 
{ 
	int V; // numarul varfurilor
	// Pointer array pentru listele de adiacenta 
	list<int> *adj; 
public: 
	Graph(int V); // Constructor 
	// definim functia de adaugare arc in clasa Graph 
	void addEdge(int v, int w); 
	// afiseaza ruta de la un nod dat x. 
	void BFS(int s); 
}; 

// functie pentru crearea unui graf folosind clasa Graph
Graph::Graph(int V) // deoarece am creat clasa Graph folosim :: pentru a 
{					// declara o functie pentru clasa 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) // :: se foloseste pentru a crea o 
{	// functie declarata in interiorul clasei si dezvoltata dupa
	adj[v].push_back(w); //adaugam un arc de la v la w 
}

void Graph::BFS(int s) 
{ 
	// pentru inceput trebuie sa marcam toate nodurile nevizitate 
	bool *visited = new bool[V]; // folosim un pointer boolean pentru
	for(int i = 0; i < V; i++) // marcarea nodurilor vizitate
		visited[i] = false; 
	// cream o lista pentru parcurgere
	list<int> queue; 
	// notam nodul de start ca vizitat si il adaugam in coada. 
	visited[s] = true; 
	queue.push_back(s); 
	// indexul "i" va trece prin toate nodurile grafului 
	list<int>::iterator i; 
	while(!queue.empty()) // pana golim lista
	{ 
		// scoatem un nod din lista si il afisam
		s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 
		// obtinem toate nodurile adiacente lui s, iar daca este 
		// unul care nu a fost vizitat, atunci il punem in lista
		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		{ 
			if (!visited[*i]) 
			{ 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 
} 
// program de test pentru algoritm
int main() 
{  
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 
	g.BFS(2); 

	return 0; 
} 
