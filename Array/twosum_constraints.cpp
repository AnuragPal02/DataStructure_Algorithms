//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
   void solve(vector<vector<int>> &results,vector<int> &nums, int target){
       int n = nums.size();
       unordered_map<int,int> mp;
       unordered_map<int,bool> visited;
       for(int i=0;i<n;i++){
           int e = target - nums[i];
           if(mp.find(target-nums[i])!=mp.end() && !visited[e]){
              visited[e] = true;
              visited[nums[i]] = true;
              results.push_back({min(e,nums[i]),max(e,nums[i])});
           }
           mp[nums[i]]++;
       }
      auto comp = [](vector<int>&a,vector<int>&b){
          if(a[0] < b[0])return true;
          else if(a[0]==b[0] && a[1] < b[1]) return true;
          else return false;
      };
      sort(results.begin(),results.end(),comp);
   }
    vector<vector<int>> distinctPairs(vector<int> &arr, int target) {
           vector<vector<int>> results;
           solve(results,arr,target);
           return results;
    }
};
