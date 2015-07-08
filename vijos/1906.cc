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
struct Node {
	int w;
	vector<int> son;
	Node(int _w=0):w(_w){} 
};
const int maxn=200005;
const int Mn=10007;
Node node[maxn];
#define pb push_back
int n;
int ans_max=0;
int ans=0;
int a,b;
int main() {
	R(n);
	rep(i,1,n-1,1){
		R(a);R(b);
		node[a].son.pb(b);
		node[b].son.pb(a);
	}
	rep(i,1,n,1){
		R(node[i].w);
	}
	rep(i,1,n,1) {
		int delta;
		int size=node[i].son.size();
		rep(j,0,size-2,1){
			rep(k,j+1,size-1,1) {
				int js=node[i].son[j];
				int ks=node[i].son[k];
				delta=node[js].w*node[ks].w;
				ans+=delta;
				ans_max=max(ans_max,delta);
				ans%=Mn;
			}
		}
	}
	Ps(ans_max);
	Pn(ans*2);
}
