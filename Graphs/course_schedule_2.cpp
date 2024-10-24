
#include<bits/stdc++.h>
using namespace std;

// Using DFS method, it can be also done by bfs you have to consider the indegree 
// in that case 

// always remeber cycle detection in directed and in in directed always choose dfs 
// for topological questions choose bfs 
class Solution {
public:
    bool isCycle(int node, vector<bool>& visited, vector<bool>& inrecursion,
                 unordered_map<int, vector<int>>& adj, stack<int>& st) {
        visited[node] = true;
        inrecursion[node] = true;
        for (int& v : adj[node]) {
            if (!visited[v] && isCycle(v, visited, inrecursion, adj, st)) {
                return true;
            }
            if (inrecursion[v] == true) {
                return true;
            }
        }
        st.push(node);
        inrecursion[node] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        unordered_map<int, vector<int>> adj;
        for (auto& it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> inrecursion(numCourses, false);
        stack<int> st;
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && isCycle(i, visited, inrecursion, adj, st)) {
                f = false;
                break;
            }
        }
        vector<int> result;
        if (f) {
            while (!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
        }
        return result;
    }
};