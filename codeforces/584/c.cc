//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=1e5+3;
int cnt;
char solve(char a,char b) {
	if('b'!=a&&'b'!=b) return 'b';
	if('a'!=a&&'a'!=b) return 'a';
	if('z'!=a&&'z'!=b) return 'z';
	
}
char s1[maxn],s2[maxn];

int main() {
	int n,t;
	R(n); R(t);
	t=n-t;
	scanf("%s%s",s1+1,s2+1);
	rep(i,1,n,1) {
		cnt+=(s1[i]==s2[i]);
	}
	if(t<=cnt) {
		rep(i,1,n,1) {
			if(s1[i]==s2[i] &&t > 0) {
				printf("%c",s1[i]);
				t--;
			} else {
				printf("%c",solve(s1[i],s2[i]));
			}
		}
		return 0;
	} else  {
		int temp=t-cnt;
		int pos=0;
		if(n-cnt<temp*2 ) {
			Pn(-1); return 0;
		}
		rep(i,1,n,1) {
			if(s1[i]!=s2[i] && pos<2) {
				temp--;
				if(!pos) printf("%c",s1[i]);
				else printf("%c",s2[i]);
				if(!temp) {
					pos+=1;
					temp=t-cnt;
				}
			} else {
				if(s1[i]==s2[i]) {
					printf("%c",s1[i]);
				} else {
					printf("%c",solve(s1[i],s2[i]));
				}
			}
		}
		return 0;
	}
}
