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
int cnt[400005];
int a[100050];
int b[100050]; 
int n;
int ans_pos;
int ans=0;
int count(int k,int p=1,int l=1,int r=n) {
	if(l>=k)
		return cnt[p];
	if(r<k) {
		return 0;
	} else {
		return count(k,p<<1,l,(l+r)>>1)+count(k,p<<1|1,((l+r)>>1)+1,r);
	}
}

void sett(int k,int p=1,int l=1,int r=n) {
	if(l==r) {
		cnt[p]=1;
		return ;
	} else {
		int mid=l+r;
		mid>>=1;
		if(k<=mid)
			sett(k,p<<1,l,(l+r)>>1);
		else
			sett(k,p<<1|1,((l+r)>>1)+1,r);
		cnt[p]=cnt[p<<1]+cnt[p<<1|1];
	}
}
int inc=INT_MIN;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		int x; R(x);
		a[i]=x;		
		b[i]=count(x);
		sett(x);
	}
	set<int> s;
	for(int i=n;i;--i) {
		int cinr=distance(s.begin(),s.lower_bound(a[i]));
		if(b[i]==1) {
			s.insert(a[i]);
		}
		cinr-=(b[i]==0);
		cerr<<cinr<<endl;
		if(cinr>inc)  {
			inc=cinr;
			ans=a[i];
		} else if(cinr==inc) {
			ans=min(ans,a[i]);
		}
	}
	Pn(ans);
}


