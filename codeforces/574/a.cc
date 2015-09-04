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
priority_queue<int> pq;
int n;
int ini;
int cur;
int main() {
	R(n);
	n--;
	R(cur);
	ini=cur;
	while(n--) {
		int x; R(x); pq.push(x);
	}
	while(pq.top()>=cur) {
		int top=pq.top()-1;
		pq.pop();
		cur++;
		pq.push(top);
	}
	Pn(cur-ini);
}
