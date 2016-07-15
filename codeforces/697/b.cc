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
int a[100000];
int pos;
int k=0;
int main() {
	char ch=getchar();
	while(ch>='0'&&ch<='9') {
		a[++k]=ch-'0';
		ch=getchar();
	}
	pos=k;
	ch=getchar();
	while(ch>='0'&&ch<='9') {
		a[++k]=ch-'0';
		ch=getchar();
	}
	int e;
	cin>>e;
	if(k==2&&a[2]==0&&(a[1]==0||e==0)) {
		cout<<a[1]<<endl;
		return 0;
	}
	pos+=e;
	bool flag=1;
	for(int i=1;i<=k||i<=pos;++i) {
		if(flag&&(!a[i])&&i<pos) continue;
		cout<<a[i];
		flag=0;
		if(i<k&&i==pos) cout<<'.';
	}
	cout<<endl;
}

