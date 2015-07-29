/*ID: yeguang2
PROG: barn1
LANG: C++
*/
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
#define PROB "barn1"
void Redirect(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
}
vector<int> a;
vector<int> b;
#define pb push_back
int k,len,n;
int x;
int main() {
	Redirect();
	R(k); R(len); R(n);
	k=min(k,n-1);
	for(int i=1;i<=n;++i) {
		R(x); a.pb(x);
	}
	sort(a.begin(),a.end());
	for(int i=1;i<a.size();++i) {
		b.pb(a[i]-a[i-1]-1);
	}
	sort(b.begin(),b.end(),greater<int>());
	len-=len-a[a.size()-1];
	for(int i=0;i<k-1;++i) {
		len-=b[i];
	}
	len-=a[0]-1;
	Pn(len);
}
