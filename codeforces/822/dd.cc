#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define MOD 1000000007
#define MAX 50010
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

int le, ri;
LL t;
const LL mod = 1000000007;
LL power[5000010];
LL cnt[5000010];
int flag[5000010];
int prime[1000010];
int cou;

int main(){
	cou = 0;
	for (int i = 2; i <= 5000000; i++){
		if (!flag[i]){
			prime[cou++] = i;
		}
		for (int j = 0; j < cou && (LL)i * prime[j] <= 5000000; j++){
			flag[i * prime[j]] = 1;
			if (i % prime[j] == 0){
				break;
			}
		}
	}
	cnt[1] = 1;
	for (int i = 2; i <= 5000000; i++){
		if (!flag[i]){
			cnt[i] = ((LL)i * (i - 1) / 2) % mod;
		}
		else{
			for (int j = 0; j < cou; j++){
				if (i % prime[j] == 0){
					cnt[i]= ((LL)i * (prime[j] - 1) / 2 + cnt[i / prime[j]]) % mod;
					//cnt[i]=f[j]*(i/fd[i])+cnt[
					//3 + 3 
					break;
				}
			}
		}
	}
	while (~scanf("%lld%d%d", &t, &le, &ri)){
		int m = ri - le;
		power[0] = 1;
		for (int i = 1; i <= m; i++){
			power[i] = (power[i - 1] * t) % mod;
		}
		LL ans = 0;
		for (int i = le; i <= ri; i++){
			ans += power[i - le] * cnt[i];
			ans %= mod;
#ifdef YGHDEBUG
			printf("%lld\n",cnt[i]);
#endif
		}
		printf("%lld\n", ans);
	}
	return 0;
}
