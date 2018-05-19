#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int a[26];
    static bool cmp(char x,char y) {
        return a[x-'a']<a[y-'a'];
    }
    string customSortString(string S, string T) {
        memset(a,0x3f,sizeof a);
        for(int i=0;i<S.size();++i) {
            a[S[i]-'a']=min(i,a[S[i]-'a']);
        }
        sort(T.begin(),T.end(),cmp);
        return T;
    }
};
