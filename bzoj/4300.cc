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

int n;
int f[35];
int main() {
	R(n);
	int ans=0;
	for(int i=1;i<=n;++i) {
		int x; R(x);
		int cur_max=0;
		for(int i=0;i<=31;++i) {
			if(x&(1<<i)) {
				cur_max=max(cur_max,f[i]+1);
			}
		}
		ans=max(ans,cur_max);
		for(int i=0;i<=31;++i) {
			if(x&(1<<i))
			f[i]=cur_max;
		}
	}
	Pn(ans);
} 
