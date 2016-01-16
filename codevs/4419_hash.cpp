//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#include <hash_map>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
__gnu_cxx::hash_map<int,int> a;
int main() {
	int n; R(n); int ans=0;
	for(int i=1;i<=n;++i) {
		int k; R(k);
		a[k]++;
		if(a[k]>a[ans]) {
			ans=k;
		}
	}
	Pn(ans);
}

