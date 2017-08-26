//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-8;
double a, b, c, X1, Y1, z1, X2, Y2, z2;
double vX1, vX2, vY1, vY2, vz1, vz2, r1, r2, t;

double sqr(double X) {
    return X*X;
}

double check(double a, double b, double c) {
    if (fabs(a) < eps) {
        if (fabs(b) < eps) {
            if (fabs(c) < eps) return 0;
            else return -1;
        }
        if ((-c)*b > -eps) return (-c)/b;
        else return -1;
    }
    if (sqr(b)-4*a*c < -eps) return -1;
    if ((-b+sqrt(fabs(sqr(b)-4*a*c)))/(2*a) < -eps) return -1;
    if ((-b-sqrt(fabs(sqr(b)-4*a*c)))/(2*a) < -eps)
        return (-b+sqrt(fabs(sqr(b)-4*a*c)))/(2*a);
    else return (-b-sqrt(fabs(sqr(b)-4*a*c)))/(2*a);
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%lf %lf %lf %lf %lf %lf %lf", &X1, &Y1, &z1, &r1, &vX1, &vY1, &vz1);
        scanf("%lf %lf %lf %lf %lf %lf %lf", &X2, &Y2, &z2, &r2, &vX2, &vY2, &vz2);

        if (sqrt(sqr(X1-X2)+sqr(Y1-Y2)+sqr(z1-z2)) - (r1+r2) < eps) {
            printf("0.000\n");
            continue;
        }

        a = sqr(vX1-vX2)+sqr(vY1-vY2)+sqr(vz1-vz2);
        b = 2*((vX1-vX2)*(X1-X2)+(vY1-vY2)*(Y1-Y2)+(vz1-vz2)*(z1-z2));
        c = sqr(X1-X2)+sqr(Y1-Y2)+sqr(z1-z2)-sqr(r1+r2);
        t = check(a, b, c);
        if (fabs(t+1) < eps) printf("No collision\n");
        else printf("%.3lf\n", fabs(t));
    }
}
