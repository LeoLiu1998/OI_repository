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
unordered_map<string,int> cr,wr;
unordered_map<string,string> trans;
int n;
string a[22];
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	rep(i,1,n,1) cin>>a[i];
	int m;
	cin>>m;
	rep(i,1,m,1) {
		string a,b,c;
		cin>>a>>b>>c;
		trans[a]=b;
		if(c[0]=='c') {
			cr[a]++;
		} else {
			wr[a]++;
		}
	}
	ll all=1,crr=1;
	rep(i,1,n,1) {
		all*=(cr[a[i]]+wr[a[i]]);
		crr*=cr[a[i]];
	}
	if(all==1) {
		rep(i,1,n,1) {
			cout<<trans[a[i]]<<" ";
		}
		cout<<endl;
		if(crr==1) {
			cout<<"correct\n";	
		} else {
			cout<<"incorrect\n";
		}
	} else {
		cout<<crr<<" correct\n";
		cout<<all-crr<<" incorrect\n";
	}

}


