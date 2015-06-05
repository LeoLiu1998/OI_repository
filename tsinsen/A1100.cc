#include<cstdio> 
#include<cstring> 
#include<iostream> 
#include<cstdlib> 
using namespace std; 
int main() 
{ 
    int a,b; 
    scanf("%d%d",&a,&b); 
    if(a/10!=0)printf("  %d\n",a); 
        else printf("   %d\n",a); 
    if(b/10!=0)printf("* %d\n----\n",b); 
        else printf("*  %d\n----\n",b); 
    if(b/10==0) 
    { 
        a=a*b; 
        if(a/100)printf(" %d\n",a); 
        else if(a/10)printf("  %d\n",a); 
        else printf("   %d\n",a); 
    } 
    else 
    { 
        int a1=a*(b%10),b1=a*(b/10); 
        if(a1/100)printf(" %d\n",a1); 
        else if(a1/10)printf("  %d\n",a1); 
        else printf("   %d\n",a1); 

        if(b1/100)printf("%d\n",b1); 
        else if(b1/10)printf(" %d\n",b1); 
        else printf("  %d\n",b1); 
        printf("----\n"); 
        a=a*b; 
        if(a/1000)printf("%d\n",a); 
        else if(a/100)printf(" %d\n",a); 
        else if(a/10)printf("  %d\n",a); 
        else printf("   %d\n",a); 
    } 
    return 0; 
}
