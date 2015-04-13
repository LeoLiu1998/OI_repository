#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t, n, num[101]={0};
    while(cin >> t){
        while(t--){
            int DP[101]={0}, Max = -10000;
            cin >> n;
            for(int i = 1; i <= n; i++)
                cin >> num[i];
            for(int i = 1; i <= n; i++){
                if(DP[i-1]+num[i] > num[i])
                    DP[i] = DP[i-1] + num[i];
                else    DP[i] = num[i];
                if(DP[i] > Max) Max = DP[i];
            }
            cout << Max << endl;
        }
    }
    return 0;
}