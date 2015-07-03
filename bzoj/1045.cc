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

const int maxn=1000010;
int c[maxn];
int a[maxn];
int n;
pair<int,int> mid;
#define mp make_pair
unsigned long long cave;
unsigned long long ave;
int main() {
	R(n);
	for(int i=1;i<=n;++i){
		R(a[i]);
		ave+=a[i];
	}
	ave/=n;
	for(int i=1;i<n;++i){
		c[i]=c[i-1]+a[i]-ave;
	}
	sort(c,c+n);
	int cmid=c[n>>1];
	long long ans=0;
	for(int i=0;i<n;++i) ans+=abs(cmid-c[i]);
	cout<<ans<<endl;
}
