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
const int maxn=10050;
int res[maxn];
pii pos[maxn];
bool vis[11];
bool check(int x) {
	memset(vis,0,sizeof vis);
	while(x) {
		int cur=x%10;
		if(vis[cur]) return 0;
		vis[cur]=1;
		x/=10;
	}
	return 1;
}
void Print(int k) {
	if(res[k]==1) {
		Ps(k);
		return ;
	} else {
		Print(pos[k].fi);
		Print(pos[k].se);
	}
}
int T;
/*
int main2() {
	for(int i=1;i<=10000;++i) {
		if(check(i)) {
			res[i]=1;
			continue;
		} else {
			res[i]=INT_MAX;
			for(int j=1;2*j<=i;++j) {
				if(res[i]>res[j]+res[i-j]) {
					res[i]=res[j]+res[i-j];
					pos[i]=mp(j,i-j);
				}
			}
		}
	}
	R(T);
	while(T--) {
		int n; R(n);
		Ps(res[n]);
		Print(n);
		puts("");
	}
}
*/
bool flag=0;
int cnt[15];
int fcnt[15];
int cl;
void dfs(int k,bool s) {
	if(k==cl+1) {
		flag=1;
		return ;
	}
	if(s) {
		for(int i=cnt[cl-k+1];i>=0;--i) {
			for(int j=cl;j>=cl-k+2;--j) {
				if(fcnt[j]==i) {
					goto NEX;
				}
			}
			fcnt[cl-k+1]=i;
			if(i==cnt[cl-k+1]) {
				dfs(k+1,1);
				if(flag) return ;
			} else {
				dfs(k+1,0);
				if(flag) return ;
			}
NEX:
			continue;
		}
	} else {
		for(int i=9;i>=0;--i) {
			for(int j=cl;j>=cl-k+2;--j) {
				if(fcnt[j]==i) goto NEX1;
			}
			fcnt[cl-k+1]=i;
			dfs(k+1,0);
			if(flag) return ;
NEX1:
			continue;
		}
	}
}
int LF(int x) {
	cl=0; flag=0;
	while(x) {
		cnt[++cl]=x%10;
		x/=10;
	}
	dfs(1,1);
	int ret=0;
	for(int i=cl;i;--i) {
		ret*=10;
		ret+=fcnt[i];
	}
	return ret;
}

int pre[]
int main() {
	R(T);
	while(T--) {
		int n; R(n);
		if(check(n)) {
			Ps(1); Pn(n);
		} else {
			Ps(2);
			int cur=n,ot;
			while(1) {
				cur=LF(n-1);
				ot=n-cur;
				if(check(ot)) {
					Ps(cur); Pn(ot);
					goto SMG;
				}
			}
		}
SMG:
		continue;
	}
}
