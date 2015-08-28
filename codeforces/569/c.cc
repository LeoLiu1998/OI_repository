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
const long MAXP = 2000000;  
long prime[MAXP] = {0},num_prime = 0;  
int isNotPrime[MAXP] = {1, 1};  
int pi[MAXP];
void Prime()  
{  
    for(long i = 2 ; i <  MAXP ; i ++)  
    {  
        if(! isNotPrime[i])  
            prime[num_prime ++]=i;  
        for(long j = 0 ; j < num_prime && i * prime[j] <  MAXP ; j ++)  
        {  
            isNotPrime[i * prime[j]] = 1;  
            if( !(i % prime[j]))  
                break;  
        }  
    }
    rep(i,1,MAXP,1) {
    	pi[i]=pi[i-1]+(!isNotPrime[i]);
    }
} 
int num[10];
int rub[MAXP];
bool checkPali(int k) {
	int cnt=0;
	while(k) {
		num[++cnt]=k%10;
		k/=10;
	}
	rep(i,1,cnt/2+1,1) {
		if(num[i]!=num[cnt+1-i]) {
			return 0;
		}
	}
	return 1;
}
void Palindromes() {
	rep(i,1,MAXP,1) {
		rub[i]+=rub[i-1]+checkPali(i);
	}
}
double a;
int p,q;
int main() {
	Prime();Palindromes(); 
	cin>>p>>q;
	a=p*1.0/q;
	int ans=1;
	while(a*rub[ans]-pi[ans]>-(1e-8)) 
		ans++;
	ans--;
	Pn(ans);
}
