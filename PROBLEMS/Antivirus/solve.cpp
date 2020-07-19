#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define forn(i,a,b) for (int i = a; i <= b; i++)
#define sz(x) (int)((x).size())
#define inf 0x3f3f3f3f
#define Nmax 2005
#define cin in
#define cout out
const ll mod = 1000000007;
const int N = 2e5 + 11;
ifstream in("antivirus.in");
ofstream out("antivirus.out");
int t, n, k, last;
int a[Nmax], s[Nmax];
int dp[Nmax][Nmax];	
void start(int n,int k)
{
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			dp[i][j] = inf;
		}
	}
	for(int i = 0; i <= n; i++)
	{
		s[i]=0;
		dp[i][0]=0;	
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0); cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		start(n,k);
		int last=0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s[i] = s[i-1] + a[i];
			if(!a[i])k--;
		}
		for(int i = 1; i <= n; i++)
		{
			if(a[i] && last)
			{
				for(int j = 1; j <= k; j++)
				{
					dp[i][j] = dp[i-1][j];
					if(last + j - i >= 0)
					{
						dp[i][j] = min(dp[i][j] , dp[last][j - i + last] + s[i] - s[last]);
					}
				}
			}else
			if(!a[i])
			{
				for(int j = 1; j <= k; j++)
				{
					dp[i][j] = dp[i-1][j];
					for(int l = i; l > last; l--)
					{
						if(j - i + l >= 0)
							dp[i][j] = min(dp[i][j] , dp[l-1][j - i + l ] + s[i] - s[l-1]);
					}
				}
				last=i;
			}
		}
        cout << dp[n][k] << '\n';
	}
	return 0;	
}