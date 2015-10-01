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
#define l first
#define r second
typedef pair<int,int> pii;
vector<pii > q;
pii k;
bool cmp(pii a, pii b) {
	return a.l*a.r<b.l*b.r;
}
inline void R(pii &a) {
	R(a.l); R(a.r); 
}
const int maxb=10005;
struct Bint{
	int a[maxb];
	int bit;
	Bint(int k=0) {
		while(k) {
			
		}
	}
}
int n;
int main() {
	pii temp;
	R(n); 
	for(int i=1;i<=n;++1) {
		R(temp);
		q.pb(temp);
	}
	R(king);
	sort(q.begin(),q.end(),cmp);
	Bint ans;
	Bint cur=king.l;
	for(int i=0;i<n;++i) {
		ans=max(ans,cur/q[i].r);
		cur=cur*q[i].l;
	}
	ans.print();
}
