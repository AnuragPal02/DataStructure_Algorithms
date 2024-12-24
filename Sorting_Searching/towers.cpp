#include <bits/stdc++.h>
using namespace std;

int upperbound(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            right = mid; // We want the first element greater than target
        } else {
            left = mid + 1;
        }
    }
    return left; // This will be the index of the first element greater than target
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dynamic_arr;
    for (int i = 0; i < n; i++) {
        int it = upperbound(dynamic_arr, arr[i]);
        if (it == dynamic_arr.size()) {
            dynamic_arr.push_back(arr[i]); // If nothing found greater than that then new tower
        } else {
            dynamic_arr[it] = arr[i]; // If found just put the current element on top
        }
    }
    
    cout << dynamic_arr.size() << endl;
}