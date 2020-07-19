#include <bits/stdc++.h>
#define dim 105
using namespace std;
ifstream fin("conexidad.in"); ofstream fout("conexidad.out");

vector <int> graph[dim],comp[dim],nr1;
vector <pair<int, int> > muchii_adaugate;
int n,m,conex,conex1,extra[dim],viz[dim],maxx;

void Read()	
{
    fin>>n>>m;	
    for(int i=1; i<=m; ++i)
    {
        int a,b;
        fin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
	
void Dfs(int node)
{
    comp[conex].push_back(node);	
    for(int i=0; i<graph[node].size(); ++i)
        if(!viz[graph[node][i]])
        {
            viz[graph[node][i]]=1;	
            Dfs(graph[node][i]);
        }
}
	
void Comp_Conex()
{
    for(int i=1; i<=n; ++i)	
        if(!viz[i]&&graph[i].size()!=0)
        {
            ++conex;
            Dfs(i);
        }
        else if(!viz[i])
        {
            ++conex1;
            viz[i]=2;
            nr1.push_back(i);
        }
}
	
void Write()	
{
    maxx=1;	
    for(int i=1; i<conex; ++i)
    {
        muchii_adaugate.push_back({comp[i][0],comp[i+1][1]});
        extra[comp[i][0]]++;
        extra[comp[i+1][1]]++;
    }
    int i;
    int ok;
    for(i=0; i<conex1; ++i)
    {
        int k=nr1[i];
        ok=0;
        for(int j=1; j<=n; ++j)
            if(extra[j]==0&&viz[j]!=2&&j!=k)
            {
                extra[j]++;
                extra[k]++;
                ok=1;
                maxx=max(maxx,extra[j]);
                muchii_adaugate.push_back({j,k});
                break;
            }
        if(ok==0)
            break;
    }
    if(ok==0)
    {
        for(i=i; i<conex1; ++i)
        {
            int k=nr1[i];
            if(extra[k]==0)
            {
                for(int j=1; j<=n; ++j)
                    if(extra[j]<2&&k!=j)
                    {
                        extra[j]++;
                        extra[k]++;
                        maxx=max(maxx,extra[j]);
                        muchii_adaugate.push_back({k,j});
                        break;
                    }
            }
        }
    }
    fout<<maxx<<'\n'<<conex+conex1-1<<'\n';
    for(int i=0; i<muchii_adaugate.size(); ++i)
        fout<<muchii_adaugate[i].first<<" "<<muchii_adaugate[i].second<<'\n';
}

int main()	
{
    Read();	
    Comp_Conex();
    Write();
    return 0;
}