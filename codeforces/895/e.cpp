//This sourcecode is under GPLv3
// yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
struct Blo{
	double sum,mul,add;
}blo[500];
int blon;
int blol;
double a[(int)2e5+20];
int n,m;

inline int getIdx(int x) {
	return ((x-1)/blol)+1;
}

inline int getL(int x) {
	return (x-1)*blol+1;
}

inline int getR(int x) {
	return x*blol > n ? n: x*blol ;
}

inline bool Ori(int idx) {
	return fabs(blo[idx].mul-1)<1e-8&&fabs(blo[idx].add)<1e-8;
}

inline void pushdown(int x) {
	if(Ori(x))
		return ;
	int l=getL(x),r=getR(x);
	blo[x].sum=0;
	rep(i,l,r,1) {
		a[i]=a[i]*blo[x].mul+blo[x].add;
		blo[x].sum+=a[i];
	}
	blo[x].mul=1; blo[x].add=0;
}

inline double Query(int l,int r) {
	int lb=getIdx(l),rb=getIdx(r);
	double ret=0;
	if(lb==rb) {
		if(l==getL(lb)&&r==getR(lb)) 
			if(Ori(lb)) return blo[lb].sum;
			else return blo[lb].sum*blo[lb].mul+(r+1-l)*blo[lb].add;
		pushdown(lb);
		rep(i,l,r,1) 
			ret+=a[i];
		return ret;
	}
	rep(i,lb+1,rb-1,1) {
		if(Ori(i)) ret+=blo[i].sum;
		else ret+=blo[i].sum*blo[i].mul+(getR(i)+1-getL(i))*blo[i].add;
	}
	return Query(l,getR(lb))+ret+Query(getL(rb),r);
}

void Update(int idx,double mul,double add) {
	blo[idx].add=blo[idx].add*mul+add;
	blo[idx].mul*=mul;
}

void Build(int idx) {
	int l=getL(idx),r=getR(idx);
	blo[idx].sum=0;
	rep(i,l,r,1)
		blo[idx].sum+=a[i];
	blo[idx].mul=1;
	blo[idx].add=0;
}

void ModBlo(int l,int r,double mul,double add) {
	int lb=getIdx(l),rb=getIdx(r);
	if(lb==rb) {
		if(l==getL(lb)&&r==getR(lb)) {
			Update(lb,mul,add);
			return ;
		}
		pushdown(lb);
		rep(i,l,r,1) {
			a[i]=a[i]*mul+add;
		}
		Build(lb);
		return ; 
	}
	ModBlo(l,getR(lb),mul,add);
	ModBlo(getL(rb),r,mul,add);
	rep(i,lb+1,rb-1,1)
		Update(i,mul,add);
}

void Modify(int l1,int r1,int l2,int r2) {
	int len1=(r1-l1)+1;
	int len2=(r2-l2)+1;
	double s1=Query(l1,r1);
	double s2=Query(l2,r2);
	ModBlo(l1,r1,1.0*(len1-1)/len1,s2/len2/len1);
	ModBlo(l2,r2,1.0*(len2-1)/len2,s1/len1/len2);
}

void Build() {
	blol=sqrt(n);
	cerr<<blol<<endl;
	blon=(n+(blol-1))/blol;
	rep(i,1,n,1) {
		blo[getIdx(i)].sum+=a[i];
		blo[getIdx(i)].mul=1;
		blo[getIdx(i)].add=0;
	}
}

int main() {
	R(n); R(m);
	rep(i,1,n,1) {
		int t; R(t);
		a[i]=t;
	}
	Build();
	while(m--) {
		int cmd; R(cmd);
		if(cmd==1) {
			int l1,l2,r1,r2;
			R(l1); R(r1); R(l2); R(r2);
			Modify(l1,r1,l2,r2);
		} else {
			int l,r; R(l); R(r);
			printf("%.8f\n",Query(l,r));
		}
	}
}


