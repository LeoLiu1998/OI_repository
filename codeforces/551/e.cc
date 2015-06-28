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


const int maxn=500000;
const int maxb=800;
int a[maxn];
int n,T,cmd;
#define pv first
#define po second
#define mp make_pair
/*bool operator < (const pair<int,int> &a, const pair<int,int> &b)
{
	if(a.pv==b.pv)	return a.po<b.po;
	return a.pv<b.pv;
}*/
namespace solution {
	int bn,bl;
	struct B {
		int lazy;
		pair<int,int> ord[maxb];
		B() {lazy=0;}
	}blo[maxb];
	inline int getL(int x) {
		return (x-1)*bl+1;
	}
	inline int getR(int x) {
		if(x==bn)
			return n;
		return x*bl;
	}
	inline void pb(){
#ifdef YGHDEBUG
		cout<<"n:" <<bn<<" l:"<<bl<<endl;
		for(int i=1;i<=bn;++i) {
			for(int j=1;j<=bl;++j) {
				cout<<blo[i].ord[j].pv<<" "<<blo[i].ord[j].po<<" ";
			}
			cout<<endl;
		}
#endif
	}
	void init() {
		bn=sqrt(n);
		bl=n/bn + (n%bn !=0);
		int cnt=1;
		rep(i,1,bn,1) {
			int r=getR(i);
			int j=0;
			for(j=1;j<=bl&&cnt<=n;++j,++cnt) {
				blo[i].ord[j]=mp(a[cnt],cnt);
			}
			sort(blo[i].ord+1,blo[i].ord+j);
		}
		pb();
	}
	inline int getB(int x) {
		return (x/bl)+(x%bl!=0);
	}
	void Reset(int x) {
		int l=getL(x),r=getR(x);
		int i,j;
		for(i=1,j=l;j<=r;++i,++j) {
			blo[x].ord[i]=mp(a[j],j);
		}	
		sort(blo[x].ord+1,blo[x].ord+j);
		return ;
	}
	void Modify(int l,int r,int x) {
		if(l>r)
			swap(l,r);
		int lb=getB(l),rb=getB(r);
		if(lb==rb) {
			rep(i,l,r,1) {
				a[i]+=x;
			}
			Reset(lb);
			pb();
			return; 
		}
		int lbl=getL(lb),lbr=getR(lb),rbl=getL(rb),rbr=getR(rb);
		rep(i,lbl,rbr,1) {
			a[i]+=x;
		}
		Reset(lb);
		rep(i,rbl,rbr,1) {
			a[i]+=x;
		}
		Reset(rb);
		rep(i,lb+1,rb-1,1) {
			blo[i].lazy+=x;
		}
		pb();
		
	}
	int findl(int x) {
		for(int i=1;i<=bn;++i) {
			int p=lower_bound(blo[i].ord+1,blo[i].ord+(getR(i)-getL(i)+1)+1,mp(x-blo[i].lazy,0))-blo[i].ord;
			if(blo[i].ord[p].pv-blo[i].lazy==x){
#ifdef YGHDEBUG
				cout<<"lp:"<<p<<endl;
#endif
				return blo[i].ord[p].po;
			}
		}
		return n+1;
	}
	int findr(int x){
		for(int i=bn;i>=1;--i) {
			int p=upper_bound(blo[i].ord+1,blo[i].ord+(getR(i)-getL(i))+2,mp(x-blo[i].lazy,n+1))-blo[i].ord;
			cout<<"r!"<<p<<endl;
			if(blo[i].ord[p-1].pv-blo[i].lazy==x) {
#ifdef YGHDEBUG
				cout<<"rp: "<<p<<endl;
#endif
				return blo[i].ord[p-1].po;
			}
		}
		return n+1;
	}
	int Query(int x) {
		int l=findl(x),r=findr(x);
#ifdef YGHDEBUG
		cout<<"l "<<l<<"  r "<<r<<endl;
#endif
		if(l==n+1)
			return -1;
		else 
			return (r-x);
	}
}



int main() {
	R(n);R(T);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	solution::init();
	while(T--) {
		R(cmd);
		if(cmd==1) {
			int l,r,x;
			R(l); R(r); R(x);
			solution::Modify(l,r,x);
		} else {
			int y;
			R(y);
			Pn(solution::Query(y));
		}
	};
	return 0;
}
