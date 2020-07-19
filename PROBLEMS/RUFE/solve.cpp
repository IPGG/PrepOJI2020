#include <bits/stdc++.h>
using namespace std;
ifstream fin ("rufe.in"); ofstream fout("rufe.out");	
long long m,n,a,b,k;

long long arie(long long lung)	
{
    if(lung < 0)
        return 0;
    return 1LL * (lung + 1) * (lung + 2) / 2;	
}

long long calculate(long long dist) /// numarul punctelor aflate la o dist >=dist	
{
    long long ans = 0;
    /// ans = numarul punctelor aflate la o dist < dist	
    --dist;

    /// cadran 1
    ans += arie(dist);
    ans -= arie(dist - (n - a + 1)); /// rombul depaseste latura de jos
    ans -= arie(dist - (m - b + 1)); /// rombul depaseste latura din dreapta	
    ans += arie(dist - (n - a + m - b + 2)); /// rombul depaseste ambele laturi

    ///cadran 2
    --dist;
    ans += arie(dist);
    ans -= arie(dist - (n - a + 1)); ///rombul depaseste latura de jos
    ans -= arie(dist - (b - 1)); /// rombul depaseste latura din stanga
    ans += arie(dist - (n - a + b)); /// rombul depaseste ambele laturi	
    ++dist;

    ///cadran 3
    --dist;
    ans += arie(dist);
    ans -= arie(dist - (a - 1)); /// rombul depaseste latura de sus
    ans -= arie(dist - (m - b + 1)); /// rombul depaseste latura din dreapta
    ans += arie(dist - (m - b + a)); /// rombul depaseste ambele laturi	
    ++dist;

    ///cadran 4
    dist -= 2;
    ans += arie(dist);
    ans -= arie(dist - (a - 1)); /// rombul depaseste latura de sus
    ans -= arie(dist - (b - 1)); /// rombul depaseste latura din stanga
    ans += arie(dist - (a + b - 2)); /// rombul depaseste ambele laturi
    return n * m - ans;
}
	
int main()	
{
    fin >> n >> m >> a >> b >> k;
    long long st = 1, dr = n + m;
    while(st <= dr)    
    {
        long long mid = (st + dr) / 2;
        long long rez = calculate(mid);
        if(rez == k)
        {
            fout << mid;
            return 0;
        }
        else if(rez > k)
            st = mid + 1;
        else
            dr = mid - 1;
    }
    fout << dr;
    return 0;
}