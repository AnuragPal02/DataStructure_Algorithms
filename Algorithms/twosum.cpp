#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int found = 0;
    for(int i=0;i<n;i++){
        int target = m - arr[i];
        if(mp.find(target)!=mp.end() && target != arr[i] ){
            found = 1;
            cout<<mp[target]<<" "<<arr[i];
            break;
        }
        mp[arr[i]] = i;
    }
    if(found == 0)cout<<-1<<endl;
}