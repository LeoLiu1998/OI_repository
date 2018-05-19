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
int pos;
int cnt;
double DP[30][100];
#define p2a(x) (x+50)
int aim;
char buff[100];
int main() {
	scanf("%s",buff);
	for(int i=0;buff[i];++i) {
		if(buff[i]=='+')
			aim++;
		else if(buff[i]=='-')
			aim--;
	}
	memset(buff,0,sizeof buff);
	scanf("%s",buff);
	for(int i=0;buff[i];++i) {
		if(buff[i]=='+')
			pos++;
		else if(buff[i]=='-')
			pos--;
		else if(buff[i]=='?')
			cnt++;
	}
	DP[0][p2a(pos)]=1;
	for(int i=1;i<=cnt;++i) {
		for(int j=1;j<=99;++j) {
			DP[i][j+1]+=0.5*DP[i-1][j];
			DP[i][j-1]+=0.5*DP[i-1][j];
		}
	}
	printf("%.8f\n",DP[cnt][p2a(aim)]);
}

