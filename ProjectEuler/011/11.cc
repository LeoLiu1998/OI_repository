#include <cstdio>
#include <iostream>
using namespace std;
int a[30][30];

int main(){
	freopen("11.in","r",stdin);
	for(int i=1;i<=20;++i) {
		for(int j=1;j<=20;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=20;i++) {
		for(int j=1;j<=20;++j) {
			clac(i,j);
		}
}
