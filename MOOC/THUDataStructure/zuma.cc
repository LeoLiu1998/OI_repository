//This sourcecode is under GPLv3
//http://yeguanghao.xyz
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cctype>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
const int SZ = 1<<20;  //快速io  
struct fastio{  
	char inbuf[SZ];  
	char outbuf[SZ];  
	fastio(){  
		setvbuf(stdin,inbuf,_IOFBF,SZ);  
	        setvbuf(stdout,outbuf,_IOFBF,SZ);  
	}  
}io; 
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
struct Node {
	char c;
	int l,r;
	Node(char q=0,int x=-1,int y=-1):c(q),l(x),r(y){}
};
int cnt=1;
Node node[int(1e5)+3];
char str[int(1e4)+100];
void Check(int pos) {
	int lcnt=0,lp=pos;
	int rcnt=0,rp=pos;
	while(node[node[lp].l].c==node[pos].c) {
		lcnt++; lp=node[lp].l;
	}
	while(node[node[rp].r].c==node[pos].c) {
		rcnt++; rp=node[rp].r;
	}
	if(lcnt+rcnt+1>=3) {
		node[node[lp].l].r=node[rp].r;
		node[node[rp].r].l=node[lp].l;
		Check(node[rp].r);
	}
}
void  Add(int pos,char ch) {
	pos--;
	int i=0;
	for(int j=1;j<=pos;j++,i=node[i].r);
	node[++cnt]=Node(ch,i,node[i].r);
	node[i].r=cnt;
	node[node[cnt].r].l=cnt;
	Check(cnt);
}
char buff[int(1e5)+10];
void Print() {
	int qc=-1;
	for(int i=node[0].r;;i=node[i].r) {
		if(isalpha(node[i].c)) {
			buff[++qc]=node[i].c;
			continue;
		}
		break;
	}
	if(qc==-1) {
		puts("-");
	} else {
		buff[++qc]=0;
		puts(buff);
	}
}
int main() {
	node[0]=Node('!',-1,1);
	cnt=0;
	scanf("%s",str+1);
	int len=strlen(str+1);
	for(int i=1;i<=len;++i) {
		++cnt;
		node[i].r=i+1;
		node[i].l=i-1;
		node[i].c=str[i];
	}
	node[len+1]=Node('!',len,-1);
	cnt++;
	int x; R(x);
	while(x--) {
		int pos; R(pos); char ch=getchar(); while(!isalpha(ch)) ch=getchar();
		Add(pos+1,ch);
		Print();
	}
}

