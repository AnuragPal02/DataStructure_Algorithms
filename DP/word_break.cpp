#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


bool solve(string str,set<string>&st,map<string,bool>&mp){
    if(st.find(str)!=st.end()){
        return true;
    }
    if(mp.find(str)!=mp.end()){
        return mp[str];
    }
    int n = str.size();
    for(int i=0;i<n;i++){
       string left = str.substr(0,i+1);
       if(st.find(left)!=st.end()){
           if(i+1 >= n) continue;
           string right = str.substr(i+1,n-(i+1));
           if(solve(right,st,mp)){
            return mp[str] = true;
           }
       }
    }
    return mp[str] = false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
         set<string>st;
         for(auto it:wordDict){
            st.insert(it);
         }
        map<string,bool> mp;
         return solve(s,st,mp);
    }
};