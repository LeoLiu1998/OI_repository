 //This sourcecode is under GPLv3
//yeguanghao
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <unordered_map>
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
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

char str[25];
char data[10][10];
int n;
char l[7],r[7];
int ln,rn;
int mid;
long long ans;
unordered_map<ll,int> us,um,uk;
int llz=0,rz=0;
ll upath=0;
bool vis[10][10];
inline static int Count(ll k);

#define convert(x) ((x.fi-1)*8+x.se)

void dfsl(const pii & pos,int k) {
	int idx=convert(pos);
	if(k==ln) {
		upath^=1ll<<(idx-1);
		ans+=Count(upath);
		upath^=1ll<<(idx-1);
		return ;
	}
	vis[pos.fi][pos.se]=1;
	upath^=1ll<<(idx-1);
	rep(i,-1,1,1) {
		rep(j,-1,1,1) {
			if((!i)&&(!j)) continue;
			pii z=mp(pos.fi+i,pos.se+j);
			if((z.fi>=1)&&(z.fi<=8)&&(z.se>=1)&&(z.se<=8)&&(!vis[z.fi][z.se])&&(data[z.fi][z.se]==l[k+1])) {
				dfsl(z,k+1);
			}
		}
	}
	upath^=1ll<<(idx-1);
	vis[pos.fi][pos.se]=0;
}


inline int sign(ll tot) {
	if(uk.find(tot)!=uk.end()) return uk[tot];
	int k=0;
	while(tot) {
		k++;
		tot&=(tot-1);
	}
	if(k&1) return uk[tot]=-1;
	else return uk[tot]=1; 
}


inline static int Count(ll k) {
	if(us.find(k)!=us.end()) return us[k];
	int ret=rz;
	for(ll i=k;i;i=(i-1)&k) {
		ret+=sign(i)*um[i];
	}
	us[k]=ret;
	return ret;
}


void dfsr(const pii &pos, int k) {
	int idx=convert(pos);
	if(k==rn) {
		upath^=1ll<<(idx-1);
		rz++;
		for(ll i=upath;i;i=(i-1)&upath) {
			um[i]++;
		}
		upath^=1ll<<(idx-1);
		return ;
	}
	vis[pos.fi][pos.se]=1;
	if(k!=1)	upath^=1ll<<(idx-1);
	rep(i,-1,1,1) {
		rep(j,-1,1,1) {
			if((!i)&&(!j)) continue;
			pii z=mp(pos.fi+i,pos.se+j);
			if((z.fi>=1)&&(z.fi<=8)&&(z.se>=1)&&(z.se<=8)&&(!vis[z.fi][z.se])&&(data[z.fi][z.se]==r[k+1])) {
				dfsr(z,k+1);
			}
		}
	}
	if(k!=1)	upath^=1ll<<(idx-1);
	vis[pos.fi][pos.se]=0;
}


int main() {
	R(n);
	scanf("%s",str+1);
	rep(i,1,8,1) scanf("%s",data[i]+1);
	mid=(n+1)>>1;
	for(int i=1;i<=mid;++i) {
		l[i]=str[mid+1-i];
		ln++;
	}
	for(int i=mid;i<=n;++i) {
		r[++rn]=str[i];
	}
	rep(i,1,8,1) {
		rep(j,1,8,1) {
			if(data[i][j]==str[mid]) {
				pii pos=mp(i,j);
				us.clear(); um.clear(); llz=0; rz=0; 
				cerr<<clock()*1.0/CLOCKS_PER_SEC<<" ";
				dfsr(pos,1);
				cerr<<clock()*1.0/CLOCKS_PER_SEC<<" ";
				dfsl(pos,1);
				cerr<<clock()*1.0/CLOCKS_PER_SEC<<"\n";
			}
		}
	}
	printf("%llu\n",ans);
}
