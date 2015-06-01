#include<cstdio>
using namespace std;
int n,m,a[101][101],x,y,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
      {
        scanf("%d%d",&x,&y);
        for(int i=1;i<=n;++i) ++a[i][y],++a[x][i];
        for(int i=x+1,j=y+1;i<=n&&j<=n;++i,++j) ++a[i][j];
        for(int i=x-1,j=y-1;i&&j;--i,--j) ++a[i][j];
        for(int i=x+1,j=y-1;i<=n&&j;++i,--j) ++a[i][j];
        for(int i=x-1,j=y+1;i&&j<=n;--i,++j) ++a[i][j];
        --a[x][y];
      }
    for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
        if(a[i][j]==m)
          ++ans;
    printf("%d\n",ans);
    return 0;
}
