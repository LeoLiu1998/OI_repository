#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <time.h>
#include <string>
#include <vector>
#include <math.h>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define ft first
#define sc second
#define mp make_pair
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;
typedef long double ld;
typedef pair <li, li> pli;
typedef pair <int, int> pii;

const int N = 300000;

int n, k, a, m, ships;

set <pii> xs;

int calc(int l, int r)
{
    return (r - l + 2) / (a + 1);
}

int main()
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d %d %d", &n, &k, &a, &m);

    xs.insert(mp(n, 1));

    ships = calc(1, n);

    forn(i, m)
    {
        int x, newk1 = 0, newk2 = 0;
        scanf("%d", &x);

        auto it = xs.lower_bound(mp(x, -1));

        int l = it->sc, r = it->ft;

        if(x - 1 >= l)
            newk1 = calc(l, x - 1);
        if(x + 1 <= r)
            newk2 = calc(x + 1, r);

        ships -= calc(l, r);
        ships += newk1 + newk2;

        if(ships < k)
        {
            printf("%d\n", i + 1);
            return 0;
        }

        xs.erase(it);
        if(x - 1 >= l)
            xs.insert(mp(x - 1, l));
        if(x + 1 <= r)
            xs.insert(mp(r, x + 1));
    }

    printf("-1\n");
    return 0;
}