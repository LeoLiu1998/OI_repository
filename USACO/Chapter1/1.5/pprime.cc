/*ID:yeguang2
PROG:pprime
LANG:C++
*/
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
int l,r;
bool check(int k) {
	if(k<l||k>r) return 0; 
	for(int i=2;i*i<=k;++i) {
		if(k%i==0) return 0;
	}
	return 1;
}
int num[10];
int gen[10];
void digit(int k) {
	int cnt=0;
	while(k) {
		num[++cnt]=k%10;
		k/=10;
	}
	num[0]=cnt;
}
int get() {
	int ret=0;
	for(int i=1;i<=gen[0];++i) {
		ret=ret*10+gen[i];
	}
	return ret;
}
int gen1(int k) {
	int di=2*num[0];
	gen[0]=di;
	for(int i=1;i<=num[0];i++,di--) {
		gen[di]=gen[i]=num[num[0]+1-i];
	}
	return get();
}
int gen2(int k){
	int di=2*num[0]-1;
	gen[0]=di;
	for(int i=1;i<=num[0];i++,di--) {
		gen[di]=gen[i]=num[num[0]+1-i];
	}
	return get();
}
set<int> ans;
int main() {
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	R(l); R(r);
	for(int i=1;;++i) {
		int x,y;
		digit(i);
		x=gen1(i);
		y=gen2(i);
		if(x<l&&y<l) continue;
		if(x>r&&y>r) break;
		if(check(x)) ans.insert(x);
		if(check(y)) ans.insert(y);
	}
	for(set<int>::iterator it=ans.begin();it!=ans.end();++it) Pn(*it);
}
