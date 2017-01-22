#include <stdio.h>  
#include <queue>  
using namespace std;  
int n,m,a[4000005],b[4000005];  
int cmp(const void *a,const void *b)  
{  
    return *(int *)a-*(int *)b;  
}  
int main()  
{  
    int t,flat,i,j,sum,k;  
    scanf("%d",&t);  
    while(t--)  
    {  
        int ai=1,bi=0,x,r,sum,a[2005];  
        scanf("%d%d",&n,&m);  
        priority_queue <int ,vector<int >,greater<int> >p;  
        priority_queue <int ,vector<int >,less<int> >q;  
        for(i=0; i<m; i++)  
        {  
            scanf("%d",&x);  
            p.push(x);  
        }  
        for(i=1; i<n; i++)  
        {  
            for(j=0; j<m; j++)  
            {  
                scanf("%d",&a[j]);  
            }  
            while(!p.empty())  
            {  
                sum=p.top();  
                p.pop();  
                for(j=0;j<m;j++)  
                {  
                    if(q.size()==m&&q.top()>sum+a[j])  
                    {  
                        q.pop();  
                        q.push(sum+a[j]);  
                    }  
                    else if(q.size()<m)  
                    {  
                         q.push(sum+a[j]);  
                    }  
                }  
            }  
            while(!q.empty())  
            {  
                p.push(q.top());  
                q.pop();  
            }  
        }  
        flat=0;  
        for(i=0;i<m;i++)  
        {  
            if(flat)  
            {  
                printf(" ");  
            }  
            printf("%d",p.top());  
            p.pop();  
            flat=1;  
        }  
        printf("\n");  
    }  
    return 0;  
}  