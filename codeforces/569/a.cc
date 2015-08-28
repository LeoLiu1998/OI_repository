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
double sum,cur,v;
int ans=0;
bool les(double a, double b) {
	if(fabs(a-b)<1e-8) return 0;
	return a<b;
}
int main() {
	cin>>sum>>cur>>v;
	v=(v-1)/v;
	ans++;
	while(les(((cur)/(1-v)), sum)) {
		cur/=(1-v);
		ans++;
	}
	Pn(ans);
}
