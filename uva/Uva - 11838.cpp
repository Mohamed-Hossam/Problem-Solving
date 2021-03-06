//In the name of Allah
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<functional>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#include<string>
#include<cstdio>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define sz(v)      (ll)v.size()
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(3)<<n
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 2000 + 7;
int const MOD = 1e9 + 7;
vvi G[2]; int vis[2][MAX]; vi v;
void DFS(int node, int x)
{
	vis[x][node] = 1;
	lop(i, 0, sz(G[x][node]))
	{
		int c = G[x][node][i];
		if (!vis[x][c])DFS(c, x);
	}
	if (!x)
	v.push_back(node);
}
int main()
{
	int n, m, cnt;
	while (1)
	{
		cin >> n >> m; if (n == 0 && m == 0)break;
		G[0].resize(n), G[1].resize(n);
		lop(i, 0, m)
		{
			int a, b, c; sc(a), sc(b), sc(c); --a, --b;
			if (c == 1)G[0][a].push_back(b), G[1][b].push_back(a); else G[0][a].push_back(b), G[0][b].push_back(a)
				, G[1][a].push_back(b), G[1][b].push_back(a);
		}
		cnt = 0;
		memset(vis, 0, sizeof vis);
		lop(i, 0, n)if (!vis[0][i])DFS(i, 0);
		loop(i, sz(v), 0)if (!vis[1][v[i]])DFS(v[i], 1), cnt++;
		if (cnt == 1)puts("1"); else puts("0");
		v.clear(), G[0].clear(), G[1].clear();
	}
}