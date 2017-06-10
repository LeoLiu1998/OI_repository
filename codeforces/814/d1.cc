#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 200003;
int in() {
    int k = 0, fh = 1; char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-') fh = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        k = k * 10 + c - 48;
    return k * fh;
}

struct Circle {
    int x, y, r;
    Circle(int _x = 0, int _y = 0, int _r = 0)
        : x(_x), y(_y), r(_r) {}
} C[N];

struct Point {
    int id, x, mark;
    Point(int _id = 0, int _x = 0, int _mark = 0)
        : id(_id), x(_x), mark(_mark) {}
    bool operator < (const Point &A) const {
        return x < A.x;
    }
} P[N << 1];

struct node {
    int id, mark;
    node(int _id = 0, int _mark = 0)
        : id(_id), mark(_mark) {}
};

ll sqr(int x) {return 1ll * x * x;}

int n, tot = 0, nowx, k[N];

set <node> S;
set <node> :: iterator tmp;

bool operator < (node A, node B) {
    double Y1 = (double) C[A.id].y + (double) A.mark * sqrt(sqr(C[A.id].r) - sqr(C[A.id].x - nowx));
    double Y2 = (double) C[B.id].y + (double) B.mark * sqrt(sqr(C[B.id].r) - sqr(C[B.id].x - nowx));
    //return Y1 != Y2 ? Y1 < Y2 : A.mark < B.mark;
	if(Y1!=Y2) {
		return Y1<Y2;
	}
	if(A.mark!=B.mark) return A.mark<B.mark;
	return C[A.id].r > C[B.id].r;
}

ll ans = 0;

int main() {
    int x, y, r;
    n = in();
    for (int i = 1; i <= n; ++i) {
        x = in(); y = in(); r = in();
        C[i] = Circle(x, y, r);
        P[++tot] = Point(i, x - r, 1);
        P[++tot] = Point(i, x + r, -1);
    }
    sort(P + 1, P + tot + 1);
    for (int i = 1; i <= tot; ++i) {
        nowx = P[i].x;
        if (P[i].mark == 1) {
            tmp = S.upper_bound(node(P[i].id, 1));
            if (tmp == S.end())
                k[P[i].id] = 1;
            else
                if (tmp->mark == 1)
                    k[P[i].id] = k[tmp->id]+1;
                else
                    k[P[i].id] = k[tmp->id];
            S.insert(node(P[i].id, 1));
            S.insert(node(P[i].id, -1));
        } else {
            S.erase(node(P[i].id, 1));
            S.erase(node(P[i].id, -1));
        }
    }
    
    for(int i = 1; i <= n; ++i) {
	//if(k[i]&1) k[i]++;
	//k[i]>>=1;
	//if(k[i]%2==1) k[i]=1;
	//else k[i]=-1;
        ans += sqr(C[i].r) * (((k[i]<=2)||(!(k[i]&1))) ? 1 : -1);//(((k[i]<=2)||(k[i]&1==1)) ? 1 : -1);
	printf("%d %d %d %d %d %d\n",C[i].x,C[i].y,C[i].r,k[i],((k[i]<=2)||(!(k[i]&1))) ? 1 : -1,ans);
    }
    printf("%.10f\n",(double)ans*3.14159265359);
    return 0;
}
