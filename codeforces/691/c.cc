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
char s[(int)1e6 +100];
char ans[(int)1e6+100];
int sl,ansl;
bool flag;
int fnz;
int dpos;
bool flag2;
int main() {
	scanf("%s",s+1);
	sl=strlen(s+1);
	for(int i=1;i<=sl;++i) {
		if((flag)&&(isdigit(s[i]))&&s[i]!='0') flag2=1;
		if((!flag)&&(isdigit(s[i]))&&s[i]!='0') {
			flag=1;
			fnz=i;
		}
		if(s[i]=='.') {
			dpos=i;			
		}
	}
	if(!flag) {
		puts("0");
		return 0;
	}
	if(!dpos) dpos=sl+1;
	int del=dpos-fnz-1;
	if(del<0) del++;
	ans[++ansl]=s[fnz];
	if(flag2) ans[++ansl]='.';
	for(int i=fnz+1;i<=sl;++i) {
		if(isdigit(s[i])) {
			ans[++ansl]=s[i];
		}
	}
	while(ans[ansl]=='0') --ansl;
	ans[ansl+1]=0;
	cerr<<ans[ansl]<<endl;
	if(del==0) {
		rep(i,1,ansl,1) putchar(ans[i]);
		return 0;
	}
	ans[++ansl]='E';
	for(int i=1;i<=ansl;++i) putchar(ans[i]);
	printf("%d\n",del);
}	


