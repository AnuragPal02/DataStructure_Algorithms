#include<bits/stdc++.h>
using namespace std;

void dfs_sort(vector<vector<int>> &adj,vector<bool> &visited,int node,stack<int>&st){
         // first you visit the node so visited[node] = true;
         visited[node] = true;
         // next you explore every connection of it
         for(int &v:adj[node]){
             // you will only go if it is not visited
             if(!visited[v]){
                 dfs_sort(adj,visited,v,st);
             }
         }
         // finally you push the parent or first node from which 
         // others originate 
         st.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        vector<bool>visited(adj.size(),false);
        vector<int> result;
        stack<int> st;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                dfs_sort(adj,visited,i,st);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }