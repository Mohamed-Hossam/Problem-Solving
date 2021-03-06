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
#define lop(i,a,n)   for(int i=a;i<n;++i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define ld         long double
#define sz(v)      (ll)v.size()
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 4 * 1e5 + 7; map<string, int>mp; int ans = 0;
void Fail_Fun(string s,int two)
{
    int n = s.length();
    vi longestprefix(n, 0);
    for (int i = 1, k = 0; i < n; ++i)
    {
        while (k>0 && s[i] != s[k]){ k = longestprefix[k - 1]; }
        if (s[i] == s[k])longestprefix[i] = ++k; else longestprefix[i] = k;
    }
    string ss = s.substr(0, n - longestprefix[n - 1]); if (n%ss.length() != 0)ss = s;
    string m = ss;
    while (m.length() <= n)
    {
        if (n%m.length() == 0)
            if (two&&mp[m]){ ans++; }
            else { mp[m]++; }
        m += ss;
    }
    
}
int main()
{
    string s1, s2; cin >> s1 >> s2;
    Fail_Fun(s1, 0);
    Fail_Fun(s2, 1);
    cout << ans << endl;
}