#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)
int n;
int tot;

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
    	in>>n;
	for(int i=1;i<=n;++i) {
		int temp; in>>temp;
		tot+=temp;
	}
	in>>n;
	for(int i=1;i<=n;++i) {
		int l,r; in>>l>>r;
		if(l>=tot) {
			out<<l<<endl;
			return ;
		} 
		if(tot<=r) {
			out<<tot<<endl;
			return ;
		}
	}
	out<<-1<<endl;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}


