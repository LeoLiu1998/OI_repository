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
int c[200];
int cities;
int cm=0;
int n,m;
int cur;
int cur_m;
int main() {
	R(n); R(m);
	rep(i,1,m,1) {
		cm=1;
		cur_m=-34;
		rep(j,1,n,1) {
			R(cur);
			if(cur>cur_m)
				cm=j,cur_m=cur;
		}
		c[cm]++;
	}
	int ans=1;
	rep(i,2,n,1) {
		if(c[i]>c[ans]) ans=i;
	}
	Pn(ans);
}
