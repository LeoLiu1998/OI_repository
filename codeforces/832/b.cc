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
char a[(int)1e5+10];
char b[(int)1e5+10];
bool st[3000];

inline bool equal(char x,char y) {
	if(x==y) return 1;
	if(x=='?') return st[y];
	return 0;
}
int main() {
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;++i) {
		st[a[i]]=1;
	}
	memset(a,0,sizeof a);
	scanf("%s",a+1);
	int T;
	R(T);
	int pos=-1;
	len=strlen(a+1);
	rep(i,1,len,1) {
		if(a[i]=='*') {
			pos=i;
		}
	}
	while(T--) {
		memset(b,0,sizeof b);
		scanf("%s",b+1);
		int lb=strlen(b+1);
		if(pos==-1) {
			if(len!=lb) goto FAIL;
			for(int i=1;i<=lb;++i) {
				if(a[i]!=b[i]) {
					if(equal(a[i],b[i])) continue;
					goto FAIL;
				}
			}
		} else {
			int l=0,r=lb+1;
			for(int i=1;i<pos;++i) {
				if(a[i]!=b[i]) {
					if(equal(a[i],b[i])) continue;
					else goto FAIL;
				}
			}
			int cr=len+1;
			while((cr>1)&&(r>1)&&equal(a[cr-1],b[r-1])) { 
				r--; cr--;
			}
			if(cr!=pos+1) goto FAIL;
			if(r<=pos) goto SUC;
			for(int i=pos;i<r;++i) {
				if(st[b[i]]) {
					goto FAIL;
				}
			}
		}
SUC:
		puts("YES");
		continue;
FAIL:
		puts("NO");
	}
}

