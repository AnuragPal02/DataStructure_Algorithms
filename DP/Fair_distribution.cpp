
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
void solve(vector<int>&arr,int index,vector<int>&temp,int &ans){
    if(index>=arr.size()){
        ans = min(ans,*max_element(begin(temp),end(temp)));
        return;
    }
    for(int i=0;i<temp.size();i++){
         temp[i] += arr[index];
         solve(arr,index+1,temp,ans);
         temp[i] -= arr[index];
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
         vector<int>temp(k,0);
         int ans = INT_MAX;
         solve(cookies,0,temp,ans);
         return ans;
    }
};