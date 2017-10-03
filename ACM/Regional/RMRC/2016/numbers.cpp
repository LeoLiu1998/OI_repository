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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int T,n;
char s[505];
int a[505];
vector<int> ans[505];
int main() {
	R(T);
	while(T--) {
		memset(s,0,sizeof s);
		scanf("%s",s+1);
		n=strlen(s+1);
		rep(i,1,n,1) {
			a[i]=s[i]-'0';
			ans[i].clear();
		}
		int cnt=0,flag=1;
		if(n==1) {
			goto NEX;
		}
		while(flag) {
			flag=0;
			int r=n;
			while(!a[r]) r--;
			for(int i=r-1;i;--i) {
				if(!a[i]) continue;
				if((a[i]<8)&&a[i]==a[r]) {
					a[r]<<=1;
					a[i]=0;
					flag=1;
				}
				r=i;
			}
		}
		for(int i=1;i<=n;++i) {
			if(a[i]==2) {
				ans[i].pb(2);
				a[i]=4;
			}
		}
		flag=1;
		while(flag) {
			flag=0;
			int l=1;
			while(!a[l]) l++;
			for(int i=l+1;i<=n;++i) {
				if(!a[i]) continue;
				if((a[i]<8)&&a[i]==a[l]) {
					a[i]<<=1;
					a[l]=0;
					flag=1;
				}
				l=i;
			}
		}
		for(int i=1;i<=n;++i) {
			if(a[i]==4) {
				ans[i].pb(4);
				a[i]=8;
			}
			if(a[i]) cnt++;
		}
		for(int i=0;;++i) {
			if((1<<i)>=cnt) {
				int dt=(1<<i)-cnt;
				rep(j,1,dt,1) {
					ans[n].pb(8);
				}
				break;
			}
		}
		NEX:
		for(int i=1;i<=n;++i) {
			for(auto j:ans[i]) {
				if('0'+j<=s[i]) printf("%d",j);
			}
			putchar(s[i]);
			for(auto j:ans[i]) {
				if('0'+j>s[i]) printf("%d",j);
			}
		}
		puts("");
	}
}

