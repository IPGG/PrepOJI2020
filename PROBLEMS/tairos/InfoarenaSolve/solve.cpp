#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

struct ura
{
    int adancime;
    vector <int> vecini;

}v[105];

int n,d,deep;
queue <int> q;
bool vizitat[105];
int frunze[105];
long long frunze_mare[10005];
int noduri[10005];
long long cnt[10005];

void bfs(int nod)
{	// BFS-ul clasic, doar ca pe masura ce parcurgem nodurile, stabilim si 
    q.push(nod); // adancimea la care ne aflam
    while(!q.empty())
    {
        for(int i = 0; i < v[q.front()].vecini.size(); i++)
            if(!vizitat[v[q.front()].vecini[i]])
            {
                vizitat[v[q.front()].vecini[i]] = true;
                v[v[q.front()].vecini[i]].adancime = v[q.front()].adancime+1;
                q.push(v[q.front()].vecini[i]);
            }
        q.pop();
    }
}

int main()
{
    freopen("tairos.in","r",stdin);
    freopen("tairos.out","w",stdout);
    cin>>n>>d;
    int x,y;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;
        v[x].vecini.push_back(y);
        v[y].vecini.push_back(x);
    }
    vizitat[1] = true; // marcam nodul radacina ca vizitat
    v[1].adancime = 0; // initializam si adancimea radacinii ca fiind 0
    bfs(1); // apelam BFS-ul de la radacina arborelui pentru a stabilii adancimile
    for(int i = 1; i <= n; i++)
    {
        deep = max(deep,v[i].adancime); // stabilim cat de adanc este arborele
        noduri[v[i].adancime]++; // stabilim cate noduri se afla pe fiecare nivel in arborele initial
        cnt[v[i].adancime]++; // aici contorizam numarul de noduri care se vor afla dupa regenerarile recursive
        if(v[i].vecini.size() == 1) // in cazul in care ne aflam la un nod care este frumza, atunci
        {
            frunze[v[i].adancime]++; // aici memoram pozitia si numarul frunzelor din nodul initial
            frunze_mare[v[i].adancime]++; // iar aici pentru arborele mare
        }
    }
    for(int i = 1; i <= d; i++)  // iar in aceste doua for-uri vom face magia de generare a noului arbore
    {
        for(int j = 1; j <= deep && i + j <= d; j++)
        {
            cnt[i+j]=(cnt[i+j]+1LL*frunze_mare[i]*noduri[j])%mod; // aici adaugam nodurile noi din urma unei noi adaugari
            frunze_mare[i+j]=(frunze_mare[i+j]+frunze_mare[i]*frunze[j])%mod; // si aici stabilim noile frunze in care vom aduga ulterior argorii
        }
    }
    cout<<cnt[d];// iar bineinteles in final avem de tiparit nodurile aflate la adancimea d fata de radacina.
    return 0;
}
/*Solutia pe care am propus-o spre rezolvarea acestei probleme este sa stocam nodurile intr-un mod mai facil decat cele clasice, astfel incat sa
stocam numarul de noduri care se afla pe fiecare nivel, de asemenea sa avem numarul si pozitia frunzelor pentru a putea face generarea continua,
astfel obinand solutia cea mai eficienta din punct de vedere al timpului si al memoriei, generarea grafului se va face pana in momentul cand vom
ajunge la nivelul d si acesta nu va mai ave frunze-mari inaintea sa.*/