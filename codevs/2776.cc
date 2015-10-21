//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
/*	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;*/
	scanf("%d",&x);
}
const int maxn=205;
int match[maxn];
bool vis[maxn];
int mape[maxn][maxn];
int n,m;
bool dfs(int pos) {
	rep(i,1,m,1) {
		if(mape[pos][i]&&(!vis[i])) {
			vis[i]=1;
			if((!match[i])||dfs(match[i])) {
				match[i]=pos;
				return 1;
			}
		}
	}
	return 0;
}
void Hungary() {
	int ans=0;
	for(int i=1;i<=n;++i) {
		memset(vis,0,sizeof(vis));
		if(dfs(i)) 
			ans++;
	}
	Pn(ans);
}

int main() {
	R(n); R(m);
	for(int i=1;i<=n;++i) {
		int k; R(k);
		mape[i][k]=1;
		while(k) {
			mape[i][k]=1;
			R(k);
		}
	}
	Hungary();
} 
