#include <bits/stdc++.h>
using namespace std;
ifstream fin ("grade.in"); ofstream fout ("grade.out");
vector <int> Graf[101];
int n;

void AddEdge(int a, int b)
{
    Graf[a].push_back(b);
    Graf[b].push_back(a);
}

void Read()
{
    fin >> n;
    while (!fin.eof())
    {
        int a, b;
        fin >> a >> b;
        cout << a << ' ' << b << '\n';
        AddEdge(a, b);
    }
}

void Degrees()
{
	for (int i = 1; i <= n; i++)
    {
        fout << Graf[i].size() << ' ';
    }
}

int main()
{
	Read();
	Degrees();
    return 0;
}
