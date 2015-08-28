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
const int maxn=100010;
int a[maxn];
int cnt[maxn];
int pre[maxn];
bool use[maxn];
int pos[maxn];
int n;
int ans[maxn];
int main() {
	R(n);
	rep(i,1,n,1) {
		R(a[i]);
		if(a[i]>=1&&a[i]<=n&&(!use[a[i]])) {
			ans[i]=a[i];
			use[a[i]]=1;
		}
	}
	int cur=1;
	rep(i,1,n,1) {
		if(!ans[i]) {
			while(use[cur]) cur++;
			ans[i]=cur;
			use[cur]=1;
		}
	}
	rep(i,1,n,1) Ps(ans[i]);
	puts(" ");
}
