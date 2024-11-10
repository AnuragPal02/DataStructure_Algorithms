
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> st;
        vector<int>arr;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
           while(!st.empty() && nums[st.top()] < nums[i]){
               st.pop();
           }
           if(!st.empty()) arr.push_back(st.top()-i);
           else arr.push_back(0);
           st.push(i);

        }
         reverse(arr.begin(),arr.end());
         return arr;
    }
};