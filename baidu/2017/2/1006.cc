#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int T;
const int maxn = 105;
char s[maxn];
int d[maxn];
const long long mod = 1e9 + 7;
long long f2[2][15][maxn];
int len;

void upd(long long & a,long long b){
    a += b;
    if(a >= mod) a -= mod;
}
long long dfs3(int n,bool limit,int pre,bool change){
    if(n == 0) return 1;
    if(!limit){
        long long &ret = f2[change][pre][n];
        if(ret != -1) return ret;
        ret = 0;
        if(change){
            for(int i = pre;i < 10;i++){
                upd(ret,dfs3(n - 1,0,i,1));
            }
        }else{
            for(int i = 0;i < 10;i++){
                if(i <= pre) upd(ret,dfs3(n - 1,0,i,0));
                else upd(ret,dfs3(n - 1,0,i,1));
            }
        }
        return ret;
    }else{
        long long ans = 0;
        for(int i = 0;i <= d[len + 1 - n];i++){
            if(change){
                if(i < pre) continue;
                if(i == d[len + 1 - n]){
                    upd(ans,dfs3(n - 1,1,i,1));
                }else{
                    upd(ans,dfs3(n - 1,0,i,1));
                }
            }else{
                if(i <= pre){
                    if(i == d[len + 1 - n]){
                        upd(ans,dfs3(n - 1,1,i,0));
                    } else{
                        upd(ans,dfs3(n - 1,0,i,0));
                    }
                }else{
                    if(i == d[len + 1 - n])
                        upd(ans,dfs3(n - 1,1,i,1));
                    else
                        upd(ans,dfs3(n - 1,0,i,1));
                }
            }
        }
        return ans;
    }
}

void print(){
    for(int l = 1;l < len;l++)
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 10;j++){
                printf("f[%d][%d][%d] = %d\n",i,j,l,f2[i][j][l]);
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        scanf("%s",s + 1);
        len = strlen(s + 1);
        memset(f2,-1,sizeof(f2));
        for(int i = 1;i <= len;i++){
            d[i] = s[i] - '0';
        }
        long long ans = 0;
        //print();
        for(int i = 1;i < len;i++){
            for(int j = 1;j < 10;j++){
                upd(ans,dfs3(i - 1,0,j,0));
            }
        }
        for(int j = 1;j <= d[1];j++){
            if(j == d[1]) upd(ans,dfs3(len - 1,1,j,0));
            else upd(ans,dfs3(len - 1,0,j,0));
        }
        cout << ans << endl;
    }
    return 0;
}