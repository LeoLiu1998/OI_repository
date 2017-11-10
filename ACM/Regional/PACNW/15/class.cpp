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
}

#define CLX(x) memset(x,0,sizeof x)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
char tmp[100040];
char name[1005][1000];
pair<pll,int> peo[1005];
int cur[70];
int cur2[70];
int cnt=0;

bool cmp(pair<pll,int> a, pair<pll,int> b) {
	if(a.fi!=b.fi)
		return a.fi<b.fi;
	else  {
		string sa=name[a.se];
		string sb=name[b.se];
		return sa>sb;
	}
}

void Deal(int x) {
	int l=strlen(tmp);
	int i=0;
	CLX(cur);
	CLX(name[x]);
	rep(i,0,l,1) {
		if(tmp[i]==':') break;
		name[x][i]=tmp[i];
	}
	for(i;i<=l;++i) {
		while(!isalpha(tmp[i])) i++;
		if(tmp[i]=='c') break;
		if(tmp[i]=='u') {
			cur[++cnt]=2;
		} else if(tmp[i]=='m') {
			cur[++cnt]=1;
		} else {
			cur[++cnt]=0;
		}
		while(isalpha(tmp[i])) i++;
	}
	rep(i,1,60,1) cur2[i]=1;
	for(int i=cnt,j=1;i;--i,++j) {
		cur2[j]=cur[i];
	}
	ull ret=0;
	rep(i,1,30,1) {
		ret*=3;
		ret+=cur2[i];
	}
	peo[x].fi.fi=ret;
	ret=0;
	rep(i,31,60,1) {
		ret*=3;
		ret+=cur2[i];
	}
	peo[x].se=x;
	peo[x].fi.se=ret;
	return ;
}

int main() {
	R(n);
	cerr<<n<<endl;
	for(int i=1;i<=n;++i) {
		cin.getline(tmp,5000);
		Deal(i);
	}
	sort(peo+1,peo+n+1,cmp); 
	for(int i=n;i;--i) {
		puts(name[peo[i].se]);
	}
}


