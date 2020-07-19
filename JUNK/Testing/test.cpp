#include <bits/stdc++.h>
using namespace std;

int main ()
{
    vector<int> sir;
    sir.push_back(1); sir.push_back(2); sir.push_back(3);
    cout << sir.capacity() << '\n';
    sir.insert (sir.begin() + 1, 10);
    for (int i = 0; i < sir.size(); i++)
        cout << sir[i] << ' ';
    cout <<'\n' << sir.max_size();
    return 0;
}
