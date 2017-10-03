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
char str[15];
int n;
char a[10][10];
int ans[10][10];
bool vis[10][10];

pii operator + (const pii &z,const pii &b) {
	return mp(z.fi+b.fi,z.se+b.se);
}

inline bool valid(const pii &z) {
	return (z.fi>=1)&&(z.fi<=8)&&(z.se>=1)&&(z.se<=8);
}
vector<pii> pax;

void dfs(pii pos,int k) {
	if(k==n) {
		pax.pb(pos);
/*		for(auto i:pax) {
			cout<<"("<<i.fi<<","<<i.se<<") ";
		}
		puts("");
*/		pax.erase(pax.end()-1);
		ans[pos.fi][pos.se]+=1;
		return ;
	}
	pax.pb(pos);
	vis[pos.fi][pos.se]=1;
	for(int i=-1;i<=1;++i) {
		for(int j=-1;j<=1;++j) {
			if((i==0)&&(j==0)) continue;
			pii mov=mp(i,j);
			pii nex=mov+pos;
			if(valid(nex)&&(!vis[nex.fi][nex.se])&&(a[nex.fi][nex.se]==str[k+1])) {
				dfs(nex,k+1);	
			}
		}
	}
	pax.erase(pax.end()-1);
	vis[pos.fi][pos.se]=0;
}

int main() {
	R(n);
	scanf("%s",str+1);
	rep(i,1,8,1) {
		scanf("%s",a[i]+1);
	}
	rep(i,1,8,1) {
		rep(j,1,8,1) {
			if(a[i][j]==str[1]) {
				dfs(mp(i,j),1);
			}
		}
	}
	int ret=0;
	rep(i,1,8,1) 
		rep(j,1,8,1) 
			ret+=ans[i][j];

	Pn(ret);
}

