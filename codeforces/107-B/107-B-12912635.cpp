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
#include<stdlib.h>
#include<math.h>
#include<ctime>
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
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
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
int const MOD = 1e9 + 7;
int arr[MAX];
int n, m, h;
ld NCR(ll n, ll r)
{
    if (r > n) return 0;
    if (r * 2 > n) r = n - r;
    if (r == 0) return 1;
    ld ans = n;
    lop(i, 2, r + 1){ ans *= (n - i + 1); ans /= i; }
    return ans;
}
int main()
{
    cin >> n >> m >> h;
    int sum = 0;
    lop(i, 0, m)sc(arr[i]), sum += arr[i];
    ld A = NCR(sum-arr[h-1], n - 1), B = 0;
    lop(i, 1, arr[h-1]+1)
    {
        B += NCR(sum - arr[h - 1], n - i - 1)*NCR(arr[h - 1] - 1, i);
    }
    if (A+B == 0)cout << "-1\n";else
    pr3(B / (A + B));
}