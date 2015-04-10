/*Copyright (c)2014 Ye Guanghao
 *This sourcecode is licensed under GPLv3
 */
#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const double pi=3.1415926535898;
using namespace std;
using namespace std; 
int main(){ 
    for(int a = 0; a < 25; a++)
    { 
        int c = a; 
        for(int b = 0;  b < 18; b++)
        { 
            char ch = 'A'  + ( c > 0 ? c : -c); 
            cout << ch; 
            c--; 
        } 
        cout << endl; 
    } 
    return 0; 
}