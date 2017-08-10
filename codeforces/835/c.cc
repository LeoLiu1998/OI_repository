#include<bits/stdc++.h>
using namespace std;
#define y1 cplusplusissb
inline void splay(int &v) {
    v=0;
    char c=0;
    int p=1;
    while(c<'0' || c>'9') {
        if(c=='-')p=-1;
        c=getchar();
    }
    while(c>='0' && c<='9') {
        v=(v<<3)+(v<<1)+c-'0';
        c=getchar();
    }
    v*=p;
}
const int N=100010;
int sum[12][105][105];
int n,q,c,x[N],y[N],s[N];
int main() {
    splay(n),splay(q),splay(c);
    for(int i=1; i<=n; i++) {
        splay(x[i]),splay(y[i]),splay(s[i]);
    }
    for(int t=0; t<=c; t++) {
        for(int i=1; i<=n; i++) {
            sum[t][x[i]][y[i]]+=s[i];
            s[i]++;
            if(s[i]>c)s[i]=0;
        }
        for(int i=1; i<=100; i++) {
            for(int j=1; j<=100; j++) {
                sum[t][i][j]+=sum[t][i-1][j];
                sum[t][i][j]+=sum[t][i][j-1];
                sum[t][i][j]-=sum[t][i-1][j-1];
            }
        }
    }
    for(int i=1; i<=q; i++) {
        int t,x1,y1,x2,y2;
        splay(t);
        splay(x1),splay(y1),splay(x2),splay(y2);
        t%=c+1;
        printf("%d\n",sum[t][x2][y2]-sum[t][x1-1][y2]-sum[t][x2][y1-1]+sum[t][x1-1][y1-1]);
    }
}
