#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define R(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
using namespace std;
int main() {
	int a[14]={0};
	int b=0,s=0;
	for(int i=0;i<=11;i++) {
		R(a[i]);
	}
	for(int i=0;i<=11;++i) 
		if(a[i]<=300+b) {
			s+=(300+b-a[i])/100;
			b=(300+b-a[i])%100;
		} else {
			P(0-i-1);
			return 0;
		}
	P(s*120+b);
	return 0;
}
