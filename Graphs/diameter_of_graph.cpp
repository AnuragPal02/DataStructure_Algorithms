#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
   pair<int,int> bfs(unordered_map<int,vector<int>>&adj,int source){
          
          queue<int> que;
          que.push(source);
          unordered_map<int,bool> visited;
          visited[source] = true;
          int farthestnode = source;
          int distance = 0;
          while(!que.empty()){
             int n = que.size();
             while(n--){
                int curr_node = que.front();
                que.pop();

                farthestnode = curr_node;
                for(auto &it:adj[curr_node]){
                    if(visited[it] == false){
                        visited[it] = true;
                        que.push(it);
                    }
                }
             }
             if(!que.empty()){
                distance++;
             }
          }
          return {farthestnode,distance};
   }
   int findDiameter(unordered_map<int,vector<int>>&adj){
        // step-1 is to find the farthest node from any random node 
        auto[farthestnode, distance] = bfs(adj,0); // 0 is considered random node

        // step-2 is to find the farthest node from farthest_node;

        auto[OtherNodeEnd, diameter] = bfs(adj,farthestnode);
        return diameter;
   }
       unordered_map<int,vector<int>> buildadj(vector<vector<int>>& edges){
            unordered_map<int,vector<int>> adj;

            for(auto &it:edges){
                int u = it[0];
                int v = it[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            return adj;
       }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
         unordered_map<int,vector<int>> adj1 = buildadj(edges1);
          unordered_map<int,vector<int>> adj2 = buildadj(edges2);

          int d1 = findDiameter(adj1);
          int d2 = findDiameter(adj2);

          int combined = (d1+1)/2 + (d2+1)/2 + 1;

          return max({d1,d2,combined});

    }
};