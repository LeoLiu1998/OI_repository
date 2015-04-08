/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const double pi=3.1415926535898;
using namespace std;
const int MAX_N=101;  
int r[MAX_N][MAX_N];  
int have[MAX_N];  
int d[MAX_N];  
int p;  
int init()  
{  
    scanf("%d",&p);  
    int i;  
    char a,b;  
    int s,t,d;  
    for (i=1;i<=p;i++)  
    {  
        scanf("\n%c %c %d",&a,&b,&d);  
        if (a>='a'&&a<='z') a=a-'a'+1;  
        else a=a-'A'+27;  
        if (b>='a'&&b<='z') b=b-'a'+1;  
        else b=b-'A'+27;  
        if (!r[a][b]||d<r[a][b]) r[a][b]=d;  
        if (!r[b][a]||d<r[b][a]) r[b][a]=d;  
    }  
}  
int DijkStra()  
{  
    int i,j,k;  
    memset(d,1,sizeof(d));  
    d[52]=0;  
    for (i=1;i<=52;i++)  
    {  
        int j=1;  
        while (have[j]&&j<=52) j++;  
        if (j>52) break;  
        for (k=j+1;k<=52;k++)  
        if (!have[k]&&d[k]<d[j]) j=k;  
        have[j]=1;  
        for (k=1;k<=52;k++)  
        if (!have[k]&&r[j][k]&&d[j]+r[j][k]<d[k])  
        d[k]=d[j]+r[j][k];  
    }  
    int mini;  
    mini=27;  
    for (i=27;i<=51;i++)  
    if (d[i]<d[mini]) mini=i;  
    printf("%c %d",mini-27+'A',d[mini]);  
}  
int main()  
{  
    init();  
    DijkStra();  
    return 0;  
}
