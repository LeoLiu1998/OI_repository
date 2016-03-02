/*
PROB: contact
ID: yeguang2
LANG: C++11
*/
//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB "contact"
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
map<pii,int> s;
int str[200050];
int a,b,n;
int len;
void Read() {
	char ch=0; ch=getchar();
	while(ch!=EOF) {
		if(ch=='0'||ch=='1') {
			str[++len]= (ch=='1');
		}
		ch=getchar();
	}
#ifdef YGHDEBUG
/*	for(int i=1;i<=len;++i) {
		printf("%d",str[i]);
	}
	puts("");
*/
#endif
}
void Solve(int k) {
	for(int i=k;i<=len;++i)  {// [i-k+1,i]
		int cur=0;
		for(int j=i-k+1;j<=i;++j) {
			cur<<=1;
			cur+=str[j];
		}
		s[mp(k,cur)]++;
	}
}
map<int,set<pii> > ans;
void PrintB(pii cur) {
	int l=cur.fi,v=cur.se;
	for(int i=l-1;i>=0;--i) {
		printf("%d",((1<<i)&v)!=0);
	}
}
void Print() {
	map<int,set<pii> >::iterator it=ans.end();
	it--;
	Pn(it->first);
	int cnt=0;
	for(set<pii>::iterator ik= (it->second).begin();ik!=(it->second).end();) {
		PrintB(*ik); 
		cnt++;
		++ik;
		if((cnt%6==0)||ik==(it->second).end()) {
			puts("");
		} else {
			putchar(' ');
		}
	}
	ans.erase(it);
}
int main() {
	Redirect();
	scanf("%d%d%d",&a,&b,&n);
	Read();
	for(int i=a;i<=b;++i) {
		Solve(i);
	}
	for(map<pii,int>::iterator it=s.begin();it!=s.end();++it) {
		ans[it->second].insert(it->first);
	}
	while(ans.size()&&(n--)) {
		Print();
	}
}

