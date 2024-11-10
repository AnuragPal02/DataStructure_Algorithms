#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr;
    while(n--){
        int c;cin>>c;
        arr.push_back(c);
    }
    sort(arr.begin(),arr.end());
    
    int l = 0;
    int h = arr.size()-1;
    int ans = 0;
    while(l<=h){
        if(arr[l]+arr[h] <= x){
             l++;
             h--;
             ans++;
        }else{
            ans++;
            h--;
        }
    }
    cout<<ans<<endl;
}