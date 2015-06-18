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
int n;
const int maxn=5000;
struct STU {
	int rate,num,rank;
	STU(int _rate=0,int _num=0):rate(_rate),num(_num){}
};
bool cmpr(STU a,STU b ) {
	return a.rate>b.rate;
}
bool cmpn(STU a,STU b ){
	return a.num<b.num;
}
vector<STU> a;
int main()
{
	R(n);
	for(int i=1,t;i<=n;++i){
		R(t);
		a.push_back(STU(t,i));
	}
	sort(a.begin(),a.end(),cmpr);
	int cnt=0,last=-10000000,tc;
	for(int i=0;i<a.size();++i) {
		if(a[i].rate==last) {
			a[i].rank=a[i-1].rank;
		} else {
			a[i].rank=i+1;
			last=a[i].rate;
		}
	}
	sort(a.begin(),a.end(),cmpn);
	for(int i=0;i<a.size();++i)
	{
		Ps(a[i].rank);
	}
	puts("");
}

