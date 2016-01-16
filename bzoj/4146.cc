//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll ans=0;
int n,k;
int cnt[2000500];
int main() {
	R(n);
	while(n--) {
		R(k);
		cnt[k]++;
	}
	for(int i=1;i<=2000000;++i) {
		if(cnt[i]!=0) {
			ans+= (ll)(cnt[i])*(cnt[i]-1);
			for(int j=2;j*i<=2000000;++j) 
				ans+=(ll)cnt[i]*cnt[i*j];
		}
	}
	cout<<ans<<endl;
}

