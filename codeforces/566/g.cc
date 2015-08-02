//This sourcecode is under GPLv3
//yeguanghao
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
typedef pair<int,int> pi;
int n,m;
int x,y;
#define pb push_back
#define mp make_pair
inline pi get(){
	int a,b;
	R(a); R(b);
	return mp(a,b);
}
#define pa first
#define bp second
int amaf,amas,bmaf,bmas,as,bs;
vector<pi > va,vb;
int main(){
	R(n); R(m);
	R(x); R(y);
	for(int i=1;i<=n;++i) {
		pi cur=get();
		amaf=max(amaf,cur.pa);
		amas=max(amas,cur.bp);
		as=max(as,cur.pa+cur.bp);
		va.pb(cur);
	}
	for(int i=1;i<=m;++i) {
		pi cur=get();
		bmaf=max(bmaf,cur.pa);
		bmas=max(bmas,cur.bp);
		bs=max(bs,cur.pa+cur.bp);
		vb.pb(cur);
	}
	if(amaf>=bmaf||amas>=bmas) {
		puts("Max");
		return 0;
	}
	puts(as>=bs ? "Max": "Min");
}
