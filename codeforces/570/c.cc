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
const int maxn=500005;
int len;
bool a[maxn];
int m;
bool get() {
	char ch=getchar();
	while((ch>'z'||ch<'a')&&ch!='.') ch=getchar();
	return ch=='.';
}
int ans=0;
int poi=0;
int seg=0;
inline void P() {
	Pn(ans);	
}
void pre() {
	for(int i=1;i<=len;) {
		if(a[i]) {
			i++;
			while(a[i]) {
				ans++;
				i++;
			}
		} else {
			i++;
		}
	}
}
inline bool isalone(int pos) {
	return a[pos-1]==a[pos+1]&&a[pos+1];
}
inline bool isep(int pos) {
	return a[pos-1]!=a[pos+1];
}
inline bool isse(int pos) {
	if(pos==1||pos==len) return 1;
	return 0;
}
int main() {
	R(len); R(m);
	for(int i=1;i<=len;++i) {
		a[i]=get();	
	}
	pre();
	while(m--) {
		int pos; R(pos); bool v=get();
		if(v==a[pos]) goto fla;
		if(pos==len||pos==1) {
			if(pos==len) {
				if(v) {
					if(a[pos-1]) ans++;
				} else {
					if(a[pos-1]) ans--;
				} 
			} else {
				if(v){
					if(a[2]) ans++;
				} else {
					if(a[2]) ans--;
				}
			}
		} else {
			if(v) {
				if(isalone(pos)) ans+=2;
				else if(isep(pos)) ans++;
			} else {
				if(isalone(pos)) ans-=2;
				else if(isep(pos)) ans--;
			}
		}
		a[pos]=v;
fla:		Pn(ans);
	}
}
