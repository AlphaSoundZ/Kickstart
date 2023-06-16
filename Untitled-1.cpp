#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int n = 999983*999979;
    vector<int> factors;
    for (int i = 2; i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    cout << *max_element(factors.begin(), factors.end()) << endl;
}

bool isPrime(unsigned int prime)
{
    for (unsigned int i = 2; i <= prime / 2; i++)
    {
        if (prime % i == 0)
        {
            return 1;
        }
    }
    return 0;
}

unsigned int generatePrimeNumber(unsigned int min, unsigned int max)
{
    for (unsigned int i = max; i >= min; i--)
    {
        if (isPrime(i))
        {
            return i;
        }
    }
    return 0;
}