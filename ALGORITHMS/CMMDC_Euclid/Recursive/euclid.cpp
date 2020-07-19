#include <fstream>	
using namespace std;
ifstream fin  ("euclid2.in");	
ofstream fout ("euclid2.out");
int n,a,b;
int cmmdc(int a, int b)
{
    if (!b) return a;	
    return cmmdc(b, a % b);
}	
int main (void)	
{
    fin >> n;	
    for ( ; n; n--)
    {
        fin >> a >> b;
        fout << cmmdc(a,b) << "\n";
    }
    return 0;
}