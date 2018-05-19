//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
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
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
class Solution {
public:
    int rt[10]={0,1,5,-1,-1,2,9,-1,8,6};
    bool check(int x) {
	int ori=x;
	if(x==0) return 0;
	int ret=0;
	while(x!=0) {
		int cur = rt[x%10];
		x/=10;
		if(cur==-1) return 0;
		else ret=ret*10+cur;
	}
	return ret!=ori;
}
    int rotatedDigits(int N) {
        int cnt=0;
        for(int i=1;i<=N;++i) {
            cnt+=check(i);
        	if(check(i)) cerr<<i<<endl;
	}
        return cnt;
    }
};
int main() {
	Solution sol;
	cout<<sol.rotatedDigits(10);
}


