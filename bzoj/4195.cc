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
#define mp make_pair
#define pb push_back
map<int,int> f;
vector<pair<int,int> >a;
int T;
int getf(int x) {
	if(!f.count(x)) {
		f.insert(mp(x,x));
		return x;
	}
	if(f[x]==x) return x;
	else f[x]=getf(f[x]);
	return f[x];
}
void Merge(int a,int b) {
	if(a>b) swap(a,b);
	int fa=getf(a),fb=getf(b);
	f[fa]=f[fb]=min(fa,fb);
}
#define ia first
#define ib second
bool check(){
	for(int i=0;i<a.size();++i) {
		int fa=getf(a[i].ia),fb=getf(a[i].ib);
		if(fa==fb) return 0;
	}
	return 1;
}
int main() {
	R(T);
	while(T--) {
		f.clear();
		a.clear();
		int n;
		R(n);
		register int A,b,v;
		while(n--) {
			R(A); R(b); R(v);
			if(v) {
				Merge(A,b);	
			} else {
				a.pb(mp(A,b));
			}
		}
		if(check()) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
}
