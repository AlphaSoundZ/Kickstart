#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main() {
    int t, n, f, bus; 
    ll d;
    cin >> t;
    for (ll i = 1; i <= t; ++i)
    {
        cin >> n;
        cin >> d;
        
        ll x[n];
        for (ll e = 0; e < n; ++e)
            cin >> x[e];

        for (ll i = n-1; i >= 0; --i)
            d = d-(d % x[i]);
        cout << "Case #" << i << ": " << d << endl;
    }
    return 0;
}