#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;cin>>n;
    vector<pair<int,int>> arr;
    while(n--){
        int x,y;
        cin>>x>>y;
        arr.push_back({x,y});
    }
    auto comp = [](pair<int,int>&a,pair<int,int>&b){
        return a.second < b.second;
    };
    sort(begin(arr),end(arr),comp);
    int previous_end_time = 0;
    int count = 0;
    for(int i=0;i<arr.size();i++){
        int start_time = arr[i].first;
        int end_time = arr[i].second;
        
        if(start_time >= previous_end_time){
            // if start time is greater than previous then only we can pick the movie else not becuase
            // it may clash with the current one 
            count++;
            previous_end_time = end_time;
        }
    }
    cout<<count<<endl;
}