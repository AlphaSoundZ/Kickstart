#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <numeric>
#include <limits>
#include <iomanip>


typedef long double ld;

using namespace std;

ld average(vector<ld> data);
vector<ld> getData(string file);
ld min_variance(vector<ld> data, ld min_value, ld max_value, ld max_slope, unsigned int accuracy);
ld line(ld m, ld x, ld b = 0.0);
ld variance(vector<ld> data, ld m, ld b = 0.0);

int main() { 
    ld min_value = numeric_limits<ld>::max();
    ld max_value = numeric_limits<ld>::min();
    
    // read file
    vector<ld> data = getData("data3.dat");
    if (data.size() == 0)
        return 0;

    ld av = average(data);
    cout << "Mittelwert: " << setprecision(15) << av << endl;

    for (ld x : data)
    {
        min_value = min(x, min_value);
        max_value = max(x, max_value);
    }

    const ld max_slope = (max_value - min_value) / data.size();

    ld result = min_variance(data, min_value, max_value, max_slope, 1000);

    cout << "maxslope: " << max_slope << endl;
    cout << "Variance: " << setprecision(15) << result << endl;

    return 0;
}

ld average(vector<ld> data) {
    ld ans = 0;
    for (ld x : data)
    {
        ans += x;
    }
    ans /= data.size();
    return ans;
}

vector<ld> getData(string filename) {
    string line;
    vector<ld> data;
    // read file 
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return vector<ld>{};
    }
    while(getline(file, line)) {
        // convert string to ld and push to data
        data.push_back(stold(line));
    }
    file.close();

    return data;
}

ld min_variance(vector<ld> data, ld min_value, ld max_value, ld max_slope, unsigned int accuracy)
{
    ld m, result = numeric_limits<ld>::max(), result_m;
    
    // calculate m
    for (ld i = -1*ceil(max_slope*accuracy); i < ceil(max_slope*accuracy); i++)
    {
        m = i/accuracy;
        ld var = variance(data, m);

        if (var < result)
        {
            result = var;
            result_m = m;
        }
    }

    // calculate b
    ld b, result_b;
    for (ld i = floor(min_value*accuracy); i < ceil(max_value*accuracy); i++)
    {
        b = i/accuracy;
        ld var = variance(data, result_m, b);
        
        if (var < result)
        {
            result = var;
            result_b = b;
        }
    }

    cout << "m: " << result_m << " b: " << result_b << endl;

    return result;
}

ld line(ld m, ld x, ld b)
{
    return m*x+b;
}

ld variance(vector<ld> data, ld m, ld b)
{
    ld result = 0.0;
    for (int i = 0; i < data.size(); i++)
    {
        result += pow(data[i] - line(m, i, b), 2) / data.size();
    }

    return result;
}