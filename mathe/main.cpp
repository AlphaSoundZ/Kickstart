#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    // read file
    ifstream file("C:\\Users\\janja\\Downloads\\mathe\\anotherdata12.dat");

    // check if file is open
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 0;
    }

    // read file
    int num;
    vector<float> nums;
    while (file >> num) {
        nums.push_back(num);
    }

    // close file
    file.close();

    // print out the numbers
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}