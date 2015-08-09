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
#define mp make_pair
#define pb push_back
set<pair<int,int> > seg;
int a,k,len;
int m;
int cur_k;
int get(int l,int r) {
	int c=(r-l)+1;
	return (c+1)/(len+1);
}
int get(pair<int,int> p) {
	return get(p.first,p.second);
}
pair<int,int> tp;
int pos;
#define pl first
#define pr second
typedef pair<int,int> pii;
//map<int,int> :: iterator it;
bool operator < (pii a,pii b) {
	return a.pr<b.pr;
}
int main() {
	R(a); R(k); R(len); R(m);
	seg.insert(mp(a,1));
	cur_k=get(1,a);
	for(int i=1;i<=m;++i) {
		R(pos);
		auto it=seg.lower_bound(mp(pos,-1));
		tp=*it;
		swap(tp.pl,tp.pr);
		seg.erase(it);
		cur_k-=get(tp);
		if(pos>tp.pl) {
			cur_k+=get(mp(tp.pl,pos-1));
			seg.insert(mp(pos-1,tp.pl));
		}
		if(pos<tp.pr) {
			cur_k+=get(pos+1,tp.pr);
			seg.insert(mp(tp.pr,pos+1));
		}
		if(cur_k<k) {
			Pn(i);
			return 0;
		}
	}
	Pn(-1);
	return 0;
}
