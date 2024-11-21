#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    sort(begin(arr),end(arr));
    int x = 1;
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            break;
        }
        x += arr[i];
    }
    cout<<x<<endl;
}