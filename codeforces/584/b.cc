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

const int maxn=1000;
int a[maxn];
bool have[maxn];
int n;
int cur_pi;
int ans=0;
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	while(cur_pi!=n) {
		if((ans&1)==0) {
			for(int i=1;i<=n;++i) {
				if(cur_pi>=a[i]&&(!have[i])) {
					cur_pi++;
					have[i]=1;
				}
			}
		} else {
			for(int i=n;i>=1;--i) {
				if(cur_pi>=a[i]&&(!have[i])) {
					cur_pi++;
					have[i]=1;
				}
			}
		
		}
		if(cur_pi==n) break;
		ans++;
	}
	Pn(ans);
}
