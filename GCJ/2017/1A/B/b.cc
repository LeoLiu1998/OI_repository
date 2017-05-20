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
double eps=1e-7;
int n,p;
int a[55];
int pa[55][55];
bool vis[55][55];
int l[55][55];
int r[55][55];
vector<int> buff;
int al,ar;
int ans=0;
void Check(int po, int ro) {
	double amt=l[po][ro]*a[po];
	int cnt=0;
	while((pa[po][ro]<amt*0.9)||pa[po][ro]>amt*1.1) {
		l[po][ro]++;
		amt=l[po][ro]*a[po];
		cnt++;
		if(cnt>100) {
			l[po][ro]=r[po][ro]=-1;
			return ;
		}
	}
	cnt=0;
	amt=r[po][ro]*a[po];
	while((pa[po][ro]<amt*0.9)||pa[po][ro]>amt*1.1) {
		r[po][ro]--;
		amt=r[po][ro]*a[po];
		cnt++;
		if(cnt>100) {
			r[po][ro]=l[po][ro]=-1;
			return ;
		}
	}
}
int main() {
	int T; R(T);
	for(int i=1;i<=T;++i) {
		R(n); R(p);
		int ans=0;
		memset(vis,0,sizeof vis);
		memset(pa,0,sizeof pa);
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		memset(a,0,sizeof a);
		for(int j=1;j<=n;++j) {
			R(a[j]);		
		}
		for(int j=1;j<=n;++j) {
			for(int k=1;k<=p;++k) {
				R(pa[j][k]);
			}
			sort(pa[j]+1,pa[j]+1+p);
			l[j][0]=INT_MAX;
			for(int k=1;k<=p;++k) {
				r[j][k]= 1.0*pa[j][k]/a[j]/0.9;
				l[j][k]=1.0*pa[j][k]/a[j]/1.1;
				Check(j,k);			
				if(l[j][k]==-1) continue;
				l[j][0]=min(l[j][0],l[j][k]);
				r[j][0]=max(r[j][0],r[j][k]);
			}	
			
		}
		al=l[1][0];
		ar=r[1][0];
		for(int j=2;j<=n;++j) {
			al=max(al,l[j][0]);
			ar=min(ar,r[j][0]);
		}
		if(ar<al) {
			goto END;
		}
		for(int j=al;j<=ar;++j) {
			int cur=INT_MAX;
			for(int k=1;k<=n;++k) {
				int cnt=0;
				for(int q=1;q<=p;++q) {
					if(l[k][q]==-1) continue;
					if((!vis[k][q])&&j<=r[k][q]&&j>=l[k][q]) {
						cnt++;
					}
				}
				cur=min(cur,cnt);
			}
			if(cur<=0) continue;
			for(int k=1;k<=n;++k) {
				int cnt=0;
				for(int q=1;q<=p;++q) {
					if((!vis[k][q])&&j<=r[k][q]&&j>=l[k][q]) {
						cnt++;
						vis[k][q]=1;
						if(cnt==cur) break;
					}
				}
			}
			ans+=cur;
		}
		
END:
		printf("Case #%d: %d\n",i,ans);
	}
}

