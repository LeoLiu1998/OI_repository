#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
const int MAX_N=1010;
const double INF=1e90;
const double eps=1e-10;
const double PI=acos(-1.0);

int T,n,cases=0;

struct Point{
    double x,y;

    Point () {}
    Point (double x,double y) : x(x),y(y) {
    }
    Point operator + (const Point& rhs) const {
        return Point(x+rhs.x,y+rhs.y);
    }
    Point operator - (const Point& rhs) const {
        return Point(x-rhs.x,y-rhs.y);
    }
    Point operator * (const double d) const {
        return Point(d*x,d*y);
    }
    double dis(const Point& rhs) const { //两点距离
        return sqrt((x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y));
    }
    double dot(const Point& rhs) const { //点积、内积
        return (x*rhs.x+y*rhs.y);
    }
    double cross(const Point& rhs) const { //叉积、外积
        return (x*rhs.y-y*rhs.x);
    }
}point[MAX_N],vertex[MAX_N];

inline bool cmp_x(const Point a,const Point b)
{//优先x升序，其次y升序排序
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

//Graham扫描法
inline int Andrew()
{
    sort(point,point+n,cmp_x);
    int k=0;
    //构造下凸包
    for(int i=0;i<n;i++){
        while(k>1&&(vertex[k-1]-vertex[k-2]).cross(point[i]-vertex[k-1])<=0){
            k--;
        }
        //因为存凸包的顶点是从0开始的，而最左下的点一定是凸包顶点，所以k>1
        //因为如果k=1仍然继续执行的话,k-2就小于0了
        //当然如果凸包顶点是从1开始存储的话，那么这里就应该是k>2
        vertex[k++]=point[i];
    }
    //构造上凸包
    int m=k; //m是下凸包顶点数目，且最后一个顶点是point[n-1]
    for(int i=n-2;i>=0;i--){    //注意是从point[n-2]开始，避免重复point[n-1]
        while(k>m&&(vertex[k-1]-vertex[k-2]).cross(point[i]-vertex[k-1])<=0){
            k--;
        }
        vertex[k++]=point[i];
    }
    if(k>1) k--; //point[0]重复
    return k;
}

//给出一个凸包，判断凸包是否唯一确定(稳定凸包)，即判断凸包每条边上是否存在至少三个点
inline bool JudgeStableConvexHull()
{
    if(n<6) {
        return false;
    }
    int total=Andrew();
    vertex[total]=vertex[0];
    /*
    将边上的点也存进凸包顶点里，在判断的时候只需要判断凸包顶点中是否一定存在相邻向量叉积为0即可
    上面Andrew（）函数中需要将(vertex[k-1]-vertex[k-2]).cross(point[i]-vertex[k-1])<=0改为
    (vertex[k-1]-vertex[k-2]).cross(point[i]-vertex[k-1])<0
    for(int i=1;i<total;i++){
        if((vertex[i-1]-vertex[i]).cross(vertexi+1]-vertex[i])!=0
        &&(vertex[i]-vertex[i+1]).cross(vertex[i+2]-vertex[i+1])!=0){
            return false;
        }
    }
    return true;
    */

    for(int i=0;i<total;i++){ //遍历凸包边
        Point a=vertex[i],b=vertex[i+1];//该边端点是a和b
        int cnt=0;
        for(int j=0;j<n;j++){ //检查该边上点的个数
            if((point[j]-a).cross(b-point[j])==0){// 在这条边上的点
                cnt++;
                if(cnt>=3) break;
            }
        }
        if(cnt<3){ //少于三个点
            return false;
        }
    }
    return true;
}

//旋转卡壳求凸包直径(最远点距离)
inline double GetMostFarDistance()
{
    int total=Andrew();
    if(total==2){ //处理凸包退化的情况,只有两个顶点
        return vertex[0].dis(vertex[1]);
    }

    int i=0,j=0;//在某个方向上的对踵点
    //求出x轴方向上的对踵点对
    for(int k=0;k<total;k++){
        if(!cmp_x(vertex[i],vertex[k])) i=k;
        if(cmp_x(vertex[j],vertex[k])) j=k;
    }
    double ans=0;
    int si=i,sj=j;
    while(i!=sj||j!=si){ //将方向逐步旋转180度
        ans=max(ans,vertex[i].dis(vertex[j]));
        //判断先转到边i-(i+1)的法线方向还是边j-(j+1)的法线方向
        int nexti=(i+1)%total,nextj=(j+1)%total;
        if((vertex[nexti]-vertex[i]).cross(vertex[nextj]-vertex[j])<0){
            i=nexti; //先转到边i-(i+1)的法线方向
        }else {
            j=nextj; //先转到边j-(j+1)的法线方向
        }
    }
    return ans;
}

//计算凸包面积
//将凸包看成一个个以凸包最左下顶点为顶点的凸包边为对边的三角形。 
//那么依次扫个条边，计算三角形面积累加即可。 
//已知三角形三条边计算三角形面积，可用海伦–秦九韶公式
inline double GetConvexHullArea()
{
    int total=Andrew();
    if(total<=2){
        return 0.0;
    }
    double area=0;
    for(int i=2;i<total;i++){
        double a=vertex[i-1].dis(vertex[0]);
        double b=vertex[i].dis(vertex[0]);
        double c=vertex[i].dis(vertex[i-1]);
        double p=(a+b+c)/2;
        area+=sqrt(p*(p-a)*(p-b)*(p-c));
    }
    return area;
}

//计算凸包周长
inline double GetConvexHullPerimeter()
{
    int total=Andrew();
    vertex[total]=vertex[0];
    double ans=0;
    for(int i=0;i<total;i++){
        ans+=vertex[i].dis(vertex[i+1]);
    }
    return ans;
}

inline double GetArea(Point a,Point b,Point c)//计算顶点为a,b,c的三角形面积
{
    double len1=a.dis(b);
    double len2=a.dis(c);
    double len3=b.dis(c);
    double p=(len1+len2+len3)/2;
    return sqrt(p*(p-len1)*(p-len2)*(p-len3));
}

//旋转卡壳求凸包最大三角形面积，时间复杂度O(total^2),total是凸包顶点数
inline double GetBiggestTriangleAreaInConvexHull()
{
    int total=Andrew();
    vertex[total]=vertex[0];
    double ans=0.0;
    for(int i=0;i<total;i++){
        int j=(i+1)%total;
        int k=(j+1)%total;
        while(j!=i&&k!=i){
            ans=max(ans,fabs((vertex[j]-vertex[i]).cross(vertex[k]-vertex[i])/2.0)); 
            //已知三角形三顶点，利用叉积计算面积或者海伦-秦九韶公式
            //ans=max(ans,GetArea(vertex[i],vertex[j],vertex[k]));        
            while(k!=i&&(vertex[j]-vertex[i]).cross((vertex[k+1]-vertex[k]))<0){
                k=(k+1)%total;
            }
            j=(j+1)%total;
        }
    }
    return ans;
}

//最小覆盖矩形面积
inline double MinimalRetangleCover()
{
    int total=Andrew();
    if(total<=2){
        return 0.0;
    }
    double ans=INF;
    // O(total)算法
    vertex[total]=vertex[0];
    int r=1,p=1,q;
    for(int i=0;i<total;i++){
        double edge=vertex[i].dis(vertex[i+1]);
        double tmp1,tmp2;
        while(1){ //卡出离边vertex[i]--vertex[i+1]最远的点
            tmp1=(vertex[i+1]-vertex[i]).cross(vertex[r+1]-vertex[i]); //叉积
            tmp2=(vertex[i+1]-vertex[i]).cross(vertex[r]-vertex[i]);
            if(tmp2>tmp1) break;
            r=(r+1)%total;
        }
        double height=tmp2/edge;

        while(1){ //卡出在vertex[i]--vertex[i+1]方向上正向最远的点
            tmp1=(vertex[i+1]-vertex[i]).dot(vertex[p+1]-vertex[i]); //点积
            tmp2=(vertex[i+1]-vertex[i]).dot(vertex[p]-vertex[i]);
            if(tmp2>tmp1) break;
            p=(p+1)%total;
        }
        double len1=tmp2/edge;
        //len1是从vertex[i]出发沿vertex[i]--vertex[i+1]正方向能达到的最大距离

        if(i==0) q=p;
        while(1){ //卡出在vertex[i]--vertex[i+1]方向上负方向最远的点
            tmp1=(vertex[i+1]-vertex[i]).dot(vertex[q+1]-vertex[i]); //点积
            tmp2=(vertex[i+1]-vertex[i]).dot(vertex[q]-vertex[i]);
            if(tmp2<tmp1) break; //和上面的不一样
            q=(q+1)%total;
        }
        double len2=tmp2/edge;
        //len2是从vertex[i]出发沿vertex[i]--vertex[i+1]负方向能达到的最大距离

        double len=len1-len2;
        ans=min(ans,len*height);
    }

    /* O(total^2)算法 
    for(int i=0;i<total;i++){ //遍历每一条边
        Point A,B;
        A=vertex[i],B=vertex[(i+1)%total];
        double AB=A.dis(B);
        double leftA,rightA,leftB,rightB,height;
        leftA=rightA=leftB=rightB=height=0.0;
        for(int j=0;j<total;j++){ //遍历凸包每一个顶点
            Point C=vertex[j];
            double d=(B-A).cross(C-A)/AB;
            height=max(height,d); //更新高

            double tmp=(B-A).dot(C-A)/AB;//更新A点左右最大距离
            if(tmp>0) rightA=max(rightA,tmp);
            else leftA=max(leftA,-tmp);

            tmp=(A-B).dot(C-B)/AB; //更新B点左右最大距离
            if(tmp<0) rightB=max(rightB,-tmp);
            else leftB=max(leftB,tmp);
        //  printf("i=%d j=%d rihgtA=%.2f rightB=%.2f\n",i,j,rightA,rightB);
        }
        double len1=max(leftA,leftB-AB); //左端最大超出
        double len2=max(rightB,rightA-AB); //右端最大超出
        double len=len1+len2+AB; //len即是长
        //printf("len1=%.2f len2=%.2f len=%.2f height=%.2f\n",len1,len2,len,height);
        ans=min(ans,len*height); //更新最小外接矩形
    }
    */
    return ans;
}


//计算凸包最小外接平行四边形面积[一定有两条边是凸包的边]
double height[MAX_N];//用于存储凸包每条边上最远顶点到这条边的距离
double edge[MAX_N];//存储边长度

inline double MinimalParallelogramCover()
{
    int total=Andrew();
    if(total<=2){
        return 0.0;
    }
    vertex[total]=vertex[0];
    //求每条边最远顶点距离，即是这条边上对应的高
    for(int i=0;i<total;i++){
        height[i]=-1.0; 
        edge[i]=vertex[i].dis(vertex[i+1]);
        for(int j=0;j<total;j++){
            double tmp=((vertex[i+1]-vertex[i]).cross(vertex[j]-vertex[i]));
            //edge;顶点vertex[j]到边i--(i+1)的距离
            height[i]=max(height[i],fabs(tmp/edge[i]));
        }
    }
    double ans=INF;
    //枚举两条边计算以这两条边为平行四边形边的平行四边形
    for(int i=0;i<total;i++){
        Point tmp1=vertex[i+1]-vertex[i];
        for(int j=0;j<total;j++){
            Point tmp2=vertex[j+1]-vertex[j];
            double angle=(tmp1.cross(tmp2))/edge[i]/edge[j];    //计算向量夹角的正弦值
            if(fabs(angle)<eps) continue;
            ans=min(ans,height[i]*height[j]/fabs(angle));
            //已知平行四边形两组对边上的高及一个内角的正弦值求平行四边形的面积
        }
    }
    return ans;
}
int cnt=0;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&point[i].x,&point[i].y);
        }
        printf("Swarm %d Parallelogram Area: %.4f\n",++cnt,MinimalParallelogramCover());
    }
    return 0;
}
