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
int DP[7][11];
int l=-1,r=-1;
void init();
int solve(int);
int main() {
	init();
	R(l); R(r);
	while(l&&r) {
		Pn((solve(r+1)-solve(l)+1)/2);
		R(l); R(r);
	}
}

void init() {
	for(int i=0;i<=9;++i){
		DP[1][i]=1;
	}
	DP[1][4]=0;
	for(int i=2;i<=8;++i) {
		for(int j=0;j<10;++j) {
			for(int k=0;k<10;++k) {
				if(j==4||(j==6&&k==2)) {
					continue;
				} else {
					DP[i][j]+=DP[i-1][k];
				}
			}
		}
	}
}

int solve(int n) {
	int ans=0;
	int bit[10],len=0;
	while(n) {
		bit[++len]=n%10;
		n/=10;
	}
	bit[len+1]=0;
	for(int i=1;i<len;++i) {
		for(int j=1;j<=9;++j) {
			ans+=DP[i][j];
		}
	}
	for(int i=1;i<bit[len];++i) {
		ans+=DP[len][i];
	}
//	cout<<ans<<endl;
	for(int i=len;i;i--) {
		for(int j=0;j<bit[i];++j){
			if(j==4||((j==2)&&(bit[i+1]==6))){
				continue;
			} else {
				ans+=DP[i][j];
			}
		}
		if(bit[i+1]==4||(bit[i]+1==6&&bit[i]==2))break;
	}
	return ans;
}
