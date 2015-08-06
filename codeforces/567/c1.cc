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
const int maxn=200050;
map<int,vector<int> > pos;
int a[maxn];
int k;
int n;
int dp[3][maxn];//dp[2]
//change dp[3][maxn] to prefix
#define pb push_back
#define mp make_pair
vector<int> v;
long long ans=0;
void solve(int p) {
	if((a[p]%k)!=0) 
		return ;
	int fi=a[p]/k;
	for(int i=0;i<pos[fi].size();++i) {
		if(pos[fi][i]>=p) break;
		dp[1][p]++;
		ans+=dp[1][pos[fi][i]];
	} 
}
void solve2(int p) {
	if((a[p]%k)!=0) {
		return ;
	}
	int fi=a[p]/k;
	//cout<<pos[fi][pos[fi].size()-1]<<endl;
	ans+=dp[1][pos[fi][pos[fi].size()-1]];
	dp[1][pos[fi][pos[fi].size()-1]]=0;
}
int main() {
	R(n); R(k);
	for(int i=1;i<=n;++i) {
		R(a[i]);
		int fi=a[i]/k;
		if(pos.count(a[i])) {
			pos[a[i]].pb(i);
		//	dp[1][i]+=dp[1][pos[a[i]][pos[a[i]].size()-2]];
		} else {
			v.clear();
			v.pb(i);
			pos.insert(mp(a[i],v));
		}
		int temp=lower_bound(pos[fi].begin(),pos[fi].end(),i)-pos[fi].begin();
	//	dp[1][i]+=temp;
	//	cout<<temp<<endl;
	}
	for(int i=1;i<=n;++i) {
		solve(i);	
	}
	cout<<ans<<endl;
}

