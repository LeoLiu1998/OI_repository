/* ID: yeguang2
 PROG: milk
 LANG: C++
 */
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
#define PROB "milk"
void Redirect(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
}

#define mp make_pair
#define pb push_back
#define v first
#define num second
vector<pair<int,int> >a;
int n,x,y;
int need;
int m;
int main(){
	Redirect();
	R(need); R(n);
	rep(i,1,n,1){
		R(x); R(y);
		a.pb(mp(x,y));
	}
	sort(a.begin(),a.end());
	int ans=0;
	int i=0;
	while(need) {
		if(a[i].num>need){
			ans+=a[i].v*need;
			need-=need;
		} else {
			need-=a[i].num;
			ans+=a[i].v*a[i].num;
		}
		i++;
	}
	Pn(ans);
}
