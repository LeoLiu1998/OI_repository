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
const int maxv=1000050;
int exi[maxv];
const int maxn=100050;
int a[maxn];
int n;
int ma=1;
int l=0;
int r;
vector<int> ans;
void check(int);
int main() {
	R(n);
	r=n;
	rep(i,1,n,1) {
		R(a[i]);
		exi[a[i]]++;
		if(exi[a[i]]>exi[ma]) ma=a[i];
	}
	for(int i=1;i<=n;++i) {
		if(exi[a[i]]==exi[ma]) {
			ans.push_back(a[i]);
		}
	}
	for(int i=0;i<ans.size();i++)
		check(ans[i]);
	Ps(l); Ps(r);
	puts("");
}

void check(int k) {
	int c_l=1;
	int c_r=n;
	while(a[c_l]!=k) c_l++;
	while(a[c_r]!=k) c_r--;
	if(c_r-c_l<r-l) {
		r=c_r;
		l=c_l;
	}
}
