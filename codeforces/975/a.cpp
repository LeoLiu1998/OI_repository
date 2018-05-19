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
set<string> s;
char buff[10005];
string simple(string k) {
	int cnt=0;
	sort(k.begin(),k.end());
	memset(buff,0,sizeof buff);
	buff[0]=k[0];
	for(int i=1;i<k.size();++i) {
		if(k[i]!=k[i-1])
			buff[++cnt]=k[i];
	}
	string ret=buff;
	return ret;
}

int main() {
	int n; R(n);
	for(int i=1;i<=n;++i) {
		string k;
		cin>>k;
		s.insert(simple(k));
	}
	cout<<(s.size())<<endl;
}


