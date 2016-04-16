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
int n,a,b,T;
int ori[100050];
int pre[100050],succ[100050];
int rmax;
int ans=0;

int Search(int k) {
	int r=n+1;
	int l=2;
	if(succ[2]<k) return 2;
	if(k<=succ[n]) return n+1;
	int mid;
	while(r>l+1) {
		mid=(l+r)>>1;
		if(succ[mid]<=k) {
			r=mid;	
		} else {
			l=mid;
		}
	}
	return r;
}
int pre2[100500],succ2[100500];
int Search2(int k) {
	int r=n,l=1;
	if(succ2[2]>k) return 1;
	if(succ2[n]<=k) return n+1;
	int mid;
	while(r>l+1) {
		mid=(l+r)>>1;
		if(succ2[mid]<=k) {
			l=mid;
		} else {
			r=mid;
		}
	}
	return l;
}
int Solve2() {
	int ret=0;
	memset(pre2,0x3f,sizeof pre2);
	memset(succ2,0x3f,sizeof succ2);
	int lmax;
	pre2[n]=pre[1]+succ[n]+a;;
	for(int i=n-1;i>=1;--i) {
		pre2[i]=pre2[i+1]+ori[i]*b+a+1;
		if(pre2[i]>T) {
			lmax=i+1;
			break;
		}
	}
	succ2[1]=0;
	succ2[2]=ori[2]*b+1;
	for(int i=3;i<=n;++i) {
		succ2[i]=succ2[i-1]+ori[i]*b+a+1;
	}
	for(int i=n;i>=lmax;--i) {
		int remain=T-pre2[i];	
		remain-=(n-i+2)*a;
		if(remain<=0) {
			ret=max(ret,n+1-n);
			continue;
		}
		int pos=Search2(remain);
		ret=pos+(n+1-i);
	}
	return ret;
}
int main() {
	R(n); R(a); R(b); R(T);
	for(int i=1;i<=n;++i) {
		char cmd=0; while(!isalpha(cmd)) {
			cmd=getchar();	
		}
		ori[i]=(cmd=='w');
	}
	memset(pre,0x4f,sizeof pre);
	memset(succ,0x4f,sizeof succ);
	succ[n+1]=0;
	pre[1]=b*ori[1]+1;
	if(pre[1]>T) {
		cout<<0<<endl;
		return 0;
	}
	for(int i=2;i<=n+1;++i) {
		pre[i]=pre[i-1]+a+ori[i]*b+1;
		if(pre[i]>T) {
			rmax=i-1;
			break;
		}
	}
	if(pre[n]<T) {
		cout<<n<<endl;
		return 0;
	}
	succ[n]=ori[n]*b+1;
	for(int i=n-1;i>1;--i) {
		succ[i]=succ[i+1]+a+ori[i]*b+1;
	}
	for(int i=1;i<=rmax;++i) {
		int remain=T-pre[i];
		remain-=i*a;
		if(remain<=0) {
			ans=max(ans,i);
			continue;
		}
		int pos=Search(remain);
		ans=max(n-pos+1+i,ans);
	}
	ans=max(ans,Solve2());
	ans=min(ans,n);
	cout<<ans<<endl;
}

