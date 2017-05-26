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
int n,k;
char str[100];
int a,b;
int main() {
	R(n); R(k);
	int l=0,r=n,mid;
	while(r-l>1) {
		mid=(l+r)>>1;
		Ps(1); Ps(mid); Pn(mid+1);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T') {
			r=mid;
		} else {
			l=mid;
		}
	}
	a=r;
#ifdef YGHDEBUG
	Pn(a);
#endif
	if(a==1) goto NEX;
	l=1;r=a-1;
	while(r-l>1) {
		mid=(l+r)>>1;
		Ps(1); Ps(mid); Pn(mid+1);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T') {
			r=mid;
		} else {
			l=mid;
		}
	}
	Ps(1); Ps(l); Pn(r);
	fflush(stdout);
	scanf("%s",str);
	if(str[0]=='T') r=l;
	Ps(1); Ps(r); Pn(a);
	fflush(stdout);
	scanf("%s",str);
	if(str[0]=='T') goto END;
NEX:
	l=a+1; r=n;
#ifdef YGHDEBUG
	cout<<"Begin"<<endl;
#endif
	while(r-l>1) {
		mid=(l+r)>>1;
		Ps(1); Ps(mid); Pn(mid+1);
		fflush(stdout);
		scanf("%s",str);
		if(str[0]=='T') {
			r=mid;
		} else {
			l=mid;
		}
	}
	Ps(1); Ps(l); Pn(r);
	fflush(stdout);
	scanf("%s",str);
	if(str[0]=='T') r=l;
END:	
	Ps(2); Ps(a); Pn(r);
	fflush(stdout);
}

