#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int mod=1e9+7,M=157;
int read(){
	int ans=0,f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar();}
	return ans*f;
}
int T,len,ans,h[M],f[M][15][2][2];
char s[M];
int calculate(int k){
	memset(f,0,sizeof(f));
	f[0][9][0][1]=1;
	for(int i=1;i<=k;i++){
		int now=s[i]-'0';
		for(int x=0;x<=9;x++){
			for(int y=(i==1)?1:0;y<=9;y++){
				for(int z=0;z<2;z++){
					if(z&&y>now) continue;
					int nowf=(z&&y==now);
					if(x>=y){
						if(x==y) f[i][y][1][nowf]=(f[i][y][1][nowf]+f[i-1][x][1][z])%mod;
						f[i][y][0][nowf]=(f[i][y][0][nowf]+f[i-1][x][0][z])%mod;
					}
					else{
						f[i][y][1][nowf]=(f[i][y][1][nowf]+f[i-1][x][1][z])%mod;
						f[i][y][1][nowf]=(f[i][y][1][nowf]+f[i-1][x][0][z])%mod;
					}
				}
			}
		}
	}
	int sum=0;
	for(int x=0;x<=9;x++) for(int y=0;y<2;y++) for(int z=0;z<2;z++) sum=(sum+f[k][x][y][z])%mod;
	return sum;
}
void prepare(){
	for(int i=1;i<=100;i++) s[i]='9';
	for(int i=1;i<=100;i++) h[i]=calculate(i);
}
int main()
{
	prepare();
	T=read();
	while(T--){
		ans=0;
		scanf("%s",s+1); len=strlen(s+1);	
		for(int i=1;i<len;i++) ans=(ans+h[i])%mod;
		ans=(ans+calculate(len))%mod;
		printf("%d\n",ans);
	}
	return 0;
}