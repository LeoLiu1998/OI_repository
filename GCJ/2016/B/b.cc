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
int ans[53][53];
int a[103][53];
bool vis[103];
int temp[2][53];
bool Check(int a[], int b[], int l,int r) {
	for(int i=l;i<=r;++i) {
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
int n;
vector<int> mi,ma;
void Deal(int x,int l,int r) {
	mi.clear(); ma.clear();
	for(int j=1;j<=2*n-1;++j) {
		if(vis[j]) continue;
		if((!mi.size())||a[j][l]<a[mi[0]][l]) {	
			mi.clear();
			mi.pb(j);
		} else if(a[j][l]==a[mi[0]][l]){
			mi.pb(j);
		}
		if((!ma.size())||a[j][r]>a[ma[0]][r]) {
			ma.clear();
			ma.pb(j);
		} else if(a[j][r]==a[ma[0]][r]) {
			ma.pb(j);
		}
	}
	int miv=a[mi[0]][l];
	int mav=a[ma[0]][r];
	if(x==1) {
		ans[l][l]=miv;
		return ;
	}
	if(mi.size()==2) {
		for(int i=l;i<=r;++i) {
			ans[l][i]=a[mi[0]][i];
			ans[i][l]=a[mi[1]][i];
		}
		vis[mi[0]]=vis[mi[1]]=1;
		Deal(x-1,l+1,r);
		for(int i=0;i<53;++i) {
			temp[0][i]=ans[r][i];
			temp[1][i]=ans[i][r];
		}
		if(!(Check(a[ma[0]],temp[0],l,r)&&Check(a[ma[0]],temp[1],l,r))) {
			for(int i=l;i<=r;++i) {
				swap(ans[l][i],ans[i][l]);
			}
		}
	} else {
		for(int i=l;i<=r;++i) {
			ans[r][i]=a[ma[0]][i];
			ans[i][r]=a[ma[1]][i];
		}
		vis[ma[0]]=vis[ma[1]]=1;
		Deal(x-1,l,r-1);
		for(int i=0;i<53;++i) {
			temp[0][i]=ans[l][i];
			temp[1][i]=ans[i][l];
		}
		if(!(Check(a[mi[0]],temp[0],l,r)&&Check(a[mi[0]],temp[1],l,r))) {
			for(int i=l;i<=r;++i) {
				swap(ans[r][i],ans[i][r]);
			}
		}
	}
}
void GetAns(int x) {
	memset(vis,0,sizeof vis);
	printf("Case #%d: ",x);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=2*n-1;++j) {
			if(vis[j]) continue;
			if(Check(ans[i],a[j],1,n)) {
				vis[j]=1;
				goto Next;
			}
		}
		for(int j=1;j<n;++j) {
			Ps(ans[i][j]);
		}
		Pn(ans[i][n]);
		return ;
Next:		printf("");
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			temp[0][j]=ans[j][i];
		}
		for(int j=1;j<=2*n-1;++j) {
			if(vis[j]) continue;
			if(Check(temp[0],a[j],1,n)) {
				vis[j]=1;
				goto Nex;
			}
		}
		for(int j=1;j<n;++j) {
			Ps(temp[0][j]);
		}
		Pn(temp[0][n]);
		return ;
Nex:
		printf("");
	}
}
int main() {
	int T; R(T);
	for(int i=1;i<=T;++i) {
		R(n); memset(ans,0,sizeof ans); 
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		memset(temp,0,sizeof temp);
		for(int j=1;j<=2*n-1;++j) {
			for(int k=1;k<=n;++k) {
				R(a[j][k]);
			}
		}
		Deal(n,1,n);
/*		for(int k=1;k<=n;++k) {
			for(int j=1;j<=n;++j) {
				printf("%4d",ans[k][j]);
			}
			puts("");
		}*/
		GetAns(i);
	}
	
}

