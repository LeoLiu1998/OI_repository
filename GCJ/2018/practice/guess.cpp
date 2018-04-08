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

void Redirect() {
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
char buf[1000];
int main() {
	int T;
	R(T);
	while(T--){
		int a,b; R(a); R(b);
		int n; R(n);
		int l=a+1,r=b;
		int cnt=0;
		while(1) {
			++cnt;
			int mid = (l+r)>>1;
			Pn(mid);
			memset(buf,0,sizeof buf);
			fflush(stdout);
			scanf("%s",buf);
			fprintf(stderr,"%d %d %d\n %s\n",l,r,mid,buf);
			if(buf[4]=='S') {
				l = mid+1;
			} else if(buf[4]=='B') {
				r = mid-1;
			} else if(buf[0]=='C') {
				break;
			} else if(buf[0]=='W') {
				fprintf(stderr,"%d %d %d %d\n",l,r,cnt,n);
				exit(0);
			}
		}
	}
	return 0;
 }


