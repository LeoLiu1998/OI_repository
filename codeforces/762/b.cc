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
int a,b,c;
vector<int> p[3];
int m;
ll n,ans;
int main() {
	R(a); R(b); R(c); R(m);
	for(int i=1;i<=m;++i) {
		int temp; R(temp);
		string s; cin>>s;
		if(s[0]=='U') {
			p[1].pb(temp);
		} else if(s[0]=='P') {
			p[2].pb(temp);
		}
	}
	sort(p[1].begin(),p[1].end());
	sort(p[2].begin(),p[2].end());
	int a1=min((int)p[1].size(),a);
	n+=a1;
	for(int i=0;i<a1;++i) {
		ans+=p[1][i];
	}
	int a2=min((int)p[2].size(),b);
	n+=a2;
	for(int i=0;i<a2;++i) {
		ans+=p[2][i];
	}
	while(c--) {
		if(a1==(p[1].size())&&(a2==(p[2].size()))) break;
		n++;
		if(a1==(p[1].size())) {
			ans+=p[2][a2];
			a2++;
		} else if(a2==(p[2].size())) {
			ans+=p[1][a1];
			a1++;
		} else {
			if(p[1][a1]<p[2][a2]) {
				ans+=p[1][a1];
				a1++;
			} else {
				ans+=p[2][a2];
				a2++;
			}
		}
	}
	cout<<n<<" "<<ans<<endl;
}

