//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct Man {
	int v,f;
	vector<int> son;
	int dp[2];
}man[6005];
int n;
int x,y;
int root;
#define pb push_back
void solve(int cur ) {
	Man &k=man[cur];
	if(!k.son.size()){
		man[cur].dp[0]=0;
		man[cur].dp[1]=man[cur].v;
		return ;
	} else {
		for(int i=0;i<k.son.size();++i) {
			solve(k.son[i]);
			k.dp[0]+=max(man[k.son[i]].dp[1],man[k.son[i]].dp[0]);
			k.dp[1]+=man[k.son[i]].dp[0];
		}
		k.dp[1]+=k.v;
	}
	return ;
}
int main() {
	R(n);
	rep(i,1,n,1) R(man[i].v);
	rep(i,1,n-1,1) {
		R(x); R(y);
		man[y].son.pb(x);
		man[x].f=y;
	}
	for(int i=1;i<=n;++i) {
		if(man[i].f==0) root=i;
	}
	solve(root);
	cout<<max(man[root].dp[0],man[root].dp[1])<<'\n';
}

