#include <cstdio>
#include <iostream>
using namespace std;
int a[1005];
int main() {
	int cnt=1;
	freopen("8.in","r",stdin);
	for(int i=1;i<=20;++i) {
		for(int i=1;i<=50;++i) {
			a[cnt]=getchar()-'0';
			cnt++;
		}
		getchar();
	}
	//	cout<<a[1000];
	long long ans=1;
	for(int i=13;i<=1000;++i){
		long long temp=1;
		for(int j=i;j>=(i-12);--j) {
			temp*=a[j];
		}
		ans=max(ans,temp);
	}
	cout<<ans<<endl;
}
