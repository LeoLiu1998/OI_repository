//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
set<int> have;
struct Node{
	int f;
	vector<int> son;
};
const int maxn=100050;
#define pb push_back
Node node[maxn];
int n;
int m;
int Install(int );
int Uninstall(int);
int main() {
	R(n);
	rep(i,1,n-1,1) {
		R(node[i].f);
		node[node[i].f].son.pb(i);
	}
	R(m);
	char cmd=0;
	int pos;
	while(m--) {
		cmd=0;
		while(!isalpha(cmd)) cmd=getchar();
		R(pos);
		if(cmd=='i') Pn(Install(pos));
		else Pn(Uninstall(pos));
	}
	return 0;
}

int Install(int pos) {
	if(have.count(pos)) return 0;
	if(!pos) {
		have.insert(pos);
		return 1;
	}
	have.insert(pos);
	return 1+Install(node[pos].f);
}

int Uninstall(int pos) {
	if(!have.count(pos)) return 0;
	have.erase(pos);
	int ret=1;
	for(int i=0;i<node[pos].son.size();++i) {
		ret+=Uninstall(node[pos].son[i]);
	}
	return ret;
}
