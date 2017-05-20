#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <utility>
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define pb push_back
#define PROB "hao"
static inline 
void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	x*=f;
}
const int SZ = 1<<20;  //fast io  
struct fastio{  
    char inbuf[SZ];  
    char outbuf[SZ];  
    fastio(){  
        setvbuf(stdin,inbuf,_IOFBF,SZ);  
        setvbuf(stdout,outbuf,_IOFBF,SZ);  
    }  
}io;  

using namespace std;
const int N = 4000005;
struct Pos {
	int x,y;
};

Pos a[N],tmp[N];
long long ans;

void Mergey(int l,int m,int r) {
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r)
    {
        if(a[i].y > a[j].y)
        {
            tmp[k++] = a[j++];
            ans += m - i + 1;
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while(i <= m) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i=l;i<=r;i++)
        a[i] = tmp[i];
}
void Mergex(int l,int m,int r) {
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r)
    {
        if(a[i].x > a[j].x)
        {
            tmp[k++] = a[j++];
            ans += m - i + 1;
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while(i <= m) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i=l;i<=r;i++)
        a[i] = tmp[i];
}

void Merge_sorty(int l,int r) {
    if(l < r)
    {
        int m = (l + r) >> 1;
        Merge_sorty(l,m);
        Merge_sorty(m+1,r);
        Mergey(l,m,r);
    }
}
void Merge_sortx(int l,int r) {
    if(l < r)
    {
        int m = (l + r) >> 1;
        Merge_sortx(l,m);
        Merge_sortx(m+1,r);
        Mergex(l,m,r);
    }
}

int main() {
    int n;
   	R(n);
        for(int i=0;i<n;i++) {
            R(a[i].x); R(a[i].y);
	};
	Merge_sortx(0,n-1);
        ans = 0;
        Merge_sorty(0,n-1);
        long long cur=(long long)n*(n-1);
	cur>>=1;
	cur-=ans;
	printf("%lld\n",cur);
   
    return 0;
}

