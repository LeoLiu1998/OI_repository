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
const int maxn=40000000;
unordered_set<int> st;
int pre[maxn];
int cnt=0;
int pp=0;
int vis[15];
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
int main() {
	for(int i=1;i<=9;++i) {
		pre[++cnt]=i;
	}
	for(int i=pp+1;i<=cnt;++i) {
		memset(vis,-1,sizeof vis);
		int cur=pre[i];
		if(cur>=(2e8)) break;
		while(cur) {
			vis[cur%10]=1;
			cur/=10;
		}
		for(int j=0;j<=9;++j) {
			if(vis[j]==-1) {
				pre[++cnt]=pre[i]*10+j;
			}
		}
	}
	cerr<<cnt<<endl;
	for(int i=1;i<=cnt;++i) {
		st.insert(pre[i]);
	}
	int T; R(T);
	while(T--) {
		int n; R(n);
		if(st.count(n)) {
			Ps(1); Pn(n);
		} else {
			Ps(2);
			int p=lower_bound(pre+1,pre+cnt+1,n)-pre;
			p--;
			for(int i=p;i;--i) {
				int ot=n-pre[i];
				if(st.count(ot)) {
					Ps(pre[i]); Pn(ot);
					goto SMG;
				}
			}
		}
SMG:
		continue;
	}
}

