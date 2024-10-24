
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// BFS method
    void bfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        queue<int> que;
        que.push(node);
        visited[node] = true;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            
            for(int &v:adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
         int count = 0;
         int n = isConnected.size();
         vector<bool> visited(n,false);
         
         // extract from matrix
         unordered_map<int,vector<int>> adj;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
         }
         
         for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                bfs(i,adj,visited);
            }
         }
         return count;
    }
};


// dfs method
class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        visited[node] = true;
        for(int &v:adj[node]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int count = 0;
         int n = isConnected.size();
         vector<bool> visited(n,false);
         
         // extract from matrix
         unordered_map<int,vector<int>> adj;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
         }
         
         for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
         }
         return count;
    }
};