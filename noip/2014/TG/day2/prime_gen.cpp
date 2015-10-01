//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <ctime>
#include <vector>
#ifdef DEBUG
#include <iostream>
#include <iomanip>
#endif
#include <cctype>
#include <climits>
#include <algorithm>
using namespace std;
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10 +  ch- '0'; ch=getchar();}
	x*=f;
}
#define mp make_pair
#define pb push_back
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define PROB "equation"
void Redirect() {
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
}
bool check(int a) {
	for(int i=2;i*i<=a;++i) {
		if(a%i==0) return 0;
	} 
	return 1; 
}
int main() {
	srand(time(NULL));
	int aim=rand()*rand()%10007;
	int cur=1;
	int cnt=0;
	while(cnt!=aim) {
		cnt+=check(++cur);
	}
	Pn(cur);
}
