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
int n;
const int maxn=100500;
vector<int> pos[maxn];
vector<pii> v;
string s[maxn];
char buf[maxn*10];
char cha[1005];
int cur=0;
bool cmp(pii a,pii b) {
	if(a.fi!=b.fi) return a.fi<b.fi;
	else return a.fi+s[a.se].size()>b.fi+s[b.se].size();
}
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		memset(buf,0,sizeof buf);
		scanf("%s",buf);
		s[i]=buf;
		register int k,tmp; R(k);
		for(int j=1;j<=k;++j) {
			R(tmp);
		//	pos[i].pb(tmp);
			v.pb(mp(tmp,i));
		}
		//sort(pos[i].begin(),pos[i],end());
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<1000;++i) {
		cha[i]='a';
	}
	for(int i=0;i<v.size();++i) {
		if(cur<v[i].fi+s[v[i].se].size()-1) {
			while(v[i].fi-cur>=1000) {
				cur+=1000;
				printf("%s",cha);
			}
			for(int j=cur+1;j<v[i].fi;++j) {
				putchar('a');
				cur++;
			}
			for(int j=cur+1-v[i].fi;j<s[v[i].se].size();++j) {
				putchar(s[v[i].se][j]);
				cur++;
			}
		}
	}
	puts("");
	return 0;
}

