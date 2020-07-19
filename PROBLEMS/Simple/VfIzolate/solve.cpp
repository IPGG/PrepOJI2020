#include <bits/stdc++.h>
using namespace std;
ifstream fin("Data.in"); ofstream fout ("Data.out");

int main ()
{
    int n; // nr de noduri;
    bool AuAdiacente [101];
    fin >> n;
    while (!fin.eof())
    {
        int a, b;
        fin >> a >> b;
        AuAdiacente[a] = true; AuAdiacente[b] = true;
    }
    vector <int> result;
    for (int i = 1; i <= n; i++)
        if(AuAdiacente[i] == false) result.push_back(i);
    fout << result.size() << ' ';
    for (int i = 0; i < result.size(); i++)
        fout << result[i] << ' ';
    return 0;
}
