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
#define PROB "lightsout"
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
pii operator - (const pii &a,const pii &b) {
	pii ret; ret.fi=a.fi-b.fi;
	ret.se=a.se-b.se;
	return ret;
}
int Dist(pii a,pii b) {
	int ret=abs(a.first-b.first)+abs(a.se-b.se);
	return ret;
}
int ans=0;
pii zero(0,0);
int dist[205][205];
pii poi[205];
pii del[205];// del[i] is delta poi[i-1] poi[i];
int step[205];
int n;
int curTravel;
void Floyed() {
	memset(dist,0x3f,sizeof dist);
	dist[1][n]=dist[n][1]=Dist(poi[n],poi[1]);
	for(int i=2;i<=n;++i) {
		dist[i][i-1]=dist[i-1][i]=Dist(poi[i-1],poi[i]);
	}
	for(int i=1;i<=n;++i) dist[i][i]=0;
	for(int k=1;k<=n;++k) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) {
				if(dist[i][j]>dist[i][k]+dist[k][j]) {
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
}
int MovPos(int p,int s) {
	int k=s+p; k%=n;
	if(!k) k=n;
	return  k;
}
pii Mov(int p,int s) {
	int k=s+p; k;
	k%=n; if(!k) k=n;
	return del[k];
}

static inline
int Circle(int &a) {
	a=(a+n)%n;
	if(!a) a=n;
	return a;
}
int Deg(int k) {
	int p1=k-1,p2=k,p3=k+1;
	Circle(p1); Circle(p2); Circle(p3);
	if(poi[p1].fi==poi[p2].fi&&poi[p2].fi==poi[p3].fi) return 180;
	if(poi[p1].se==poi[p2].se&&poi[p2].se==poi[p3].se) return 180;
//	if(poi[p1].fi==poi[p2].fi) return 90;
	return 90;
}
int Diffpos(int a,int b) {
	if(Deg(a)!=Deg(b)||(a==1)||(b==1)) return 0;
	for(int i=1;i<=n;++i) {
		pii ca=Mov(a,i),cb=Mov(b,i);
		int dca=Dist(ca,zero),dcb=Dist(cb,zero);
		int cap=MovPos(a,i),cbp=MovPos(b,i);
		int da=Deg(cap),db=Deg(cbp);
		if((dca!=dcb)||(da!=db)||(cap==1)||(cbp==1)) return i;
	}
	cout<<a<<" "<<b<<endl;
	assert(0);
}
int Check(int k) {
	int s=step[k];
	int p1=k,p2=MovPos(k,s);
	if(dist[p1][p2]+dist[p2][1]>curTravel) {
		curTravel=dist[p1][p2]+dist[p2][1];
//		ans=curTravel-dist[p1][1];
	}
	return dist[p1][p2]+dist[p2][1]-dist[p1][1];
}
void PRE() {
	del[1]=poi[1]-poi[n];
	for(int i=2;i<=n;++i) {
		del[i]=poi[i]-poi[i-1];
	}
	for(int i=1;i<=n;++i) {
		int cur=0;
		for(int j=1;j<=n;++j) {
			if(i==j) continue;
			cur=max(cur,Diffpos(i,j));
		}
		step[i]=cur;
		step[i]=min(step[i],n+1-i);
	}	
	Floyed();
}
int main() {
	Redirect();
	R(n);
	for(int i=1;i<=n;++i) {
		R(poi[i].fi); R(poi[i].se);
	}
	PRE();
	for(int i=2;i<=n;++i) {
		int temp= Check(i);
		if(temp>ans) {
			ans=temp;
			cout<<i<<endl;
		}
		//	ans=max(ans,temp);
	}
	cout<<ans<<endl;
}
