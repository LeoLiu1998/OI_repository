//Tarjan?
//Trajan  www
//SCC
//¡ü sb it is the hungary
//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define PROB "machine"
inline void R(int &x) {
	scanf("%d",&x);
	/*x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;*/
}
void Redirect() {
//	freopen(PROB".in","r",stdin);
//	freopen(PROB".out","w",stdout);
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
int n,m,k;
int mape[105][105];
int match[105];
bool visit[105];
bool dfs(int k) {
	for(int i=1;i<=m;++i) {
		if(mape[k][i]&&(!visit[i])) {
			visit[i]=1;
			if((!match[i])||dfs(match[i])) {
				match[i]=k;
				return 1;
			}
		}
	}
	return 0;
}
void Hungary() {
	int ans=0;
	rep(i,1,n,1) {
		memset(visit,0,sizeof(visit));
		ans=ans+dfs(i);
	}
	Pn(ans);
}
int main() {
	Redirect();
	while(~scanf("%d",&n)) {//R(n); R(m); R(k);
		R(m); R(k);
		memset(mape,0,sizeof(mape));
		memset(match,0,sizeof(match));
		rep(i,1,k,1) {
			int a,b;
			R(a); R(a); R(b);
			if(a>0&&b>0)
			mape[a][b]=1;
		}
		Hungary();
	}
}
