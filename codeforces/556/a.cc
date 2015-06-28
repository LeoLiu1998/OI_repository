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
const int maxn=200020;
vector<pair<int,int> >a;
#define pv first
#define pn second
#define mp make_pair
#define pb push_back
int n;
int cnt=1;
int rem=0;
bool ok=0;
int main() {
	R(n);
	a.reserve(maxn);
	a.push_back(mp(-1,0));
	char c;
	rep(i,1,n,1) {
		c=getchar();
		c-=48;
		if(c==a[cnt-1].pv) a[cnt-1].pn++;
		else {
			a.pb(mp(c,1));
			cnt++;
		}
	}
	int ans=0;
	a.erase(a.begin());
	rep(i,0,a.size()-1,1) {
		if(a[i].pv==1){
			ans+=a[i].pn;
		} else {
			ans-=a[i].pn;
		}
	}
	ans=abs(ans);
	Pn(ans);
}
