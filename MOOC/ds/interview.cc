//This sourcecode is under GPLv3
//yeguanghao
//#include <bits/stdc++.h>
#include <cstdio>
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
const int maxn=2005;
struct Node {
	int pre,nex,val;//iterate by nex means iterate by counter clockwise 
	//iterate by pre means iterate by clockwise
};
Node node[maxn];
int n,m;
int tot=1;
int cur_pos=1;
int Walk(int steps) {
	int ret=cur_pos;
	while(steps--) {
		ret=node[ret].nex;
	}
	return ret;
}
void insert(int l,int r) {
	int v; R(v);
	node[++tot].val=v;
	node[l].nex=tot;
	node[tot].pre=l;
	node[tot].nex=r;
	node[r].pre=tot;
	cur_pos=tot;
}
int main() {
	R(n); R(m);
	R(node[1].val); node[1].pre=1; node[1].nex=1;
	for(int i=2;i<=n;++i) {
		int step=m%tot;
		int pos=Walk(step);
//		Pn(node[pos].val);
		insert(node[pos].pre,pos);
	}
	for(int i=n,j=n;i;--i,j=node[j].pre) {
		Ps(node[j].val);
	}
}

