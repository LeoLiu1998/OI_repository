#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<ctime>
using namespace std;
int ans=0;
void dfs(vector<int>v,int ind){
	if(1.0*clock()/CLOCKS_PER_SEC>1.95) return;
	if(ind!=-1){
		assert(v[ind]==v[ind+1]);
		v[ind]++;
		v.erase(v.begin()+ind+1);
		ans=max(ans,v[ind]);
	}
	for(int i=0;i<v.size()-1;i++){
		if(v[i]==v[i+1]){
			dfs(v,i);
		}
	}
}

int main(){
	ifstream fin("248.in");
	ofstream fout("248.out");
	vector<int>v;
	int n; fin>>n;
	for(int i=0;i<n;i++){
		int vi;fin>>vi;
		v.push_back(vi);
	}
	dfs(v,-1);
	fout<<ans<<endl;
}
