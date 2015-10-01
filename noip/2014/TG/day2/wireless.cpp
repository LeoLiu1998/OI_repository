//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#ifdef DEBUG
#include <iostream>
#include <iomanip>
#endif
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
#define PROB "wireless"
void Redirect() {
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
}
typedef long long ll;
const int maxn=129;
ll sum[maxn+1][maxn+1];
int pub[maxn+1][maxn+1];
int d,n;
ll ans=0,ans_cnt=0;
int main() {
	Redirect();
	R(d); R(n);
	for(register int i=1,tx,ty;i<=n;++i) {
		 R(tx); R(ty);
		 R(pub[++tx][++ty]);
	}
	for(int x=1;x<=maxn;++x) {
		for(int y=1;y<=maxn;++y) {
			sum[x][y]=sum[x-1][y]+ sum[x][y-1] - sum[x-1][y-1]+ pub[x][y];	
		}
	}
	for(int cx=1;cx<=maxn;++cx) {
		for(int cy=1;cy<=maxn;++cy) {
			int left=max(cx-d,1)-1;
			int right=min(cx+d,maxn);
			int down=min(cy+d,maxn);
			int up=max(cy-d,1)-1;
			ll cur_ans=sum[right][down]-sum[right][up]-sum[left][down]+sum[left][up];
			if(ans < cur_ans ) {
				ans=cur_ans;
				ans_cnt=1;
			} else if(cur_ans==ans) {
				ans_cnt++;
			}
		}
	}
	printf("%I64d %I64d",ans_cnt,ans);
}
