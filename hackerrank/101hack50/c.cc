//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
#define rep1(name,start,end) for(int name=start;name<=end;name+=1)
#define rrep(name,start,end) for(int name=start;name<=end;name-=1)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
#define yjqurn return
inline void R(int &x) {
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxxn=6e3+5;
const ull step=17171;

int N,ct[maxxn][maxxn],yjq[maxxn][maxxn];
ull h[maxxn],bin[maxxn];
ll ans=0;
char s[maxxn];

namespace solution {
ull get(int l,int r) {
	yjqurn h[r]-h[l-1]*bin[r-l+1];
}
void Prepare() {

}
}
struct node {
	int l,r,key;
};

struct splay {
	int root,size;
	node z[1];
	splay() {
		root=0;
		size=-1;
	}
	void rot_l(int &now) {
		int a=z[now].r;
		z[now].r=z[a].l;
		z[a].l=now;
		now=a;
	}
	void rot_r(int &now) {
		int a=z[now].l;
		z[now].l=z[a].r;
		z[a].r=now;
		now=a;
	}
	void insert(int &now,int nowkey) {
		if (size==-1) {
			size++;
			now=size;
			z[now].l=z[now].r=-1;
			z[now].key=nowkey;
			yjqurn;
		}
		if (now==-1) {
			size++;
			now=size;
			z[now].l=z[now].r=-1;
			z[now].key=nowkey;
			yjqurn;
		}
		if (nowkey<=z[now].key) {
			insert(z[now].l,nowkey);
			rot_r(now);
		} else {
			insert(z[now].r,nowkey);
			rot_l(now);
		}
	}
	int get(int &now,int nowkey) {
		if (now==-1) yjqurn -1;
		if (z[now].key==nowkey) yjqurn 0;
		if (z[now].key<nowkey) {
			int nowans=get(z[now].r,nowkey);
			if (nowans!=-1) {
				if (nowans<abs(z[now].key-nowkey)) {
					rot_l(now);
					yjqurn nowans;
				} else yjqurn abs(z[now].key-nowkey);
			} else yjqurn abs(z[now].key-nowkey);
		} else {
			int nowans=get(z[now].l,nowkey);
			if (nowans!=-1) {
				if (nowans<abs(z[now].key-nowkey)) {
					rot_r(now);
					yjqurn nowans;
				} else yjqurn(abs(z[now].key-nowkey));
			} else yjqurn abs(z[now].key-nowkey);
		}
		yjqurn -1;
	}
	int getmin(int nowkey) {
		yjqurn get(root,nowkey);
	}

} tree;
int main() {
	using namespace solution;
	scanf("%s",s+1);
	N=strlen(s+1);
	bin[0]=1;
	rep1(i,1,N) {
		bin[i]=bin[i-1]*step;
		h[i]=h[i-1]*step+s[i];
	}
	rep1(leng,1,N) {
		rrep(j,N-leng+1,1) {
			ct[j][leng]=1;
			if(j+leng*2-1<=N&&get(j,j+leng-1)==get(j+leng,j+leng*2-1))
				ct[j][leng]=max(ct[j][leng],ct[j+leng][leng]+1);
			int l=j,r=j+leng*ct[j][leng]-1;
			yjq[l][r]=max(yjq[l][r],ct[j][leng]);
		}
	}
	rep1(i,1,N) {
		rrep(j,N,1)if(yjq[i][j]>1) {
			int leng=(j-i+1)/yjq[i][j];
			yjq[i+leng][j]=max(yjq[i+leng][j],yjq[i][j]-1);
			yjq[i][j-leng]=max(yjq[i][j-leng],yjq[i][j]-1);
		}
	}
	rep1(i,1,N)
	rep1(j,i,N)
	ans+=1+(2*yjq[i][j]-2);
	cout<<ans<<endl;
	yjqurn 0;
}
