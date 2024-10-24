
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        int n = numCourses;

        unordered_map<int,vector<int>> adj;

        for(int i=0;i<arr.size();i++){
            int first = arr[i][0];
            int second = arr[i][1];
            adj[second].push_back(first);
        }
        vector<int> result;
        
        vector<int> indegree(n);
        
        // iterating in map
        for(auto it:adj){
            int key = it.first;
            vector<int> value = it.second;
            for(int node:value){
                indegree[node]++;
            }
        }
        queue<int> que;
        
        // pushing all the 0 indegree nodes

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int node = que.front();
            que.pop();
            result.push_back(node);
            for(int &v:adj[node]){
                  indegree[v]--;
                  if(indegree[v] == 0) que.push(v);
            }
        }
        if(result.size() != n)return false;
        return true;
    }
};