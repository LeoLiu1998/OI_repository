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
int n,k;
int a[100050];
int f[500];
bool hard[500];
int main() {
	R(n); R(k);
	memset(f,-1,sizeof f);
	rep(i,1,n,1) {
		R(a[i]);
		int min_val = a[i];
		if(hard[a[i]]){
			continue;
		}
		while(min_val>=1&&(a[i]-(min_val-1)+1<=k)&&hard[min_val-1]==0) {
			min_val-=1;
		}
		if((f[a[i]]!=-1&&min_val > f[a[i]])) {
			for(int j=min_val;j<=a[i];++j) {
				hard[j]=1;
			}
			continue;
		}
		for(int j=min_val;j<=a[i];++j) {
			f[j]=min_val;
			hard[j]=1;
		}
		for(int j=a[i]+1;j<=(min_val+k-1);++j) {
			if(hard[j]) break;
			f[j]=min_val;
		}
	}
	rep(i,1,n,1) {
		Ps(f[a[i]]);
	}
	puts("");
}


