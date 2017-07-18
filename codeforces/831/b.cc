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
char s[50],t[50];
char str[500000];
map<char,char> ma;
int main() {
	scanf("%s",s+1);
	scanf("%s",t+1);
	scanf("%s",str+1);
	for(int i=1;i<=26;++i) {
		ma[tolower(s[i])]=tolower(t[i]);
	}
	int len=strlen(str+1);
	rep(i,1,len,1) {
		if(isdigit(str[i])) putchar(str[i]);
		else if(islower(str[i])) putchar(ma[tolower(str[i])]);
		else putchar(toupper(ma[tolower(str[i])]));
	
	}
	puts("");
}

