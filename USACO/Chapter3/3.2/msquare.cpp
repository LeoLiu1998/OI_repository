/**
USER: yeguang2
PROB: msquare
LANG: C++14
**/
//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB "msquare"
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

void Redirect() {
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
unordered_map<int,string> dis;
int END=12345678;
queue<int> q;
void Add(string cs,int nex, char symbol) {
	if(dis.find(nex)!=dis.end()&&(dis[nex].size()<=(cs+symbol).size()))
		return ;
	else
		dis[nex]=cs+symbol;
#ifdef DEBUG
	Pn(nex);
	cout<<cs+symbol<<endl;
#endif
	q.push(nex);
}
void BFS(int s) {
	dis[s]="";
	q.push(s);
	while(q.size()) {
		int cur=q.front(); q.pop();
		string cs=dis[cur];
		int nex=(cur%10000)*10000+cur/10000;
		Add(cs,nex,'A');
		int l=cur/10000,r=cur%10000;
		l=(l%10)*1000+l/10;
		r=(r%10)*1000+r/10;
		Add(cs,l*10000+r,'B');
		int rot=cur/10000%1000/10*100+cur%1000/10;
		rot=(rot/1000)*100+rot%10*10+rot%100/10*1000+rot/100%10;
		l=cur/10000; r=cur%10000;
		l=l/1000*1000+rot/100*10+l%10;
		r=r/1000*1000+rot%100*10+r%10;
		Add(cs,l*10000+r,'C');
		if(dis.find(END)!=dis.end())
			break;
	}
}
int tmp[5];
int main() {
	Redirect();
	int s=0;
	rep(i,1,4,1) {
		int t; R(t);
		s=s*10+t;
	}
	rep(i,1,4,1) R(tmp[i]);
	rep(i,1,4,1) {
		s=s*10+tmp[5-i];
	}
	END=s;
	BFS(12348765);
	Pn(dis[END].size());
	cout<<dis[END]<<endl;
}


