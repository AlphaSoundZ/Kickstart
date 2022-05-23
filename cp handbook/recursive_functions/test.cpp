#include <bits/stdc++.h>
typedef long long ll;
#define INF numeric_limits<int>::max()

#define Arrlen(a) (sizeof(a)/sizeof(*a))

using namespace std;

int solve(int n);

int main() {
    cout << solve(6);
}

int solve(int n) {
    int m = 4;
    int result;
    if (m == 0) return 0;
    if (n >= 0) return 1;

    for (int i = 1; i <= m; i++)
    {
        result = solve(n-i);
    }
    return result;

}
/*
Try to find every order of array elements with specific length.

wenn start value x = 5:
if1 = false;
if2 = false;
solve1: solve2(5-4 = 1): solve3(1-1 = 0):

*/