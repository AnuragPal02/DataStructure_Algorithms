
#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
         unordered_map<int,vector<int>> mp;
         
         for(int i=0;i<adj.size();i++){
             mp[i] = adj[i];
         }
         
         vector<bool> visited(adj.size()+1,false);
         vector<int> result;
         bfs(0,mp,visited,result);
         return result;
    }
    void bfs(int node,unordered_map<int,vector<int>> mp, vector<bool> &visited, vector<int> &result){
        
        queue<int> que;
        que.push(node);
        result.push_back(node);
        visited[node] = true;
        
        while(!que.empty()){
            int front_node = que.front();
            que.pop();
            
            for(auto it:mp[front_node]){
                if(!visited[it]){
                    que.push(it);
                    visited[it] = true;
                    result.push_back(it);
                }
            }
        }
    }