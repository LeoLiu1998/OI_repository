//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int&x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
#define ll int
set<ll> have;
queue<pair<ll,int> > q;
#define v first
#define cnt second
#define pb push_back
#define mp make_pair
ll temp;
int bfs();
int main() {
	R(temp);
	q.push(mp(temp,0));
	cout<<bfs()<<endl;
}
vector<int> tem;
inline ll convert() {
	ll ret=0;
	for(int i=0;i<9;++i) {
		ret=ret*10+tem[i];
	}
	return ret;
}
void Trans(pair<ll,int> cur) {
	int num=cur.v;
	int pos=0;
	tem.clear();
	while(num) {
		tem.pb(num%10);
		num/=10;
	}
	if(tem.size()==8) tem.pb(0);
	pos=abs(pos-8);
	for(int i=0,j=8;i<=4&&j>=4;++i,--j) {
		swap(tem[i],tem[j]);
		if(!tem[i]) pos=i;
		if(!tem[j]) pos=j;
	}
	if(pos%3<=1) {
		swap(tem[pos],tem[pos+1]);
		q.push(mp(convert(),cur.cnt+1));			
		swap(tem[pos],tem[pos+1]);
	}
	if(pos%3>=1) {
		swap(tem[pos],tem[pos-1]);
		q.push(mp(convert(),cur.cnt+1));
		swap(tem[pos],tem[pos-1]);
	}
	if(pos/3<=1) {
		swap(tem[pos],tem[pos+3]);
		q.push(mp(convert(),cur.cnt+1));
		swap(tem[pos],tem[pos+3]);
	} 
	if(pos/3>=1) {
		swap(tem[pos],tem[pos-3]);
		q.push(mp(convert(),cur.cnt+1));
		swap(tem[pos],tem[pos-3]);
	}
}
int bfs() {
	pair<ll,int> cur;
	while(q.size()) {
		cur=q.front(); q.pop();
		if(have.count(cur.v)) continue;
		have.insert(cur.v);
		if(cur.v==123804765) return cur.cnt;
		Trans(cur);
	}
}
