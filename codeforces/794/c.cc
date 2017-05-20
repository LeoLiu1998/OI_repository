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
int n;
const int maxn=300100;
char s[maxn],t[maxn];
char ans[maxn];
bool cmp(char a, char b) {
	return a>b;
}
int cnto,cnti;
int main() {
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	sort(s+1,s+n+1);
	sort(t+1,t+n+1,cmp);
	int l=0,r=n+1;
	for(int i=1;i<=n;++i) {
		if(i%2) {
			if(s[cnto+1]>=t[cnti+1]) {
				ans[--r]=s[++cnto];
			} else {
				ans[++l]=s[++cnto];
			}
		} else {
			if(t[cnti+1]<=s[cnto+1]) {
				ans[--r]=t[++cnti];
			} else {
				ans[++l]=t[++cnti];
			}
		}
	/*	if(i%2) {
			ans[i]=s[++cnto];		
		} else {
			ans[i]=t[++cnti];
		}
		putchar(ans[i]);*/
	}
	for(int i=1;i<=n;++i) {
		putchar(ans[i]);
	}
	puts("");
}

