//Fuck 
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
const int maxn=300500;
int vis[maxn];
int ans=0;
stack<int> s;
char cmd[20];
int n;
int cur=0;
void Remove() {
	if(s.size()&&(s.top()==cur+1)) {
		s.pop();
		++cur;
		return ;
	} else if((!s.size())&&(vis[cur+1]==1)) {
		vis[++cur]=0;
	} else{
		while(s.size()) {
			vis[s.top()]=1;
			s.pop();
		}
		ans++;
		vis[++cur]=0;
	}
}
int main() {
	R(n);
	for(int i=1;i<=2*n;++i) {
		int x;
		scanf("%s",cmd+1);
		if(cmd[1]=='a') {
			R(x);
			s.push(x);
		} else {
			Remove();
		}
	}
	Pn(ans);
}

