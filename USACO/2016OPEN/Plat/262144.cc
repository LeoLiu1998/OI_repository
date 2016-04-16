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
#define PROB "262144"
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

const int maxn=280050;
int r[maxn];
int a[maxn];
int n;
int mi=INT_MAX;
bool flag=1;
int main() {
	Redirect();
	R(n);
	//memset(r,-1,sizeof r);
	for(int i=1;i<=n;++i) {
		R(a[i]); mi=min(a[i],mi);	
	}
	for(int i=mi;flag;++i) {
		flag=0;
		for(int j=1;j<=n;++j) {
			if(r[j]==-1) continue;
			if(r[j]==0) {
				if(a[j]==i) {
					r[j]=j;	
				}
			} else {
				if((r[r[j]+1]!=0)&&(r[r[j]+1]!=-1)) {
					r[j]=r[r[j]+1];
					flag=1;
				} else {
					r[j]=-1;			
				}
			}
		}
		if(!flag) {
			cout<<i-1<<endl;
			return 0;
		}
	}
}

