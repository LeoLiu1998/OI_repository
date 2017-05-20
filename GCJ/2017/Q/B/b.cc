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
char str[25];
char ans[25];
int l;
int T;
int main() {
	scanf("%d",&T);
	for(int q=1;q<=T;++q) {
		memset(str,0,sizeof str);
		memset(ans,0,sizeof ans);
		scanf("%s",str+1);
		l=strlen(str+1);
		ans[l]=str[l];
		for(int i=2;i<=l;++i) {
			int c=l+1-i;
			if(str[c]<=ans[c+1]) {
				ans[c]=str[c];
			} else {
				ans[c]=str[c]-1;
				for(int j=c+1;j<=l;++j) {
					ans[j]='9';
				}
			}
		}	
		int k=1;
		while(ans[k]=='0'&&k<=l) k++;
		printf("Case #%d: %s\n",q,ans+k);
	}

}
