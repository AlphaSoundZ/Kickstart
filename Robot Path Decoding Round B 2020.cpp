#include <iostream>
#include <string>
typedef long long ll;

using namespace std;

int main()
{
    int t;
    string movements;
    cin >> t;
    cin >> movements;
    ll Pos[2] = {1, 1};

    for (int i = 0; i < movements.length(); ++i)
    {
        if ((movements[i] == "n")
        {
            ++Pos[1];
        }
        
    }
    cout << Pos[0] << " " << Pos[1] << endl;

}