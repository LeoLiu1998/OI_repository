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
int a[105][105];
int r,c,h,v;
int blocks=0;
int per_blo = 0;
int cnt=0;
int hero[105];
int vert[105];
int rowsum[105];
int rowcnt[105];
bool bfsl(int k ) {
	if(k==v) {
		return 1;
	}
	int last = vert[k];
	memset(rowcnt,0,sizeof rowcnt);
	for(int i=last+1;i<=c;++i) {
		for(int j=1;j<=h+1;++j) {
			for(int q=hero[j-1]+1;q<=hero[j];++q) {
				rowcnt[j] += a[q][i];
			}
		}
		for(int j=1;j<=h+1;++j) {
			if(rowcnt[j]!=per_blo) {
				goto NEXT;
			}
		}
		if(bfsl(k+1)) {
			return 1;
		}
NEXT:
		continue;
	}
	return 0;
}

bool bfsh(int k) {
	if(k==h) {
		hero[h+1] = r;
		return bfsl(0);	
	}
	int last = hero[k];
	int prefix= 0;
	for(int i=last+1;i<=r;++i) {
		prefix += rowsum[i];
		if(prefix == (per_blo*(v+1))) {
			hero[k+1] = i;
			if (bfsh(k+1)) {
				return 1;
			}
		}
	}
	return 0;
}

bool BF() {
	int presum = 0;
	for(int hh = 1;hh<r;++hh) {
		presum += rowsum[hh];
		if(presum == 2*per_blo) 
			for(int vv = 1; vv<c;++vv) {
				int tot = 0,tot2=0;
				for(int i=1;i<=hh;++i) {
					for(int j=1;j<=vv;++j) {
						tot+=a[i][j];
					}
				}
				for(int i=hh+1;i<=r;++i) {
					for(int j=1;j<=vv;++j) {
						tot2+=a[i][j];
					}
				}
				if(tot2==tot&&tot==per_blo) {
					return 1;
				}
			}
	}
	return 0;
}

int main() {
	int T; R(T);
	for(int qwq=1;qwq<=T;++qwq) {
		R(r); R(c); R(h); R(v);
		int ans = 0;
		cnt=0;
		for(int i=1;i<=r;++i) {
			rowsum[i] = 0;
			for(int j=1;j<=c;++j) {
				char ch=0; while(ch!='@'&&ch!='.') ch=getchar();
				a[i][j]= ch=='@';
				cnt+=a[i][j];
				rowsum[i]+=a[i][j];
			}
		}
		
		blocks=(h+1)*(v+1);
		
		if(cnt%blocks) {
			printf("Case #%d: IMPOSSIBLE\n",qwq);
			continue;
		}
		per_blo = cnt / blocks;
		if(h==v&&v==1) {
			ans = BF();
			goto PRINT;	
		}
		ans = bfsh(0);
PRINT:
		printf("Case #%d: ",qwq);
		printf(ans?"POSSIBLE\n":"IMPOSSIBLE\n");
	}
}


