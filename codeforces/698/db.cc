#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>
#include<stack>
#define hash jhhhh
using namespace std;
typedef long long LL;
const int N = 1010;
struct Point{
	LL x,y;
	Point(){};
	Point(LL x, LL y):x(x), y(y){}
	LL dist(){
		return x * x + y * y;
	}
}p[10000], ar[10];
Point operator + (const Point &a, const Point &b){
	return Point(a.x + b.x, a.y + b.y);
}
Point operator - (const Point &a, const Point &b){
	return Point(a.x - b.x, a.y - b.y);
}
LL det(const Point &a, const Point &b){
	return a.x * b.y- a.y * b.x;
}
LL dot(const Point &a, const Point &b){
	return a.x * b.x + a.y * b.y;
}
vector<pair<LL, int> > vec[N][8];
int n,m;
stack<int> st;
int a[10];
int hash[N], Time = 1;
bool work(int x){
	Time ++;
	while(!st.empty()) st.pop();
	st.push(x);
	int zz = 1;
	hash[x] = Time;
	while (!st.empty()){
		int t = st.top();
		st.pop();
		int y = a[zz++];
		for(int i=0;i<vec[t][y].size() && i <= 7;i++){
			int tmp = vec[t][y][i].second;
			if(hash[tmp]!=Time){
				hash[tmp] = Time;
				st.push(tmp);
			}
		}
		if(m - zz + 1 < st.size()) return 0;
	}
	return 1;
}
bool check(int x){
	for(int i=1;i<=m;i++)
		a[i] = i;
	do{
		if(work(x)) return 1;
	}while(next_permutation(a + 1, a + m +1));
	return 0;
}
int main() {
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ar[i] = Point(x,y);
	}
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i] = Point(x,y);
	}
	for(int i=1;i<=n;i++)
		for(int j =1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(det(p[i] - p[k], ar[j] - p[k]) == 0 && dot(p[i] - p[k], ar[j] - p[k]) < 0){
					vec[i][j].push_back(make_pair((p[k]-ar[j]).dist(), k));
				}
			}
			//sort(vec[i][j].begin(), vec[i][j].end());
		}
	int ans = 0;
	for(int i=1;i<=n;i++) if(check(i)) ans ++;
	cout<<ans<<endl;
	return 0;
	
}