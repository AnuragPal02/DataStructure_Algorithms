
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    
    
    bool dfs_cycle(int node,int parent,vector<bool>&visited,vector<vector<int>> &adj){
        
       visited[node] = true;
       for(int &v : adj[node]){
           if(v == parent) continue;
           if(visited[v]) return true;
           if(dfs_cycle(v,node,visited,adj)) return true;
       }
       return false;
    }
    bool isCycle(vector<vector<int>> adj) {
        int n = adj.size();
        vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i] && dfs_cycle(i,-1,visited,adj)){
                return true;
            }
        }
        return false;
    }
};