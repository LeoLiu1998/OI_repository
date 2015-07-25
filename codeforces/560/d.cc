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
const int maxn=200434;
char str[2][maxn];
int len[2];
void solve(int k,int s,int e) {
	int l=e-s+1;
	if(l&1) return;
	int half=l/2;
	int s1=s,s2=s+half;
	solve(k,s,s+half-1);
	solve(k,s+half,e);
	for(int i=1;i<=l;++i,s1++,s2++) {
		if(str[k][s1]<str[k][s2]) return ;
		else if(str[k][s1]>str[k][s2]) {
			for(int j=s;j<s+half;++j) {
				swap(str[k][j],str[k][j+half]);
			}
			return ;
		}
	}
}
int main() {
	scanf("%s",str[0]);
	scanf("%s",str[1]);
	len[0]=strlen(str[0]);
	len[1]=strlen(str[1]);
	solve(0,0,len[0]-1);
	solve(1,0,len[1]-1);
	 if(!strcmp(str[0],str[1])){
	 	puts("YES");
	 } else  {
	 	puts("NO");
	 }
}
