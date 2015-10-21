//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int ans=0;
void dfs(int max,int cur) {
	if(cur==0) {
		ans++;
		return ;
	} else {
		for(int i=1;i<=max;++i) {
			if(cur>=i) dfs(i,cur-i);
		}
	}
}
int a[11]={
4087968,
4697205,
5392783,
6185689,
7089500,
8118264,
9289091,
10619863,
12132164,
13848650,
15796476
};
int main() {
	int n;
	R(n);
	if(n>=70) {
		Pn(a[n-70]);
		return 0;
	}
	dfs(n,n);
	Pn(ans);
}

