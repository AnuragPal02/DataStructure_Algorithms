#include<bits/stdc++.h>
#define int long long
using namespace std;
 
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // dfs method
    bool dfs_iscyclic(vector<bool>&visited,vector<bool>&recursion,vector<vector<int>>&adj,int node){
         visited[node] = true;
         recursion[node] = true;
         
         // explore the node 
         for(int &v:adj[node]){
             if(!visited[v]){
                 if(dfs_iscyclic(visited,recursion,adj,v)){
                     return true;
                 }
             }
             if(recursion[v] == true){
                 return true;
             }
         }
         recursion[node] = false;
         return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
          
          int n = adj.size();
          vector<bool> visited(n,false);
          vector<bool> recursion(n,false);
          
          for(int i=0;i<n;i++){
              if(!visited[i]){
                  if(dfs_iscyclic(visited,recursion,adj,i)){
                      return true;
                  }
              }
          }
          return false;
    }
};