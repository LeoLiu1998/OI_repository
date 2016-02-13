#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int cnt;
const int maxn=2000000;
bool isPrime[maxn];
int Prime[maxn];
int main()
{
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i<maxn;++i) {
		if(isPrime[i]) {
			cnt++;
			Prime[cnt]=i;
		}
		for(int j=1;j<=cnt&&Prime[j]*i<maxn;++j) {
			isPrime[Prime[j]*i]=0;
			if(!(i%Prime[j]))
				break;
		}
	}
	for(int i=1;i<=100;++i) {
		cout<<Prime[i]<<endl;
	}
	cout<<Prime[10001]<<endl;
}
