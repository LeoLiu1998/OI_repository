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
char str[(int)1e6+50];
char p[(int)1e4+50];
int next[(int)1e4+50]; //next[i] means str(i-next[i],i-1]==str[1,next[i]] 
int ls,lp;
void Build() {
	next[1]=0;
	int len=0;
	for(int i=2;i<=lp;++i) {
		while(len>0&&p[i]!=p[len+1]) {
			len=next[len];
		}
		if(p[len+1]==p[i]) len++;
		next[i]=len;
	}
}
void Solve() {
	int ans=0,pos=1;
	for(int i=1;i<=ls;++i) {
		while(pos>1&&p[pos]!=str[i]) {
			pos=next[pos-1]+1;		
		}
		if(p[pos]==str[i]) pos++;	
		if(pos==lp+1) {
			ans++;
		}
	}
	cout<<ans<<endl;
}
int main() {
	int M;
	R(M);
	while(M--) {
		memset(str,0,sizeof str);
		memset(p,0,sizeof p);
		memset(next,0,sizeof next);
		scanf("%s%s",p+1,str+1);
		ls=strlen(str+1); lp=strlen(p+1);
		Build();
	/*	for(int i=1;i<=lp;++i) {
			Ps(next[i]);
			puts("");
		}*/
		Solve();
	}
}

