#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<queue>  
#include<stack>  
#include<math.h>  
#include<vector>  
#include<map>  
#include<set>  
#include<cmath>  
#include<complex>  
#include<string>  
#include<algorithm>  
#include<iostream>  
#define exp 1e-10  
using namespace std;  
const int N = 50005;  
const int M = 40;  
const int inf = 100000000;  
const int mod = 2009;  
int s[2*N],e[2*N],m[2*N],p[N],q[N];  
int fun(int x)    
{    
    if(s[x]!=x)    
        s[x]=fun(s[x]);    
    return s[x];    
}  
int main()  
{  
    int t,n,i,x,y,k;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        for(i=1;i<=n+n;i++)  
            s[i]=i,e[i]=m[i]=0;  
        for(i=0;i<n;i++)  
        {  
            scanf("%d%d",&p[i],&q[i]);  
            x=fun(p[i]);  
            y=fun(q[i]);  
            s[x]=y;  
        }  
        for(i=0;i<n;i++)  
            e[fun(p[i])]++;  
        for(i=1;i<=n+n;i++)  
            m[fun(i)]++;  
        for(i=1;i<=n+n;i++)  
        {  
            k=fun(i);  
            if(e[k]>m[k])  
                break;  
        }  
        if(i<=n+n)  
            puts("impossible");  
        else  
            puts("possible");  
    }  
    return 0;  
}  