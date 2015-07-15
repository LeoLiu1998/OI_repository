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
typedef long long ll;
struct Tree{
	int pos,num;
	Tree(int _pos=0,int _num=0):pos(_pos),num(_num){}
	inline bool operator < (const Tree &a) const {
		return abs(pos) > abs(a.pos);
	}
	inline void Read(){
		R(pos);
		R(num);
		return ;
	}
};
#define pb push
priority_queue<Tree> l;
priority_queue<Tree> r;
const int maxn=200;
Tree a[maxn];
int n;
ll ans=0;
void Left() {
	rep(i,1,n,1){
		if(a[i].pos>0) 
			r.pb(a[i]);
		else 
			l.pb(a[i]);
	}
	ll cur_ans=0;
	while(l.size()) {
		cur_ans+=l.top().num;
		l.pop();
		if(!r.size()) break;
		cur_ans+=r.top().num;
		r.pop();
	}
	ans=max(ans,cur_ans);
}
void Right(){
	rep(i,1,n,1) {
		if(a[i].pos>0) 
			r.pb(a[i]);
		else 
			l.pb(a[i]);
	}
	ll cur_ans=0;
	while(r.size()) {
		cur_ans+=r.top().num;
		r.pop();
		if(!l.size()) break;
		cur_ans+=l.top().num;
		l.pop();
	}
	ans=max(ans,cur_ans);
}
int main() {
	R(n);
	rep(i,1,n,1)
		a[i].Read();
	Left();
	Right();
	cout<<ans<<endl;
}

