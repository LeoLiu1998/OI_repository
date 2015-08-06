#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
  
using namespace std;
  
#include <algorithm>
  
typedef unsigned long long lli;
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

int sets[200010], end[200010], rank[200010];

inline int findSet(int i) { 
    if( sets[i] == i ) return i;

    return sets[i] = findSet( sets[i] ); 
}

inline void unionSet(int i, int j) { 
    int ri = findSet(i);
    int rj = findSet(j);
    sets[ri]=sets[rj]=min(ri,rj);
}

bool isSameSet(int i, int j) { 
    return findSet(i) == findSet(j); 
}
 
int main(void){
  
    int n, q;
    R(n); R(q);//scanf("%d %d", &n, &q );
    for( int i = 1; i <= n; i++ ){
        sets[i] = end[i] = i;
    }
    int t, x, y;
    while(q--){
        //scanf("%d %d %d", &t, &x, &y );
	R(t); R(x); R(y);
	if( t == 1 ){
            unionSet(x,y);
        }
        else if( t == 2 ){
            int mi=min(x,y);
	    int ma=max(x,y);
	    x=mi;
	    y=ma;
		int xs = findSet(x);
            for( int i = x+1; i <= y; ){
                int k=end[i];
		end[i] = max(end[i],y);
                unionSet(xs,i);
                i = max(k+1,i+1);
            }
        }
        else{
            //printf("%s\n", isSameSet(x,y) ? "YES" : "NO" );     
            if(isSameSet(x,y)) {
            	puts("YES");
	    } else {
	    	puts("NO");
	    }
	}
    }
    
      
    return 0;
}
