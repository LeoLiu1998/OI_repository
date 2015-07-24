//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
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
int T;
int n;
set<int> have;
inline bool get(int k) {
	if(have.count(k)) return 1;
	else have.insert(k);
	return 0;
}
int main() {
	R(T);
	register int tem;
	while(T--) {
		have.clear();
		bool f=1;
		R(n);
		while(n--) {
			R(tem);
			if(!get(tem)) {
				if(!f) printf(" ");
				else f=0;
				printf("%d",tem);
			}
		}
		puts("");
	}
}
