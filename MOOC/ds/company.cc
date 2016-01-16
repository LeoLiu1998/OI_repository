//This sourcecode is under GPLv3
//yeguanghao
#include <cstdio>
#include <utility>
#include <cctype>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define round rnd
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=10000005;
char getc() {
	char ch=getchar();
	while(!isalpha(ch)) ch=getchar();
	return ch;
}
pii a[maxn];
int  tot;
int n,m;
int ans=0;
int round=1;
void login() {
	int p,c; R(p); R(c);
	if(a[p].fi!=round) {
		a[p].fi=round; tot++;
	}
	a[p].se=c;
}
void logout() {
	int p; R(p);
	if(a[p].fi!=round) return ;
	else {
		tot--;
		a[p].fi=round-1;
	}
}

void clear() {
	round++;
	tot=0;
}
void number() {
	ans+=tot;
}

void query() {
	int p; R(p);
	if(a[p].fi!=round) {
		ans+=-1;
		return ;
	} else {
		ans+=a[p].se;
	}
}
int main() {
	R(n); R(m);
	while(m--) {
		char cmd=getc();
		if(cmd=='I') {
			login();
		} else if(cmd=='O') {
			logout();
		} else if(cmd=='C') {
			clear();
		} else if(cmd=='N') {
			 number();
		} else {
			query();
		}
	}
	Pn(ans);
}

