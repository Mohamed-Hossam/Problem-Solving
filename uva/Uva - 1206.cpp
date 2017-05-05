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
#define R_W        R_("in.txt"),W_("out.txt")
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
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
class point
{
public: 
    ld x, y;string out;
	point(){ x = y = 0.0; }
	point(ld xx, ld yy,string _x,string _y) :x(xx), y(yy){out='('+_x+','+_y+')';}
    static ld dist(point p1, point p2){ return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); }
	bool operator==(point p)const{ return fabs(x - p.x) < EPS&&fabs(y - p.y) < EPS; }
};
struct vec
{
	ld x, y;
	vec(ld _x, ld _y) : x(_x), y(_y) {}
	static vec toVec(point a, point b){return vec(b.x - a.x, b.y - a.y);};
	static ld cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
	static bool ccw(point p, point q, point r) { return cross(toVec(p, q), toVec(p, r)) > 0; }
	static bool collinear(point p, point q, point r) { return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }
};
point pivot;
class polygon
{
public:
	static bool angleCmp(point a, point b) 
	{
		if (vec::collinear(pivot, a, b)) 
		return point::dist(pivot, a) < point::dist(pivot, b); 
		ld d1x = a.x - pivot.x, d1y = a.y - pivot.y;
		ld d2x = b.x - pivot.x, d2y = b.y - pivot.y; 
		return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; 
	}
	static vector<point> Convex_Hull(vector<point> P) 
	{ 
		int n=sz(P);
		if (sz(P) <= 3) 
		{ 
			if (!(P[0] == P[n-1])) P.push_back(P[0]); 
			return P;
		} 
		int P0 = 0;
		lop(i,1,n) 
			if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) P0 = i;
		swap(P[0],P[P0]);pivot = P[0];
        sort(++P.begin(), P.end(), angleCmp);
		vector<point> S; 
		S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); 
		int i=2,j;
		while (i < n) 
		{ 
			j = sz(S)-1; 
			if (vec::ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); 
			else S.pop_back(); 
		} 
		return S;
	}
};
int main()
{
	//R_W;
	string in;
	while(getline(cin,in))
	{
		string a[2];int j=0;vector<point>P;
		lop(i,0,in.length())
		{
			if(in[i]=='('||in[i]==')')continue;
			if(in[i]=='-'||(in[i]>='0'&&in[i]<='9')||in[i]=='.')a[j]+=in[i];
			else
			{
				if(j)P.push_back(point(atof(a[0].c_str()),atof(a[1].c_str()),a[0],a[1])),a[0].clear(),a[1].clear();
				j=!j;
			}
		}
		P.push_back(point(atof(a[0].c_str()),atof(a[1].c_str()),a[0],a[1]));
		P.push_back(P[0]);
		P=polygon::Convex_Hull(P);
		lop(i,0,sz(P))if(i<sz(P)-1)cout<<P[i].out<<" "; else cout<<P[i].out<<endl; 
	}
}