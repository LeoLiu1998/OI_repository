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
#define PROB "bcs"
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
int cnt[105];
int ans=0;
bool Check(int a,int b,int c) {
	return cnt[0]==cnt[a]+cnt[b]+cnt[c];
}
int main() {
	Redirect();
	R(n);
	for(int i=0;i<=n;++i) {
		int x,y; R(x); R(y);
		for(int j=1;j<=x*y;++j) {
			char cmd=0;
			while((!isalpha(cmd))&&cmd!='.') cmd=getchar();
			if(isalpha(cmd)) {
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			for(int k=j+1;k<=n;++k) {
				ans+=Check(i,j,k);				
			}
		}
	}
	cout<<ans<<endl;
}

