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
char a[]=" BGR";
int cnt[4];//BGR
int n;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		char ch=getchar();
		while(!isalpha(ch)) {
			ch=getchar();
		}
		if(ch=='R') {
			cnt[3]++;
		} else if(ch=='G') {
			cnt[2]++;
		} else {
			cnt[1]++;
		}
	}
	if((cnt[1]&&cnt[2]&&cnt[3])||((cnt[1]>=2)+(cnt[2]>=2)+(cnt[3]>=2))>=2) {
		puts("BGR");
		exit(0);
	}
	if(((cnt[1]!=0)+(cnt[2]!=0)+(cnt[3]!=0))==1) {
		for(int i=1;i<=3;++i) {
			if(cnt[i]) {
				printf("%c\n",a[i]);
				exit(0);
			}
		}
	}
	if((cnt[1]==1)+(cnt[2]==1)+(cnt[3]==1)==2) {
		for(int i=1;i<=3;++i) {
			if(!cnt[i]) {
				printf("%c\n",a[i]);
				exit(0);
			}
		}
	}
	for(int i=1;i<=3;++i) {
		if(cnt[i]>=2)
			continue;
		printf("%c",a[i]);
	}
	puts("");
}

