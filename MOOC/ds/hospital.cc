//This sourcecode is under GPLv3
//yeguanghao
//#include <bits/stdc++.h>
#include <cstdio>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void R(long long &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
const int maxn=35000;
ll hos[maxn];
int n;
ll l[maxn]; // l[i] means when you move from i-1 to i your cost will increase l[i]
ll r[maxn];
ll cl[maxn],cr[maxn]; //  cost on l cost on r
ll cost[maxn];
int main() {
	R(n);
	rep(i,1,n,1) {
		int pos,v; R(pos); R(v);
		hos[pos+1]+=v;
	}
	for(int i=1;i<=32770;++i) {
		l[i]=l[i-1]+hos[i];
	}
	for(int i=32770;i>=1;--i) {
		r[i]=r[i+1]+hos[i];
	}
	for(int i=1;i<=32770;++i) {
		cl[i]=cl[i-1]+l[i];
	}
	for(int i=32770;i>=1;--i) {
		cr[i]=cr[i+1]+r[i];
	}
	int ans_pos=1; 
	for(int i=1;i<=32770;++i) {
		cost[i]=cl[i-1]+cr[i+1];
		if(cost[i]<cost[ans_pos]) ans_pos=i;
	}
	Pn(ans_pos-1);
	printf("%lld\n",cost[ans_pos]);
}

