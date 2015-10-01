//This sourcecode is under GPLv3
//yeguanghao
#include<cstdio>
#include<climits>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=100000;
int a[maxn+5];
int num[maxn+5];
int n,m;
struct pii {
	int first,second;
	pii(int _f=0,int _s=0){first =_f; second=_s;}
};
pii make_pair(int a,int b) {
	pii ret(a,b);
	return ret;
}
pii bs1(int k) {// binary search return a[first]<k<=a[second] // a[first]<=k<a[second]
	int l=0,r=n+1;
	int mid;
	while(r-l>1) {
		mid=(l+r)>>1;
		if(a[mid]>k) r=mid;
		else if(a[m]<k) l=mid;
		else {
			l=mid; while(a[l]==k) l--;
			return mp(l,l+1);
		}
	}
	return mp(l,r);
}
pii bs(int k) {
	int l=0,r=n+1;
	int mid;
	while(r-l>1) {
		mid=(l+r)>>1;
		if(a[mid]>=k) r=mid;
		if(a[mid]<=k) l=mid;
	}
	if(a[l]==k) r=l;
	if(a[r]==k) l=r;
	return mp(l,r);
}
int b[(10000000)+10];
int pre[maxn+50];
int temp;
int main() {
	R(n); R(m);
	rep(i,1,n,1){ 
		R(temp);
		b[temp]++;
	}
	int cnt=0;
	for(int i=0;i<=1000000;++i)  
		if(b[i]) {
			a[++cnt]=i;
//			Ps(i);
			pre[cnt]=pre[cnt-1]+b[i];
		}		
	n=cnt;
//	puts("");
	a[n+1]=INT_MAX; a[0]=-INT_MAX;
	while(m--) {
		int p,q; R(p); R(q);
		p--;
		pii pp=bs(p),qp=bs(q);
		int ret=pre[qp.first]-pre[pp.first];
//		Ps(pp.first); Ps(pp.second); Ps(qp.first); Pn(qp.second);
		Pn(ret);
	}
}
