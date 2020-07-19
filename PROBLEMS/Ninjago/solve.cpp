#include <bits.stdc++.h>
using namespace std;	
int p;
int n,m;

struct elem	
{
  int dest, cost, hasE;	
};

struct edge	
{
  int src, dst, cost, hasE;	
};

struct Comp1: binary_function<edge,edge,bool>	
{
  bool operator() (edge e1, edge e2)
  {
    if(e1.hasE!=e2.hasE)
      return e1.hasE>e2.hasE;
    return e1.cost>e2.cost;
  }	
};

vector<elem> v[31505];
int pow5[4]={1,5,25,125};
bool vis[31505];	
int head[31505];
int siz[31505];

int getHead(int a)	
{
  while(head[a]!=a)
  {
    head[a]=head[head[a]];
    a=head[a];
  }
  return a;	
} 

bool unite(int a, int b)	
{
  int headA=getHead(a);
  int headB=getHead(b);
  if(headA!=headB)
  {
    if(siz[headA]>=siz[headB])
    {
      head[headB]=headA;
      siz[headA]+=siz[headB];
    }
    else
    {
      head[headA]=headB;
      siz[headB]+=siz[headA];
    }
    return 1;
  }
  return 0;	
}	
queue<int> s;
priority_queue<edge,vector<edge>,Comp1> q;

int main()	
{
  freopen("ninjago.in","r",stdin);
  freopen("ninjago.out","w",stdout);
  scanf("%d",&p);
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++)
  {
    int j,k;
    int cost=0;
    int hasE=0;
    char c[4];
    scanf("%d %d %s",&j,&k,c);
    for(int j=0;j<4;j++)
    {
      if(c[j]>='A'&&c[j]<='D')
        cost+=pow5[j]*(c[j]-'A'+1);
      else
        hasE++;
    }
   // printf("%d %d %s %d %d\n",j,k,c,cost,hasE);
    if(p==1 &&hasE==0)
    {
      v[j].push_back({k,cost,hasE});
      v[k].push_back({j,cost,hasE});
    }
    if(p>=2)
      q.push({j,k,cost,hasE});
  }
  if(p==1)
  {
    s.push(1);
    vis[1]=1;
    int countt=1;
    while(!s.empty())
    {
      int tp = s.front();
      s.pop();
      int maxS= v[tp].size();
      int j=0;
      for(;j<maxS;j++)
      {
        elem ele = v[tp][j];
        if(!vis[ele.dest]&&ele.hasE==0)
        {
          vis[ele.dest]=1;
          s.push(ele.dest);
          countt++;
        //  break;
        }
      }
    //  if(j==maxS)
       // s.pop();
    }
    printf("%d",countt);
  }
  else
  {
    int sum=0;
    int minE=0;
    int minC=0;
    for(int i=1;i<=n;i++)
      head[i]=i;
    while(!q.empty())
    {
      edge tp = q.top();
      q.pop();
      if(unite(tp.src,tp.dst))
      {
        sum+=tp.cost;
        minE+=tp.hasE;
        if(tp.hasE>0)
          minC++;
      }
    }
    if(p==2)
      printf("%d\n%d",minC,minE);
    else
      printf("%d",sum);
  }	
}