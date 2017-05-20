//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
#include <cstdio>
#include <cctype>
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
//typedef pair<int,int> pii;
//typedef pair<ll,ll> pll;
const int maxn=1e7+5;
int a[maxn];
int t[maxn];
int ans;
int n,m;
int tot=0;
int lft=0;
int main() {
	R(n); R(m);
	for(int i=1;i<=m;++i) {//while(m--) { 
		char ch=getchar(); while(!isalpha(ch)) ch=getchar();
		if(ch=='I') {
			register int x,y; R(x); R(y);
			if(t[x]<=lft||a[x]==-1) tot++;  
			a[x]=y;
			t[x]=i;
		} else if(ch=='O') {
			register int x; R(x);
			if(t[x]<=lft||a[x]==-1) continue;
			a[x]=-1;
			tot--;
			t[x]=i;
		} else if(ch=='C') {
			lft=i;
			tot=0;
		} else if(ch=='N') {
			ans+=tot;
		} else {
			int x; R(x);
			if(t[x]<=lft||a[x]==-1) {
				ans+= -1;
			} else {
				ans+=a[x];
			}
		}
	}
	Pn(ans);
}

