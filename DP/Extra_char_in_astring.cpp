#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int  solve(string str,set<string>&st,unordered_map<string,int>&mp){
        if(st.find(str)!=st.end()){
            return 0;
        }
        if(mp.find(str)!=mp.end()){
            return mp[str];
        }
        long long ans = INT_MAX;
        int n = str.size();
        for(int i=0;i<str.length();i++){
            string left = str.substr(0,i+1);
            string right = str.substr(i+1);
            
            if(st.find(left)!=st.end()){
               long long res = solve(right,st,mp);
               ans = min(ans,res);
            }else{
               long long res = left.size() + solve(right,st,mp);
               ans = min(ans,res);
            }
        }
     return mp[str] = (ans == INT_MAX ? str.size() : ans);
     }
    int minExtraChar(string s, vector<string>& dictionary) {
         set<string> st(dictionary.begin(),dictionary.end());
         unordered_map<string,int> mp;
         return solve(s,st,mp);
    }
};