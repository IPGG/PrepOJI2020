#include <bits/stdc++.h>
#include <tuple>	
#define pb push_back
#define mt make_tuple
#define MAXN 100010
using namespace std;
set<int> times;
vector<tuple<int, int, int> > orders; // un vector cu o structura care combina trei date de tip int
int n, d, solution[MAXN]; 

void readInput() 
{	
    ifstream fin("ramen.in");	
    int t, p;
    fin >> n >> d;
    for (int i = 0; i < n; i++) 
    {
        fin >> t >> p;
        times.insert(t);
        orders.pb(mt(p, t, i));
    }
    fin.close();	
}

void solve() 
{	
    for (int i = 0; i < n; i++) 
    {	
        int val, orderP, orderT, orderInd;
        set<int>::iterator ind; // aici avem un set de date de tip int
        orderP = get<0>(orders[i]);
        orderT = get<1>(orders[i]);
        orderInd = get<2>(orders[i]);
        val = orderT - orderP - d;
        ind = times.lower_bound(val);
        solution[orderInd] = *ind + orderP + d;
        times.erase(ind);
    }	
}

void printSolution() 	
{
    ofstream fout("ramen.out");	
    for (int i = 0; i < n; i++)
        fout << solution[i] << "\n";
    fout.close();	
}

int main()	
{
    readInput();
    sort(orders.begin(), orders.end());//sortam comenzile primite de la clienti pentru a putea stabilii secunda la care ajung 
    solve();
    printSolution();
    return 0;	
}