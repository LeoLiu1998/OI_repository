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
int cnt;
char str[505];
int main() {
	int T; R(T);
	while(T--) {
		cnt=0;
		int l; R(l);
		scanf("%s",str+1);
		for(int i=1;i<=l;++i) {
			if(str[i]=='H') {
				cnt++;
				if(cnt>1) {
					puts("Invalid");
					goto Nex;
				}
			} else if(str[i]=='T') {
				cnt--;
				if(cnt<0||cnt>1) {
					puts("Invalid");
					goto Nex;
				}
			}
		}
		puts((cnt==0)? "Valid":"Invalid");
Nex:
		cnt=0;
	}
}

