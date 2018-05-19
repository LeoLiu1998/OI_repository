//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        for(auto gh:ghosts) {
            int l = abs(gh[0]-target[0]), r= abs(gh[1]-target[1]);
            int t1 = l+r;
            int l1 = abs(target[0]), r1 = abs(target[1]);
            int t2 = l1+r1;
            if(t1<=t1) return 0;
        }
        return 1;
    }
};
int main() {
    Solution sol;
    cout<<sol.escapeGhosts(vector([vector([1,0]),vector([0,3])]),[0,1]);
}
