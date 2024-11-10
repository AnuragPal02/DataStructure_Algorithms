
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   void solve(int &maxlen,vector<int>&arr,int n){
       int sum = 0;
       
       int i=0;
       int j=0;
       unordered_map<int,int>mp;
       mp[0] = -1;
       for(int i=0;i<n;i++){
           sum += arr[i];
           if(mp.find(sum)!=mp.end()){
               int u = i-mp[sum];
               maxlen = max(maxlen,u);
           }
           if(mp.find(sum) == mp.end()){
               mp.insert({sum,i});
           }
       }
   }
    int maxLen(vector<int>& arr, int n) {
        int maxlen = INT_MIN;
        solve(maxlen,arr,n);
        return maxlen==INT_MIN?0:maxlen;
    }
};
