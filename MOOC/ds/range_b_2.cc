#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
 
const int maxn = 5*100000+20;
int a[maxn];
 
int cmp(const void* a, const void* b) {
    return (*(int*) a)>(*(int*) b)?1:-1;
}
 
int find_lowbound(int* array, int left, int right, int key) {
 
    int ans = right;
    if(right == left)
        return ans;
 
    while(left <= right) {
        int mid = (right + left) / 2;
        if(key == array[mid])
            return mid;
        if(key < array[mid]){
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    //cout<<"test"<<endl;
    return ans;
}
int main() {
 
    int n,s;
    while(~scanf("%d%d",&n,&s)) {
        
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        while(s--) {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x>a[n-1] || y<a[0]) {
                printf("0\n");
                continue;
            }           
            int p1 = find_lowbound(a,0,n-1,x);
            int p2 = find_lowbound(a,0,n-1,y);
            if(a[p2] > y) p2--;
            printf("%d\n",p2-p1+1);
        }
    }
    return 0;
}