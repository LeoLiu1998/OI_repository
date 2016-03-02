/*
PROB: fact4
ID : yeguang2
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
#define PROB "fact4"
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
int n,cnt;
ll cur=1;
int main() {
	Redirect();
	R(n);
	for(int i=1;i<=n;++i) {
		int temp=i;
		while(temp%2==0) {
			temp/=2;
			cnt++;
		}
		while(temp%5==0) {
			temp/=5;
			cnt--;
		}
		cur*=temp; cur%=10;
	}
	for(int i=1;i<=cnt;++i) {
		cur*=2;
		cur%=10;
	}
	cout<<cur<<endl;
}

