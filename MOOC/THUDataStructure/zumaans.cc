#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <utility>
using namespace std;

#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define pb push_back
#define PROB "hao"


static inline 
void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	x*=f;
}

static inline 
void R(char &x) {
	x=getchar(); while(x<'A'||x>'Z') x=getchar();
}

struct Node {
	int nex,pre; 
	char colo;
};
Node node[40005];
char s[20005];
const int last=40000;
int cnt=0;
int n;

const int SZ = 1<<20;  //fast io  
struct fastio{  
    char inbuf[SZ];  
    char outbuf[SZ];  
    fastio(){  
        setvbuf(stdin,inbuf,_IOFBF,SZ);  
        setvbuf(stdout,outbuf,_IOFBF,SZ);  
    }  
}io;  

void Build() {
	node[last].colo='-';
	node[last].nex=last;
	node[0].colo='-';
	node[0].nex=last;
	int l=strlen(s+1);
	s[l--]=0;
	for(int i=1;i<=l;++i) {
		node[cnt].nex=cnt+1;
		node[++cnt].colo=s[i];
		node[cnt].pre=cnt-1;
	}
	node[cnt].nex=last;
	node[last].pre=cnt;
}

void insert(int l, int r , int cur) {
	node[l].nex=cur;
	node[cur].pre=l;
	node[cur].nex=r;
	node[r].pre=cur;
}

static inline
void link(int l,int r) {
	node[l].nex=r;
	node[r].pre=l;
}


void check(int cur) {
	int cnt=1;
	int rpos=cur;
	while(node[rpos].colo==node[cur].colo&&node[rpos].colo!='-') {
		rpos=node[rpos].nex;
		cnt++;
	}
	int lpos=cur;
	cnt-=2;
	while(node[lpos].colo==node[cur].colo&&node[lpos].colo!='-') {
		lpos=node[lpos].pre;
		cnt++;
	}
	if(cnt>=3) {
		link(lpos,rpos);
		if(node[lpos].colo!='-') check(lpos);
		//if(node[rpos].colo!='-') check(rpos);
	}
}
int p_cnt=0;
void solve(int pos,char v) {// means insert a  v colored node in after pos 
	node[++cnt].colo=v;
	insert(pos,node[pos].nex,cnt);
	check(cnt);
	p_cnt=0;
	int cur=0;
	while(cur!=last) {
		if(node[cur].colo!='-') {
			p_cnt++;
			printf("%c",node[cur].colo);
		}
		cur=node[cur].nex;
	}
	puts((p_cnt==0?"-":""));
}

int find(int  pos) {
	int cur=0,cur_cnt=0;	
	while(cur_cnt!=pos) {
		cur=node[cur].nex;
		cur_cnt++;
	}
	return cur;
}
int main() {
	//freopen("input.txt","r",stdin);
	fgets(s+1,15000,stdin);//scanf("%s",s+1);	
	Build();
	R(n);
	for(int i=1;i<=n;++i) {
		int pos; char v;
		R(pos); R(v);
		solve(find(pos),v);
	}
}

