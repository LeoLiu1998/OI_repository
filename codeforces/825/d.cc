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
#define PROB
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
const int maxn=5005000;
char s[maxn],t[maxn];
int scnt[30],tcnt[30];
int ans[30];
int num=0;
pii p[30];
int cnt=0;
bool check(int x) {
	ll req=0;
	for(int i=1;i<=26;++i) {
		if(tcnt[i])
		req+=max((ll)0,(ll)tcnt[i]*x-scnt[i]);
	}
	return req<=num;
}
int main() {
	scanf("%s",s+1);
	scanf("%s",t+1);
	int sl=strlen(s+1),tl=strlen(t+1);
	rep(i,1,sl,1) {
		if(isalpha(s[i])) {
			scnt[s[i]-'a'+1]++;
		} else {
			num++;
		}
	}
	rep(i,1,tl,1) {
		if(isalpha(t[i])) {
			tcnt[t[i]-'a'+1]++;
		}
	}
	int l=0,r=sl+1;
	while(r-l>1) {
		int mid=(l+r)>>1;
		if(check(mid)) {
			l=mid;
		} else {
			r=mid;
		}
	}
	for(int i=1;i<=26;++i) {
		if(tcnt[i]) {
			ans[i]+=max((ll)0l,(ll)l*tcnt[i]-scnt[i]);
			num-=ans[i];
		}
	}
	if(num) {
		ans[1]+=num;
	}
	for(int i=1;i<=sl;++i) {
		if(s[i]=='?') {
			for(int j=1;j<=26;++j) {
				if(ans[j]) {
					s[i]=j+'a'-1;
					ans[j]--;
					break;
				}
			}
		}
	}
	printf("%s\n",s+1);
}

