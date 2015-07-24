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
struct String{
	int a[26];
	String(){
		memset(a,0,sizeof(a));
	}
};
const int maxn=200005;
char s1[maxn],s2[maxn];
//String str[2][maxn];
int len;
bool check(int as,int ae,int bs,int be) {
	int flag=1;
	for(int i=as,j=bs;i<=ae&&j<=be;++i,++j) {
		if(s1[i]!=s2[j]){
			flag=0; break;
		}
	}
	if(flag) return 1;
	if((ae-as+1)&1) return 0;
	int am=(as+ae)>>1;
	int bm=(bs+be)>>1;
	return (check(as,am,bm+1,be)&&check(am+1,ae,bs,bm));
}
int main() {
	scanf("%s",s1); scanf("%s",s2); len=strlen(s1);
	if(check(0,len-1,0,len-1)) {
		puts("YES");
	} else {
		puts("NO");
	}
}
