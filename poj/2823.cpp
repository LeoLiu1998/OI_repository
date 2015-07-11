#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cctype>
#include <set>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
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
inline void P(int x){
	if(x<0){ putchar('-');
	x*=-1;}
	if(x>9) P(x/10);
	putchar(x%10+'0');
}
#define popf pop_front
#define popb pop_back
#define pushf push_front
#define pushb push_back
#define pt second
#define pv first
#define mp make_pair
#define pb push_back
deque<pair<int,int> > dmax;
deque<pair<int,int> > dmin;
void solvemax(int,int);
void solvemin(int,int);
vector <int > ansmax;
vector <int> ansmin;
int n,k;
int main() {
	R(n); R(k);
	for(int i=1;i<=n;++i) {
		int a;R(a);
		solvemax(i,a);
		solvemin(i,a);
	}
	for(int i=k-1;i<ansmin.size();++i) {
		P(ansmin[i]);
		putchar(' ');	
	}
	putchar('\n');
	for(int i=k-1;i<ansmax.size();++i) {
		P(ansmax[i]);
		putchar(' ');
	}
	putchar('\n');
	return 0;
}

void solvemax(int time,int v) {
	while(dmax.size()&&dmax.back().pv<v) {
		dmax.popb();
	}
	while(dmax.size()&&dmax.front().pt+k-1<time){
		dmax.popf();
	}
	dmax.pushb(mp(v,time));
	ansmax.pb(dmax.front().pv);
}

void solvemin(int time,int v) {
	while(dmin.size()&&dmin.back().pv>v){
		dmin.popb();
	}
	while(dmin.size()&&dmin.front().pt+k-1<time) {
		dmin.popf();
	}
	dmin.pushb(mp(v,time));
//	cout<<dmin.front().pt<<" "<<time<<endl;
	ansmin.pb(dmin.front().pv);
}
