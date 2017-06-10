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
inline void R(long long &x) {
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
const int mod=1e9+9;
const int maxn=155;
struct Matrix {
	int a[maxn][maxn];
}ans,cur;
int n;
Matrix operator *(const Matrix &a, const Matrix &b) {
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			ll tmp=0;
			for(int k=1;k<=n;++k) {
				tmp+=(ll)a.a[i][k]*b.a[k][j];
				tmp%=mod;
			}
			ret.a[i][j]=tmp;

		}
	}
	return ret;
}
//1-11
ll s,m,d;
int GP(int t,int v) {
	return (v-1)*m+t;
}
ll an1;
int ori[15][15];
ll dp[110][110];

void print() {
	for(int q=1;q<=m;++q) {
		for(int i=1;i<=m;++i) {
			for(int j=1;j<=m;++j) {
				Ps(ans.a[i][GP(j,q)]);
			}
			puts("");
		}
		puts("");
	}
}
void printc() {
	for(int i=0;i<=m;++i) {
		for(int j=0;j<=m;++j) {
			Ps(cur.a[i][GP(j,1)]);	
		}
		puts("");
	}
}


void qpow(ll k) {
	for(int i=0;i<maxn;++i) {
		ans.a[i][i]=1;
	}
	while(k) {
		if(k&1) {
			ans=ans*cur;
			print();
			puts("");
		}
		k>>=1;
		cur=cur*cur;
	}
}
int main() {
	R(s); R(m); R(d);
	for(int i=1;i<=m;++i) dp[i][i]=1;
	for(int i=2;i<=m;++i) {
		for(int j=1;j<=m&&j<=i;++j) {
			for(int k=1;k<=m;++k) {
				if(abs(k-j)>d) continue;
				dp[i][j]+=dp[i-j][k];
				dp[i][j]%=mod;
			}
		}
	}
	if(s<=m) {
		ll an=0;
		for(int i=1;i<=m;++i) {
			an+=dp[s][i];
			an%=mod;
		}
		cout<<an<<endl;
		return 0;
	}
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=m;++j) {
			if(abs(i-j)<=d) {
				ori[i][j]=j;
			}
		}
	}
	n=m*10;
	memset(cur.a,0,sizeof(cur.a));
	for(int i=1;i<=m;++i) {
		for(int j=2;j<=10;++j) {
			cur.a[GP(i,j)][GP(i,j-1)]=1;
		}
	}
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=m;++j) {
			if(!ori[i][j]) continue;
			cur.a[i][GP(j,ori[i][j])]=1;
		}
	}
	s-=m;
	qpow(s);
	ll an=0;
#ifdef YGHDEBUG
	print();
#endif
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=m;++j) {
			an+=dp[m][i]*ans.a[i][j];
			an%=mod;
		}
	}
//	cout<<an<<endl;
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=m;++j) {
			for(int k=1;k<=m;++k) {
				//an1+=(ll)ans.a[i][GP(j,k)]*dp[m+1-k][i];
				an1+=dp[m+1-k][i]*ans.a[i][GP(j,k)];
				an1%=mod;
/*				for(int l=1;l<=m;++l) {
					if(abs(j-k)<=d&&(i-k>=0)) {
						an2+=dp[i-k+1][j]*ans.a[k][GP(l,m-i+1)];// s-(s-m+i)
						an2%=mod;
					}
				}
				*/
			}
		}
	}
	cout<<an1<<endl;
}

