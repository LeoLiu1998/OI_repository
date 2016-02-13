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
string hun="hundred";
//onethousand
int cnt=11;
int len[100];
int main() {
	freopen("data.out","r",stdin);
	for(int i=1;i<=99;++i) {
		string a;
		int k;
		cin>>k>>a;
		for(int j=0;j<a.size();++j) {
//			cout<<a[j];
			if(isalpha(a[j])) {
				len[i]++;
			}
		}
//		cout<<a<<" "<<len[i]<<endl;
		cnt+=len[i];
	}
	for(int i=1;i<=9;++i) {
		cnt+=len[i]+hun.size();
	}
	for(int i=1;i<=9;++i) {
		for(int j=1;j<=99;++j) {
			cnt+=len[i]+hun.size()+3+len[j];
		}
	}
	cout<<cnt<<endl;
}

