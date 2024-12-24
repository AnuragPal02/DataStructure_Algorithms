#include <bits/stdc++.h>
using namespace std;

int main() {
    string inputString;
    cin >> inputString;
    int length = inputString.length(), totalCost = 0;
    vector<int> costs(length);
    
    for (int i = 0; i < length; ++i) {
        cin >> costs[i];
    }
    
    int lastCharValue = inputString[0] - '0'; // Convert char to int
    int lastValueCost = costs[0];

    for (int i = 1; i < length; ++i) {
        if (inputString[i] - '0' != lastCharValue) {
            lastCharValue = inputString[i] - '0';
            lastValueCost = costs[i];
        } else {
            totalCost += min(lastValueCost, costs[i]);
            lastValueCost = max(lastValueCost, costs[i]);
        }
    }

    cout << totalCost;
    return 0;
}