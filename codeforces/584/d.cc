//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
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
inline void R(long long &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=10005;
typedef long long ll;
ll cop[maxn],record[maxn];
ll seg[305];
ll num[1005],temp[1005];
int n,t;
int top;
int Brute() {
	rep(i,1,t-1,1) {
		rep(j,1,n,1) cop[i*n+j]=cop[j];
	}
	n*=t;
	rep(i,1,n,1) {
		record[i]=1;
		rep(j,1,i-1,1) {
			if(cop[j]<=cop[i]) record[i]=record[i]> record[j]+1? record[i]: record[j]+1;
		}
	}
	int ret=0;
	rep(i,1,n,1) ret=ret> record[i] ? ret: record[i];
	return ret;
}

int Brute2() {
	rep(i,1,99,1) {
		rep(j,1,n,1) {
			cop[i*n+j]=cop[j];
		}
	}
	n*=100;
	rep(i,1,n,1) {
		record[i]=1;
		rep(j,1,i-1,1) {
			if(cop[j]<=cop[i]) record[i]=record[i]> record[j]+1? record[i]: record[j]+1;
		}
	}
	int ret=0;
	rep(i,1,n,1) rep(i,1,n,1) ret=ret> record[i] ? ret: record[i];
	return ret;
}

int main() {
	R(n); R(t);
	rep(i,1,n,1) {
		R(cop[i]);
	}
	if(t<=100){
		Pn(Brute());
		return 0;
	}
	rep(i,1,n,1) {
		seg[cop[i]]++;
	}
	ll ans=0;
	rep(i,1,300,1) ans=ans>seg[i] ? ans: seg[i];
	ll x=Brute2();
	cout<<x+ans*(t-100)<<endl;
}
