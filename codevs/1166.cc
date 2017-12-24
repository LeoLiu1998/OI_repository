//
//  main.cpp
//  练手
//
//  Created by 宋珺晰 on 11/2/17.
//  Copyright © 2017 Junxi Song. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
string num[100],ans="0",dp[100][100],p2[100];
int x[10000],y[10000],z[10000];
int maxint(int a, int b)
{
    if(a>b) return a;
    return b;
}
string pluss(string a,string b)
{
    int sizea=a.size( ),sizeb=b.size( );
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));
    for(int i=sizea-1;i>=0;i--) x[sizea-i]=a[i]-'0';
    for(int i=sizeb-1;i>=0;i--) y[sizeb-i]=b[i]-'0';
    for(int i=1;i<=max(sizea,sizeb);i++)
    {
        if(x[i]+y[i]>=10) z[i+1]=z[i+1]+1;
        z[i]=(x[i]+y[i]+z[i])%10;
    }
    int tem=max(sizea,sizeb);
    if(z[tem+1]==1) tem=tem+1;
    string c;
    c.resize(tem);
    for(int i=tem;i>=1;i--) c[tem-i]=z[i]+'0';
    return c;
}
string maxs(string a, string b)
{
    int sizea=a.size( ),sizeb=b.size( );
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));
    if(sizea>sizeb) return a;
    if(sizea<sizeb) return b;
    int tem=0;
    while(tem<sizea&&a[tem]==b[tem])
        tem++;
    if(a[tem]>b[tem]) return a;
    return b;
}
int main( )
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        //for(int j=0;j<100;++j) num[j]="0";
	memset(dp,0,sizeof(dp));
        for(int j=1;j<=m;j++)
        {
            cin>>num[j];
            dp[j][j]=num[j];
        }
        for(int j=1;j<m;j++)
        {
            for(int l=1;l<=m-j;l++)
            {
                int k=l+j;
                dp[l][k]=max(pluss(pluss(dp[l][k-1],dp[l][k-1]),num[k]),pluss(num[l],pluss(dp[l+1][k],dp[l+1][k])));
            }
        }
        ans=pluss(ans,dp[1][m]);
    }
    cout<<pluss(ans,ans)<<endl;
    return 0;
}
