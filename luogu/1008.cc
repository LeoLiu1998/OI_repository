#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10];
int b[5];
vector <int> ans;
int main() {
	
	for(int i=1;i<=9;i++)	a[i]=i;
	do{
		memset(b,0,sizeof(b));
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;++j){
				b[i]*=10;
				b[i]+=a[3*(i-1)+j];
			}
		}
		if(b[3]/b[1]==3&&b[2]/b[1]==2)
			ans.push_back(b[1]);
		if(b[1]==192)
			printf("%d %d\n\n",b[2],b[3]);
		next_permutation(a+1,a+10);
	}while(a[3]<=3);
	for(int i=0;i<ans.size();i++){
		printf("%d %d %d \n",ans[i],ans[i]*2,ans[i]*3);
	}
	return 0;
}
