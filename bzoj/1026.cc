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
typedef long long ll;
const int maxl=18; 
ll dp[maxl][11];
ll l,r;
void init(){
	for(int i=0;i<=9;++i) {
		dp[1][i]=1;
	}
	for(int i=2;i<=19;++i) {
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				if(abs(k-j)>=2){
					dp[i][j]+=dp[i-1][k];
				}
			}
		}
	}
}
ll solve(ll r) {
	int bit[30],len=0;
	memset(bit,0,sizeof(bit));
	while(r){
		bit[++len]=r%10;
		r/=10;
	}
	bit[len+1]=0;
	ll ans=0;
	for(int i=1;i<len;++i) {
		for(int j=1;j<=9;++j){
			ans+=dp[i][j];
		}
	}
	for(int i=1;i<bit[len];++i){
		ans+=dp[len][i];
	}
	for(int i=len-1;i>0;i--){
		for(int j=0;j<bit[i];j++) {
			if(abs(j-bit[i+1])>=2){
				ans+=dp[i][j];
			}
		}
		if(abs(bit[i]-bit[i+1])<2)
				break;
	}
	return ans;
}
int main() {
	init();
	scanf("%lld%lld",&l,&r);
	printf("%lld",solve(r+1)-solve(l));
}
