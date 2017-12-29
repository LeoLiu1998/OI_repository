//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
char order[]="LRUD";
int ans=0;
char ins[105];
char ma[55][55];
int n,m,len;
pii s,e;
map<char,pii> dir;
bool legal(pii x) {
	if(x.fi<0||x.se<0) return 0;
	if(x.fi>n||x.se>m) return 0;
	return ma[x.fi][x.se]!='#';
}

pii operator +(const pii &a,const pii &b) {
	return mp(a.fi+b.fi,a.se+b.se);
}

bool check() {
	pii cur=s;
	for(int i=1;i<=len;++i) {
		cur=cur+dir[order[ins[i]-'0']];
		if(!legal(cur))
			return 0;
		else if(cur==e)
			return 1;
	}
	return 0;
}

int main() {
	dir['U']=mp(-1,0);
	dir['D']=mp(1,0);
	dir['R']=mp(0,1);
	dir['L']=mp(0,-1);
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		scanf("%s",ma[i]+1);
		for(int j=1;j<=m;++j) {
			if(ma[i][j]=='S') {
				s=mp(i,j);
			} else if(ma[i][j]=='E') {
				e=mp(i,j);
			}
		}
	}
	scanf("%s",ins+1);
	len=strlen(ins+1);
	sort(order,order+4);
	do {
		if(check()) {
			ans++;
		}
	}while(next_permutation(order,order+4));
	Pn(ans);
}


