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
#define PROB
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
set<char> s;
int n;
int ans=0;
char getc() {
	char ch=0;
	while(ch!='.'&&ch!='?'&&ch!='!') ch=getchar();
	return ch;
}
char gue;
char str[1000500];
int main() {
	R(n);
	rep(i,0,25,1) {
		s.insert('a'+i);
	}
	for(int t=1;t<=n;++t) {
		char cmd=getc();
		getchar();
		scanf("%s",str+1);
		int len=strlen(str+1);
		if(s.size()==1) {
			gue=*s.begin();
			if(cmd=='.') continue;
			else if(cmd=='!') ans++;
			else {
				ans+= (gue!=str[1]);
			}
		}else if(cmd=='.') {
			for(int i=1;i<=len;++i) {
				s.erase(str[i]);
			}
		} else if(cmd=='!') {
			set<char> temp;
			for(int i=1;i<=len;++i) {
				temp.insert(str[i]);
			}
			set<char> res;
			for(auto i:s) {
				if(temp.find(i)!=temp.end()) {
					res.insert(i);
				}
			}
			s=res;
		} else if(cmd=='?') {
			s.erase(str[1]);
		}
	}
	Pn(ans);
}


