#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve();

int main() {
    int t;
    cin >> t;
    cout << "Case #" << "1" << ": " << endl;
    solve();

    for (int i = 1; i <= t; i++)
    {
    }
    return 0;
}

void solve() {
    cout << "test" << endl;
    int n, d;
    int result = 0;
    int x[100000];
    int f;
    cin >> n;
    cin >> d;

    for (int e = 0; e < n; ++e)
    {
        cin >> x[e];
    }
    for (int i = n-1; i > 0; --i)
    {
        cout << "result:: " << endl;
        f = d % x[i];
        if (d-f > result) {
            cout << "try x[i] days before";
        }
        else {
            result = d-f;
            cout << result << endl;
        }
    }
}