#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t, n, h[100000];
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int peaks = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
            if (i > 1) {
                if ( h[i-2] < h[i-1] && h[i-1] > h[i]) {
                    ++peaks;
                }
            }
        }
        cout << "Case #" << i << ": " << peaks << endl;
    }
    return 0;
}