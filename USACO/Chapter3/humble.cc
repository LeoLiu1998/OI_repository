/*
PROB: humble
ID: yeguang2
LANG: C++11
*/
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
#define PROB "humble"
inline void R(long long &x) {
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
ll a[100];
set<ll> s;
set<ll> :: iterator it;
ll n,k;
ll cur=1;
ll maxm;
int main() {
	Redirect();
	R(n); R(k);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	for(int i=1;i<=k;++i) {
		for(int j=1;j<=n;++j) {
			ll temp=cur*a[j];
			if(temp>maxm&&s.size()>k) continue;
			if(temp>INT_MAX) continue;
			maxm=max(maxm,temp);
			s.insert(temp);
		}
		it=s.lower_bound(cur);
		if(i!=1) it++;
		cur=*it;
	}
	cout<<cur<<endl;
}

