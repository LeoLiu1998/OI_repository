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
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
ll sum;int mi=1001;
int main() {
	int n;
	R(n);
	for(register int i=1,temp;i<=n;++i) {
		R(temp);
		sum+=temp;
		if(temp&1) mi=min(mi,temp);			
	}
	if(n==1&&(sum&1)) puts("NIESTETY");
	else {
		sum-=(sum&1)* mi;
		cout<<sum<<endl;
	}
}
