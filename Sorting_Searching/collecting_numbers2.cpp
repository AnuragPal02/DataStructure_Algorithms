#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;cin>>n;
    vector<int> arr(n);
    unordered_multimap<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp.insert(arr[i],i);
    }

    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        
        mp.erase(arr[x]);
        mp.erase(arr[y]);

        mp.insert(arr[x],y);
        mp.insert(arr[y],x);

        int ans = solve(mp,arr);
        cout<<ans<<endl;
    }

}
int solve(unordered_multimap<int,int>&mp,vector<int>&arr){
     int round = 0;
     int n = arr.size();
     for(int i=0;i<n;i++){
        int x = arr[i];
        if(mp[x+1] > mp[x]) continue;
        else{
            round++;
        }
     }
}