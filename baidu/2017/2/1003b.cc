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


int ans=0; 
bool vis[50][4];
int n;

pii Move(int k,pii pos) {
	pii ret=pos;
	if(k==0) {
		ret.fi+=1;
		return ret;
	} else if(k==1) {
		ret.fi-=1;
		return ret;
	} else if(k==2) {
		ret.se+=1;
		return ret;
	} else if(k==3){
		ret.se-=1;
		return ret;
	} else if(k==4) {
		ret.fi+=1;
		ret.se+=1;
		return ret;
	} else if(k==5) {
		ret.fi-=1;
		ret.se+=1;
		return ret;
	} else if(k==6) {
		ret.fi+=1;
		ret.se-=1;
		return ret;
	} else  {
		ret.fi-=1;
		ret.fi-=1;
		return ret;
	}
}

void dfs(int k,pii pos) {
	if(k==2*n) {
		ans++;
		return ;
	}
	for(int i=0;i<8;++i) {
		pii nex=Move(i,pos);
		if((nex.fi>=0)&&(nex.se>=0)&&(!vis[nex.fi][nex.se])) {
			vis[nex.fi][nex.se]=1;
			dfs(k+1,nex);
			vis[nex.fi][nex.se]=0;
		}
	}
}

int main() {
	R(n);	
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=1;++j) {
			memset(vis,1,sizeof vis);
			for(int k=1;k<=n;++k) {
				vis[k][0]=vis[k][1]=0;
			}
			vis[i][j]=1;
			dfs(1,mp(i,j));
			vis[i][j]=0;
			cerr<<ans<<endl;
		}
	}
	cout<<ans<<endl;
}

