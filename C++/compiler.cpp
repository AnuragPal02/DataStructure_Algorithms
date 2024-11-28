#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(begin(arr),end(arr));
    int prev = 0;
    unordered_map<int,int>mp;
    int sum = 0;
    vector<int> temp;
    for(int i=0;i<arr.size();i++){
        if(mp.find(arr[i])!=mp.end()){
            sum += prev + 1;
            prev = prev + 1;
        }else{
            sum += arr[i];
            prev = arr[i];
        }
         mp[prev]++;
        temp.push_back(prev);
    }
     for(auto it:temp){
        cout<<it<<" ";
     }
     cout<<endl;
     cout<<sum<<endl;
}