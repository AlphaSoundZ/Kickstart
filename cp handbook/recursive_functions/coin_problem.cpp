#include <bits/stdc++.h>
typedef long long ll;
#define INF numeric_limits<int>::max()

#define Arrlen(a) (sizeof(a)/sizeof(*a))

using namespace std;

int32_t solve(int x);

int main() {
    cout << solve(10);
}

int solve(int x) {
    int coins[3] = {4, 3, 1};
    if (x < 0) return 100000;
    if (x == 0) return 0;
    int best = 100000;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1);
    }

    return best;
}

/*
Try to find every order of array elements with specific length.

wenn start value x = 5:
if1 = false;
if2 = false;
solve1: solve2(5-4 = 1): solve3(1-1 = 0):

*/