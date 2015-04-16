#include <cstdio>
int main(){
    int n,p,q,t=0;
    while(scanf("%d%d%d",&n,&p,&q)!=EOF)
        printf("Case %d: %.4f\n",++t,(q+1.0)/(p+2.0));
    return 0;
}