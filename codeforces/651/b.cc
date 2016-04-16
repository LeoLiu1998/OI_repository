//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
vector<int> a;
int Solve(vector<int> &k) {
	if(k.size()<=1) return 0;
	vector<int> temp;
	int ret=0; temp.clear();
	for(int i=1;i<k.size();++i) {
		if(k[i]!=k[i-1]) {
			ret++;
		} else {
			temp.push_back(k[i]);
		}
	}
	ret+=Solve(temp);
	return ret;
}
int main() {
	R(n);
	for(int i=1;i<=n;++i) {
		int k;
		R(k); a.push_back(k);
	}
	sort(a.begin(),a.end());
	cout<<Solve(a)<<endl;
}

