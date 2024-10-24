//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
       int n = adj.size();
       
       queue<int> que;
       vector<int> indegree(n);
       for(vector<int> &u:adj){
           for(int &v:u){
               indegree[v]++;
           }
       }
       
      for(int i=0;i<n;i++){
          if(indegree[i] == 0){
              que.push(i);
          }
      }
       
       // Now just perform the bfs
       vector<int> result;
       while(!que.empty()){
           int node = que.front();
           que.pop();
           result.push_back(node);
           for(int &v:adj[node]){
               indegree[v] = indegree[v] - 1;
               if(indegree[v] == 0){
                   que.push(v);
               }
           }
       }
       return result;
    }
    
};
