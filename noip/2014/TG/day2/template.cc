//yeguanghao
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
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
