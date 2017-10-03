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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=100050;
unordered_map<ll,int> mmp;
char a[maxn][15];
char anx[20];
int n;
unordered_map<ll,int> mp;
void getAns(int x) {
	mp.clear();
	string ans="89643956435974353";
	for(int i=1;i<=9;++i) {
		ll cur=0;
		string cs="";
		for(int j=i;j<=9;++j) {
			cs+=a[x][j];
			if(cs.length()>ans.length()) break;
			int tmp=a[x][j]-'0';
			if(!tmp) tmp=10;
			cur=cur*11+tmp;
			mp[cur]++;
			if(mp[cur]==mmp[cur]) {
				ans=cs;	
			}
		}
	}
	memset(anx,0,sizeof anx);
	for(int i=0;i<ans.size();++i) {
		anx[i]=ans[i];
	}
	return ;
}

void Add(int x) {
	for(int i=1;i<=9;++i) {
		ll cur=0;
		for(int j=i;j<=9;++j) {
			int tmp=a[x][j]-'0';
			if(!tmp) tmp=10;
			cur=cur*11+tmp;
			mmp[cur]++;
		}
	}
}

int main() {
	R(n);
	rep(i,1,n,1) {
		scanf("%s",a[i]+1);
		Add(i);
	}
	rep(i,1,n,1) {
		getAns(i);
		puts(anx);
	}

}
