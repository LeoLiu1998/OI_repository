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

char str[25];
char data[10][10];
int n;
char l[7],r[7];
int ln,rn;
int mid;
long long ans;
//map<ull,int> lm;
//map<ull,int> rm;
unordered_map<ull,int> um;
vector<ull> lv,rv;
vector<pii> path;
bool vis[10][10];

#define convert(x) ((x.fi-1)*8+x.se)


ull Convert(const vector<pii> &v) {
	ull ret=0;
	for(auto i:v) {
		ret+= (ull)1<<(convert(i)-1);
	}
	return ret;
}

ull Convert2(const vector<pii> &v) {
	ull ret=0;
	for(int i=1;i<v.size();++i) {
		ret+= (ull)1<<(convert(v[i])-1);
	}
	return ret;
}

static inline bool valid(const pii &z) {
	return (z.fi>=1)&&(z.fi<=8)&&(z.se>=1)&&(z.se<=8)&&(!vis[z.fi][z.se]);
}
void dfsl(pii pos,int k) {
	if(k==ln) {
		path.pb(pos);
		lv.pb(Convert(path));
		path.erase(path.end()-1);
		return ;
	}
	vis[pos.fi][pos.se]=1;
	path.pb(pos);
	rep(i,-1,1,1) {
		rep(j,-1,1,1) {
			if((!i)&&(!j)) continue;
			pii z=mp(pos.fi+i,pos.se+j);
			if(valid(z)&&(data[z.fi][z.se]==l[k+1])) {
				dfsl(z,k+1);
			}
		}
	}
	path.erase(path.end()-1);
	vis[pos.fi][pos.se]=0;
}

int bitcount(int x) {
	int ret=0;
	while(x) {
		ret++;
		x&=(x-1);
	}
	return ret;
}
int sign(int tot) {
	if(bitcount(tot)%2) return -1;
	else return 1; 
}
vector<int> loc;
void Count(ull k) {
	int tmp=rv.size();
	loc.clear();
	for(int i=1;i<=64;++i) {
		if(((ull)1<<(i-1))&k) {
			loc.pb(i);
		}
	}
	int tot=(1<<loc.size())-1;
	for(int i=tot;i;--i) {
		int cur_sign=sign(i);
		ull cur=0;
		for(int j=0;j<loc.size();++j) {
			if((1<<j)&i) {
				cur+= (ull)1<<(loc[j]-1);
			}
		}
		tmp+= cur_sign*um[cur];
	}
	ans+=tmp;
	
}
int cnt=0;

void Add(ull k) {
	loc.clear();
	for(int i=1;i<=64;++i) {
		if(((ull)1<<(i-1))&k) {
			loc.pb(i);
		}
	}
	int tot=(1<<loc.size())-1;
	for(int i=tot;i;--i) {
		ull cur=0;
		for(int j=0;j<loc.size();++j) {
			if((1<<j)&i) {
				cur+= (ull)1<<(loc[j]-1);
			}
		}
		um[cur]++;
	}
}


void dfsr(pii pos, int k) {
	if(k==rn) {
		cnt++;
		path.pb(pos);
		rv.pb(Convert2(path));
		Add(rv[rv.size()-1]);
		path.erase(path.end()-1);
		return ;
	}
	vis[pos.fi][pos.se]=1;
	path.pb(pos);
	rep(i,-1,1,1) {
		rep(j,-1,1,1) {
			if((!i)&&(!j)) continue;
			pii z=mp(pos.fi+i,pos.se+j);
			if(valid(z)&&(data[z.fi][z.se]==r[k+1])) {
				dfsr(z,k+1);
			}
		}
	}
	path.erase(path.end()-1);
	vis[pos.fi][pos.se]=0;
}

void solve(pii pos) {
	um.clear(); lv.clear(); rv.clear(); path.clear(); memset(vis,0,sizeof vis);
	dfsl(pos,1);
	path.clear(); memset(vis,0,sizeof vis);
	dfsr(pos,1);
}
int last;
int main() {
	lv.reserve(500000);
	rv.reserve(500000);
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
				last=ans;
				solve(mp(i,j));
				for(auto x:lv) {
					Count(x);
				}
			}
		}
	}
	cout<<ans<<endl;
}
