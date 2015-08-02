/*ID: yeguang2
PROG: crypt1
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
vector<int> num;
bool can[15];
int n,temp;
int a[7];
#define pb push_back
int ans=0;
int get(int l,int r) {
	int ret=0;
	rep(i,l,r,1) {
		ret=ret*10+a[i];
	}
	return ret;
}
bool judge(int cur) {
	register int q;
	while(cur!=0) {
		q=cur%10;
		if(!can[q]) return 0;
		cur/=10;
	}
	return 1;
}
bool check() {
	int x=get(1,3);
	int y=get(4,5);
	rep(i,4,5,1) {
		temp=x*a[i];
		if(temp>999||(!judge(temp))) return 0;
	}
	temp=x*y;
	if(temp>9999||(!judge(temp))) return 0;
	return 1;

}
void dfs(int k) {
	if(k==6) {
		ans+=check();
		return ;
	}
	for(int i=0;i<num.size();++i) {
		a[k]=num[i];
		dfs(k+1);
	}
}
int main() {
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	R(n);
	rep(i,1,n,1) {
		R(temp); can[temp]=1; num.pb(temp);
	}
	dfs(1);	
	Pn(ans);
}
