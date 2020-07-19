#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("bfs2.in"); ofstream out("bfs2.out");	
const int N_MAX = 100001;
const int F = 1;
const int B = 0;
int D[2], Q, lim;
int isnotgood;
int per[2][N_MAX];
bool bad[2][N_MAX];	
long long s[2][N_MAX];
	
void update(int sex, int othersex, int pos) 
{
    int pos2 = upper_bound(s[othersex] + 1, s[othersex] + D[othersex] + 1, s[sex][pos - 1] + lim) - s[othersex] - 1;
    if(s[sex][pos] - s[othersex][pos2] > lim) 
    {
        isnotgood += (!bad[sex][pos]);
        bad[sex][pos] = bad[othersex][pos2] = true;
        per[sex][pos] = pos2;
        per[othersex][pos2] = pos;
    } else 
    {
        isnotgood -= bad[sex][pos];
        bad[sex][pos] = bad[othersex][per[sex][pos]] = false;
    }	
}
	
int main() 
{
    in >> D[B] >> D[F] >> lim;
    for(int i = 1; i <= D[B]; ++i) 
    {
        in >> s[B][i];
        s[B][i] += s[B][i - 1];
    }
	
    for(int i = 1; i <= D[F]; ++i) 
    {
        in >> s[F][i];
        s[F][i] += s[F][i - 1];	
    }

    in >> Q;
    char sex, othersex;
    int pos, pos2;
    while(Q--) 
    {
        in >> sex >> pos >> pos2;
        if(sex == 'F')
            sex = F, othersex = B;
        else
            sex = B, othersex = F;
        if(pos > pos2)
            --pos;
        s[sex][pos] += (s[sex][pos + 1] - s[sex][pos]) - (s[sex][pos] - s[sex][pos - 1]);
        update(sex, othersex, pos);
        update(sex, othersex, pos + 1);
        out << (!isnotgood) << '\n';
    }
    return 0;	
}