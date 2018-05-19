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
string as;
int a;

int check(int x) {
	ll sq=x*x;
	string tmp = to_string(sq);
	int j=0;
	int del=0;
	for(int i=0;i<as.length();i++) {
		if(j<tmp.length()&&as[i]==tmp[j]) {
			j++;
		} else {
			del++; 
		}
	}
	if(j!=tmp.length())
		return -1;
	else
		return del; 
}

int main() {
	R(a);
	as=to_string(a);
	int bound = sqrt(a)+0.5;
	int ans=INT_MAX;
	for(int i=bound;i;--i) {
		int res = check(i);
		if(check(i)!=-1) {
			cerr<<i*i<<" "<<res<<endl;
			if(res<ans) {
				ans=res;
				
			}
		}
	}
	Pn(ans==INT_MAX ? -1 : ans);
}


