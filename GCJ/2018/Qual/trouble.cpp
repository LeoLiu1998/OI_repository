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
int buff[100500];
int a[100500];
bool check(int *arr,int len) {
	for(int i=1;i<=len;++i) {
		buff[i] = arr[i];
	}
	bool done = false;
	while(!done) {
		done = true;
		for(int i=1;i<=len-2;++i) {
			if(buff[i]>buff[i+2]) {
				done = false;
				swap(buff[i],buff[i+2]);
			}
		}
	}
	for(int i=2;i<=len;++i) {
		if(buff[i] < buff[i-1])
			return 0;
	}
	return 1;
}
int odd[100500],ocnt;
int even[100500],ecnt;
bool qchecker(int *arr,int len) {
	ocnt = 0;
	ecnt = 0;
	for(int i=1;i<=len;++i) {
		if(i&1) 
			odd[++ocnt] = arr[i];
		else
			even[++ecnt] = arr[i];
	}
	sort(odd+1,odd+ocnt+1);
	sort(even+1,even+ecnt+1);
	for(int i=1;i<=len;++i) {
		if(i&1)
			buff[i] = odd[(i>>1)+1];
		else
			buff[i] = even[i>>1];
		if(buff[i]<buff[i-1])
			return false;
	}
	return true;
}

int main() {
	int T; R(T);
	rep(qwq,1,T,1) {
		int n; R(n);
		rep(i,1,n,1) R(a[i]);
		if(qchecker(a,n)) {
			printf("Case #%d: OK\n",qwq);
		} else {
			for(int i=1;i<=n;++i) {
				if(buff[i]<buff[i-1]) {
					printf("Case #%d: %d\n",qwq,i-2);
					goto NEXT;
				}
			}
		}
NEXT:
		continue;
	}
}


