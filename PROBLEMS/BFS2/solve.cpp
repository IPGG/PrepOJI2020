#include <bits/stdc++.h>
using namespace std;
ifstream fin ("bfs2.in"); ofstream fout("bfs2.out");
const int N_MAX = 100001;
const int F = 1;
const int B = 0;
int D[2], Q, lim;
int isnotgood;
int per[2][N_MAX];
bool bad[2][N_MAX];
long long s[2][N_MAX];

void update (int sex, int opositeSex, int pos1)
{
	int pos2 = upper_bound(s[opositeSex]+1, s[opositeSex]+D[opositeSex]+1, s[sex][pos1-1]+lim)-s[opositeSex]-1;
	if (s[sex][pos1] - s[opositeSex][pos2] > lim)
	{
		isnotgood += (!bad[sex][pos1]);
		bad[sex][pos1] = bad[opositeSex][pos2] = true;
		per[sex][pos1] = pos2;
		per[opositeSex][pos2] = pos1;
	} else
	{
		isnotgood -= bad[sex][pos1];
		bad[sex][pos1] = bad[opositeSex][per[sex][pos1]] = false;
	}
}

int main ()
{
	fin >> D[B] >> D[F] >> lim;
	for (int i = 1; i <= D[B]; i++)
	{
		fin >> s[B][i];
		s[B][i] += s[B][i - 1];
	}
	for (int i = 1; i <= D[F]; i++)
	{
		fin >> s[F][i];
		s[F][i] += s[F][i - 1];
	}

	fin >> Q;
	char sex, opositeSex;
	int pos1, pos2;
	while (Q--)
	{
		fin >> sex >> pos1 >> pos2;
		if (sex == 'F') sex = F, opositeSex = B;
		else sex = B, opositeSex = F;
		if (pos1 > pos2) --pos1;
		s[sex][pos1] += (s[sex][pos1 + 1] - s[sex][pos1]) - (s[sex][pos1] - s[sex][pos1 - 1]);
		update(sex, opositeSex, pos1);
		update(sex, opositeSex, pos1 + 1);
		fout << (!isnotgood) << '\n';
	}
    return 0;
}
