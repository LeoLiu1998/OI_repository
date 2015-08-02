/*ID: yeguang2
PROG: dualpal
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
int BASE;
int num[100];
int convert(int k){
	int cnt=-1;
	memset(num,0,sizeof(num));
	while(k){
		num[++cnt]=k%BASE;
		k/=BASE;
	}
	return cnt;
}
bool check(int cur) {
	int len=convert(cur);
//	if(len<1) return 0;
	for(int i=0,j=len;i<=len&&j>=0;i++,j--){
		if(num[i]!=num[j])	return 0;
	}
//	cout<<cur<<" "<<BASE<<" "<<len<<endl;
	return 1;
}
#define PROB "dualpal"
int T,S;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB ".out","w",stdout);
	R(T);
	R(S);
	int cur=S;
	while(T--) {
		int cnt;
		do{
			cnt=0;
			cur++;
			for(BASE=2;BASE<=10;++BASE){
				cnt+=check(cur);
			}
//			cout<<"cur:"<<cur<<" cnt"<<cnt<<endl;
		}while(cnt<2);
		Pn(cur);
	}
}
