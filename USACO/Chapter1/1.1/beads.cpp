/*
ID: yeguang2
PROG: beads
LANG: C++
*/
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
int len;
const int maxn=300;
char str[maxn];
int ans=-4545;
int solve(int pos) {// solve k means str[k] is not connected with str[k+1]
	int ret=0;
	char l=str[pos],r=str[pos+1];
	for(int i=pos;;i--) {
		if(i<0) i+=len;
		if(ret>len) return len;
		if(l=='w') {
			ret++;
			if(str[i]!=l) {
				l=str[i];
			}
			continue;
		}
		if(str[i]=='w'||str[i]==l) {
			ret++;
			continue;
		}
		break;
	}
	for(int i=pos+1;;i++) {
		if(i>=len) i-=len;
		if(ret>len) return len;
		if(r=='w') {
			ret++;
			if(str[i]!=r) {
				r=str[i];
			}
			continue;
		}
		if(str[i]=='w'||str[i]==r) {
			ret++;
			continue;
		}
		break;
	}
	return ret;
}
int main() {
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	R(len);
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len-1;++i) {
		ans=max(ans,solve(i));
	}
	Pn(ans);
}
