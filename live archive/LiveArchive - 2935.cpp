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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1000 + 7;
int const MOD = 9999991;
bool comp(ii a,ii b)
{
	if (a.first != b.first)return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	int n; string s1, s2; cin >> n;
	lop(u, 0, n)
	{
		int cnt = 0, node = 0; cin >> s1 >> s2;
		ii a[3001], b[3001]; 
		stack<int>st, so;
		st.push(node);
		lop(i, 0, s1.length())
		{
			if (s1[i] == '0'){st.push(++node);}
			else{a[st.top()].second = node - st.top(); st.pop();}
			if (s1[i] == '0')cnt++, a[node].first = cnt; else cnt--;
		}
		a[0].second = node;
		node = 0, cnt = 0;
		so.push(node);
		lop(i, 0, s2.length())
		{
			if (s2[i] == '0'){ so.push(++node); }
			else{ b[so.top()].second = node - so.top(); so.pop(); }
			if (s2[i] == '0')cnt++, b[node].first = cnt; else cnt--;
		}
		b[0].second = node;
		sort(a, a + node+1);
		sort(b, b + node+1);
		lop(i, 0, node)
		{
			if (a[i] != b[i]||s1.length()!=s2.length()){ cout << "different\n"; goto N; }
		}
		cout << "same\n";
	N:;
	}
}