 //This sourcecode is under GPLv3
//yeguanghao
#include <cstdio>
#include <cstring>
#include <algorithm>
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
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

char str[25];
char data[10][10];
int n;
char l[7],r[7];
int ln,rn;
int mid;
long long ans;
unordered_map<ull,int> um;
ull lv[5000000],rv[5000000];
int llz=0,rz=0;
ull upath=0;
bool vis[10][10];

#define convert(x) ((x.fi-1)*8+x.se)

void dfsl(const pii & pos,int k) {
	int idx=convert(pos);
	if(k==ln) {
		upath+=1ull<<(idx-1);
		lv[llz++]=upath;
		upath-=1ull<<(idx-1);
		return ;
	}
	vis[pos.fi][pos.se]=1;
	upath+=1ull<<(idx-1);
	rep(i,-1,1,1) {
		rep(j,-1,1,1) {
			if((!i)&&(!j)) continue;
			pii z=mp(pos.fi+i,pos.se+j);
			if((z.fi>=1)&&(z.fi<=8)&&(z.se>=1)&&(z.se<=8)&&(!vis[z.fi][z.se])&&(data[z.fi][z.se]==l[k+1])) {
				dfsl(z,k+1);
			}
		}
	}
	upath-=1ull<<(idx-1);
	vis[pos.fi][pos.se]=0;
}


int sign(ull tot) {
	int k=0;
	while(tot) {
		k++;
		tot&=(tot-1);
	}
	if(k%2) return -1;
	else return 1; 
}



void Count(ull k) {
	int tmp=rz;
	for(ull i=k;i;i=(i-1)&k) {
		tmp+=sign(i)*um[i];
	}
	ans+=tmp;
	
}



void dfsr(const pii &pos, int k) {
	int idx=convert(pos);
	if(k==rn) {
		upath+=1ull<<(idx-1);
		rv[rz++]=upath;
		for(ull i=rv[rz-1];i;i=(i-1)&rv[rz-1]) {
			um[i]++;
		}
		upath-=1ull<<(idx-1);//pz--;
		return ;
	}
	vis[pos.fi][pos.se]=1;
	if(k!=1)	upath+=1ull<<(idx-1);
	rep(i,-1,1,1) {
		rep(j,-1,1,1) {
			if((!i)&&(!j)) continue;
			pii z=mp(pos.fi+i,pos.se+j);
			if((z.fi>=1)&&(z.fi<=8)&&(z.se>=1)&&(z.se<=8)&&(!vis[z.fi][z.se])&&(data[z.fi][z.se]==r[k+1])) {
				dfsr(z,k+1);
			}
		}
	}
	if(k!=1)	upath-=1ull<<(idx-1);
	vis[pos.fi][pos.se]=0;
}


int main() {
	R(n);
	scanf("%s",str+1);
	rep(i,1,8,1) scanf("%s",data[i]+1);
	mid=n>>1;
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
				um.clear(); llz=0; rz=0; 
				dfsl(pos,1);
				dfsr(pos,1);
				for(int i=0;i<llz;++i) {
					Count(lv[i]);
				}
			}
		}
	}
	printf("%llu\n",ans);
}
