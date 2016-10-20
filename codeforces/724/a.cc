//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
set<int> Valid;
map<string,int> m;
int main() {
	Valid.insert(3); Valid.insert(0); Valid.insert(2);
	m["monday"]=0;
	m["tuesday"]=1;
	m["wednesday"]=2;
	m["thursday"]=3;
	m["friday"]=4;
	m["saturday"]=5;
	m["sunday"]=6;
	string a,b;
	cin>>a>>b;
	int del=m[b]-m[a];
	del=del+7;
	del%=7;
	if(Valid.count(del)) puts("YES");
	else puts("NO");
}

