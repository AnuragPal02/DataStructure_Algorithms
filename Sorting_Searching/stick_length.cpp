#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){ //here we can't write signed int because we have declared int keyword as long long 
// but signed or signed int are doing the same work 

    int n;cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    sort(begin(arr),end(arr));
    
    int mid = n/2;
    int points = 0;
    for(int i=0;i<n;i++){
       points += abs(arr[mid]-arr[i]);

    }
    cout<<points<<endl;
}