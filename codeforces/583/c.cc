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
const int maxn=505;
int a[maxn*maxn];
map<int,int> fre;
int n;
vector<int> ans;
map<int,int>::iterator mit;
inline void check() {
	if(mit->second==0) {
		fre.erase(mit);
	}
}
int gcd(int a,int b) {
	if(a%b==0) return b;
	return gcd(b,a%b);
}
void g_remove(int a,int b) {
	int gc=gcd(a,b);
	fre[gc]-=2;
	mit=fre.find(gc);
	check();
}
int main() {
	R(n);
	for(int i=1;i<=n*n;++i) {
		R(a[i]);
		fre[a[i]]++;
	}
	mit=fre.end();
	mit--;
	ans.pb((*mit).first);
	mit->second--;
	check();
	while(ans.size()!=n) {
		mit=fre.end();
		mit--;
		int cur=mit->first;
		mit->second--;
		check();
		for(int i=0;i<(int)ans.size();++i) {
			g_remove(cur,ans[i]);
		}
		ans.pb(cur);
	}
	for(int i=0;i<(int)ans.size();++i) {
		Ps(ans[i]);
	}
	puts("");
}


