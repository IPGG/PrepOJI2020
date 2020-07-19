#include <bits/stdc++.h>
using namespace std;
ifstream fin ("gradmax.in"); ofstream fout ("gradmax.out");

int main()
{
    int n;
    fin >> n;
    int adiacenta[n+1][n+1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adiacenta[i][j] = 0;
    while (!fin.eof())
    {
        int a, b;
        fin >> a >> b;
        if (adiacenta[a][b]== 0) {adiacenta[a][b] = 1; adiacenta[b][a] = 1;}
    }
    for (int i = 1; i <= n; i++)
    {
        int grad_curent = 0;
        for (int j = 1; j <= n; j++)
            if (adiacenta[i][j] == 1) grad_curent++;
        adiacenta[1][i] = grad_curent;
    }
    int max = 0, Max_pos = 1;
    vector <int> solution;
    for (int i = 1; i <= n; i++)
    if (adiacenta[1][i] > max) {max = adiacenta[1][i]; Max_pos = i;}
    solution.push_back(Max_pos);
    for (int i = Max_pos + 1; i <= n; i++)
        if (adiacenta[1][i] == max) solution.push_back(i);
    fout << solution.size() << ' ';
    for (int i = 0; i < solution.size(); i++)
        fout << solution[i] << ' ';
    return 0;
}
