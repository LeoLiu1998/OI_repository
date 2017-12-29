//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#ifdef _WIN32
#define Pln(x) printf("%I64d\n",x)
#define Pls(x) printf("%I6d ",x)
#else
#define Pln(x) printf("%lld\n",x)
#define Pls(x) printf("%lld ",x)
#endif
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
const int mod=1e9+7;
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
#ifndef DEBUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int anc[5];
struct splay_node
{
    int num,maxx,ls,rs,fath;
    bool lazy;
}p[5];
struct lct
{
    inline void _pushdown(int i)
    {
        p[i].lazy^=1;
        p[p[i].ls].lazy^=1;
        p[p[i].rs].lazy^=1;
        int t=p[i].ls;p[i].ls=p[i].rs;p[i].rs=t;
    }
    inline void _pushup(int i)
    {
        p[i].maxx=max(max(p[p[i].ls].maxx,p[p[i].rs].maxx),p[i].num);
    }
    inline void _zig(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].rs].fath=j;
        p[j].ls=p[i].rs;
        p[i].rs=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    inline void _zag(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].ls].fath=j;
        p[j].rs=p[i].ls;
        p[i].ls=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    void _splay(int i)
    {
        int j;
        while(p[i].fath!=0)
        {
            j=p[i].fath;
            if(p[p[j].fath].lazy==true)_pushdown(p[j].fath);
            if(p[j].lazy==true)_pushdown(j);
            if(p[i].lazy==true)_pushdown(i);
            if(p[j].fath==0)
            {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            }
            else if(j==p[p[j].fath].ls)
            {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            }
            else
            {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_max(int i)
    {
        while(i!=0)
        {
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].ls!=0&&p[i].maxx==p[p[i].ls].maxx)i=p[i].ls;
            else if(p[i].maxx==p[i].num)return i;
            else i=p[i].rs;
        }
        return i;
    }
    void _access(int i)
    {
        int j=0;
        while(i!=0)
        {
            _splay(i);
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].rs!=0)
            {
                p[p[i].rs].fath=0;
                anc[p[i].rs]=i;
            }
            p[i].rs=j;
            p[j].fath=i;
            _pushup(i);
            j=i;i=anc[i];
        }
    }
    void _setroot(int i)
    {
        _access(i);
        _splay(i);
        p[i].lazy^=1;
    }
}T;
struct Mat {
    const static int N=15;
    ll d[17][17];
    Mat() {
        memset(d,0,sizeof d);
    }
    Mat operator * (const Mat &a) const  {
        Mat ret;
        for(int i=0; i<=N; ++i)  {
            for(int j=0; j<=N; ++j) {
                ret.d[i][j]=0;
                for(int k=0; k<=N; ++k) {
                    ret.d[i][j]+=d[i][k]*a.d[k][j];
                    ret.d[i][j]%=mod;
                }
            }
        }
        return ret;
    }
};
Mat qpow(Mat x, ll p) {
    Mat ret;
    for(int i=0; i<=ret.N; ++i) ret.d[i][i]=1;
    while(p) {
        if(p&1) {
            ret=ret*x;
        }
        x=x*x;
        p>>=1;
    }
    return ret;
}

struct cp{
	double x,y;
	  cp(){}
	  cp(double x,double y):x(x),y(y){}
	  cp operator+(const cp&b){return cp(x+b.x,y+b.y);}
	  cp operator-(const cp&b){return cp(x-b.x,y-b.y);}
	  cp operator*(const cp&b){return cp(x*b.x-y*b.y,x*b.y+y*b.x);}
};
struct Blo{
	double sum,mul,add;
}blo[500];
int blon;
int blol;
double a[(int)2e5+20];
int n,m;

inline int getIdx(int x) {
	return ((x-1)/blol)+1;
}

inline int getL(int x) {
	return (x-1)*blol+1;
}

inline int getR(int x) {
	return x*blol > n ? n: x*blol ;
}

inline bool Ori(int idx) {
	return fabs(blo[idx].mul-1)<1e-8&&fabs(blo[idx].add)<1e-8;
}

inline void pushdown(int x) {
	if(Ori(x))
		return ;
	int l=getL(x),r=getR(x);
	blo[x].sum=0;
	rep(i,l,r,1) {
		a[i]=a[i]*blo[x].mul+blo[x].add;
		blo[x].sum+=a[i];
	}
	blo[x].mul=1; blo[x].add=0;
}

inline double Query(int l,int r) {
	int lb=getIdx(l),rb=getIdx(r);
	double ret=0;
	if(lb==rb) {
		if(l==getL(lb)&&r==getR(lb)) 
			if(Ori(lb)) return blo[lb].sum;
			else return blo[lb].sum*blo[lb].mul+(r+1-l)*blo[lb].add;
		pushdown(lb);
		rep(i,l,r,1) 
			ret+=a[i];
		return ret;
	}
	rep(i,lb+1,rb-1,1) {
		if(Ori(i)) ret+=blo[i].sum;
		else ret+=blo[i].sum*blo[i].mul+(getR(i)+1-getL(i))*blo[i].add;
	}
	return Query(l,getR(lb))+ret+Query(getL(rb),r);
}

void Update(int idx,double mul,double add) {
	blo[idx].add=blo[idx].add*mul+add;
	blo[idx].mul*=mul;
}

void Build(int idx) {
	int l=getL(idx),r=getR(idx);
	blo[idx].sum=0;
	rep(i,l,r,1)
		blo[idx].sum+=a[i];
	blo[idx].mul=1;
	blo[idx].add=0;
}

void ModBlo(int l,int r,double mul,double add) {
	int lb=getIdx(l),rb=getIdx(r);
	if(lb==rb) {
		if(l==getL(lb)&&r==getR(lb)) {
			Update(lb,mul,add);
			return ;
		}
		pushdown(lb);
		rep(i,l,r,1) {
			a[i]=a[i]*mul+add;
		}
		Build(lb);
		return ; 
	}
	ModBlo(l,getR(lb),mul,add);
	ModBlo(getL(rb),r,mul,add);
	rep(i,lb+1,rb-1,1)
		Update(i,mul,add);
}

void Modify(int l1,int r1,int l2,int r2) {
	int len1=(r1-l1)+1;
	int len2=(r2-l2)+1;
	double s1=Query(l1,r1);
	double s2=Query(l2,r2);
	ModBlo(l1,r1,1.0*(len1-1)/len1,s2/len2/len1);
	ModBlo(l2,r2,1.0*(len2-1)/len2,s1/len1/len2);
}

void Build() {
	blol=sqrt(n);
	cerr<<blol<<endl;
	blon=(n+(blol-1))/blol;
	rep(i,1,n,1) {
		blo[getIdx(i)].sum+=a[i];
		blo[getIdx(i)].mul=1;
		blo[getIdx(i)].add=0;
	}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v1(1), v2(1);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int p;
		char c;
		cin >> p >> c;
		if (c == 'G') {
			v1.push_back(vector<int>());
			v2.push_back(vector<int>());
			vec.push_back(p);;
		} else if (c == 'R') {
			v1.back().push_back(p);
		} else {
			v2.back().push_back(p);
		}
	}
	long long ans = 0;
	if (vec.empty()) {
		for (int i = 1; i < v1[0].size(); i++) {
			ans += v1[0][i] - v1[0][i - 1];
		}
		for (int i = 1; i < v2[0].size(); i++) {
			ans += v2[0][i] - v2[0][i - 1];
		}
		cout << ans << endl;
		return 0;
	}
	v1[0].push_back(vec[0]);
	v2[0].push_back(vec[0]);
	for (int i = 1; i < v1[0].size(); i++) {
		ans += v1[0][i] - v1[0][i - 1];
	}
	for (int i = 1; i < v2[0].size(); i++) {
		ans += v2[0][i] - v2[0][i - 1];
	}
	for (int i = 1; i + 1 < v1.size(); i++) {
		long long sum = vec[i] - vec[i - 1];
		long long L = vec[i] - vec[i - 1];
		if (v1[i].size()) {
			int mx = max(v1[i][0] - vec[i - 1], vec[i] - v1[i].back());
			for (int j = 1; j < v1[i].size(); j++) {
				mx = max(mx, v1[i][j] - v1[i][j - 1]);
			}
			sum += L - mx;
		}
		if (v2[i].size()) {
			int mx = max(v2[i][0] - vec[i - 1], vec[i] - v2[i].back());
			for (int j = 1; j < v2[i].size(); j++) {
				mx = max(mx, v2[i][j] - v2[i][j - 1]);
			}
			sum += L - mx;
		}
		ans += min(2 * L, sum);
	}
	if (v1.back().size()) {
		ans += v1.back()[0] - vec.back();
	}
	if (v2.back().size()) {
		ans += v2.back()[0] - vec.back();
	}
	for (int i = 1; i < v1.back().size(); i++) {
		ans += v1.back()[i] - v1.back()[i - 1];
	}
	for (int i = 1; i < v2.back().size(); i++) {
		ans += v2.back()[i] - v2.back()[i - 1];
	}
	cout << ans << endl;
	return 0;
}
