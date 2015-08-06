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
struct LEN{
	vector<int> cost;
	int sum,cnt;
	LEN(){sum=cnt=0;}
};
LEN a[100005];
int n;
#define pb push_back
int pos[100005];
int pre[100005];
int main(){
	R(n);
	rep(i,1,n,1) {
		R(pos[i]);	
	}
	rep(i,1,n,1) {
		int k;
		R(k);
		a[pos[i]].cost.pb(k);
		a[pos[i]].cnt++;
		a[pos[i]].sum+=k;
	}
	int need=(n/2 + 1);
	for(int i=100000;i>=1;--i) {
		pre[i]=pre[i+1]+a[i].cnt;
		if(pre[i]>=need) {
			need=pre[i+1];
			break;
		}
	}
	need=max(0,need);
	int cur=100000;
	long long ans=0;
	while(need) {
		ans+=a[cur].sum;	
		need-=a[cur].cnt;
		need=max(0,need);
		cur--;
	}
	cout<<ans<<endl;
}
