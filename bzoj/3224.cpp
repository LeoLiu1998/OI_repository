/*Copyright (c)2014 YeGuanghao
 *This source-code is licensed under GPLv3
 */
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#define PROB ""
using namespace std;
inline void Read(int & x)
{
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        ch = getchar();
    }
    x = 0;
    while(ch <= '9' && ch >= '0') {
        x *= 10, x += ch - '0';
        ch = getchar();
    }
}
struct node {
    int v;
    node * parent;
    vector<*node> child;
    node(): v(0), parent(NULL), {
        child.clear();
    }
};
 
node * newnode()
{
    return new node();
}
 
int n;
void Insert(int);
void Delete(int);
void QueryRank(int);
void Query(int);
void QueryPre(int);
void QuerySuf(int);
node root;
bool first;
int main(int argc, char * argv[])
{
    Read(n);
    first = true;
    int opt, temp;
    while(n--) {
        Read(opt);
        Read(temp);
        switch(opt) {
        case 1: Insert(temp);
            break;
        case 2: Delete(temp);
            break;
        case 3: QueryRank(temp);
            break;
        case 4: Query(temp);
            break;
        case 5: QueryPre(temp);
            break;
        case 6: QuerySuf(temp);
        }
    }
}
 
void Insert(int value)
{
    if(first) {
        root.v=value;
        return ;
    }
}