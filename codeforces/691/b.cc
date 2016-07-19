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
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar(); } 
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
char p[]="AdbHIMOopqTUVvWwXxY";
char q[]="AbdHIMOoqpTUVvWwXxY";
char s[10001];
map<char,char> t;
int main() {
	scanf("%s",s+1);	
	int len=strlen(p);
	for(int i=0;i<len;++i) {
		t[p[i]]=q[i];
	}
	len=strlen(s+1);
	for(int i=1,j=len;i<=j;++i,--j) {
		if(s[j]!=t[s[i]]) {
			cerr<<s[i]<<endl;
			puts("NIE");
			return 0;
		}
	}
	puts("TAK");
	return 0;
}


