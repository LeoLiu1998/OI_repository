//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <cctype>
#include <climits>
#include <algorithm>
using namespace std;
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10 +  ch- '0'; ch=getchar();}
	x*=f;
}
#define mp make_pair
#define pb push_back
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define PROB "link"
struct Node {
	int w,sum;
	int ss;
	vector<int> s;
	int a[2];
	Node() {};
};
const int MOD=10007;
const int maxn=200000;
Node node[maxn+5];
int n;
int ans;
int ma;
inline void pre() {
	for(int i=1;i<=n;++i) {
		node[i].sum=0;
		node[i].ss=0;
		node[i].a[0]=0;
		node[i].a[1]=-1;
		for(int j=0,cur;j<node[i].s.size();++j) {
			cur=node[node[i].s[j]].w;
			node[i].sum+=cur;
			node[i].sum%=MOD;
			node[i].ss+=cur*cur;
			node[i].ss%=MOD;
			if(cur>node[i].a[1]) {
				node[i].a[1]=cur;
				if(node[i].a[1]>node[i].a[0]) swap(node[i].a[1],node[i].a[0]);
			}
		}
		node[i].sum%=MOD;
		ma=max(ma,node[i].a[1]*node[i].a[0]);
	}
}
void Redirect() {
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
}
inline void calc2() {
	for(int i=1;i<=n;++i) {
		for(int j=0,curw;j<node[i].s.size();++j) {
			curw=node[node[i].s[j]].w;
			int temp=(node[i].sum-curw)*curw;
			temp%=MOD;
			ans+=temp;
		}
	}
}
inline void calc() {
	for(int i=1;i<=n;++i) {
		ans+= (node[i].sum*node[i].sum)-node[i].ss;
		ans%=MOD;
	}
	ans%=MOD;
}
int main() {
	Redirect();
	R(n);
	for(int i=1,l,r;i<n;++i) {
		R(l); R(r);
		node[l].s.pb(r);
		node[r].s.pb(l);
	}
	for(int i=1;i<=n;++i) {
		R(node[i].w);
	}
	pre();
	calc();
	Ps(ma);
	while(ans<0) ans+=MOD;
	Pn(ans%=MOD);
	
}
