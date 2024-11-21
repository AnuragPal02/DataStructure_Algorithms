#include<bits/stdc++.h>
using namespace std;

int findfibo(int pos,vector<int>&arr){

     if(pos == 0){
        return 0;
     }
     if(pos == 1){
        return 1;
     }
     return arr[pos] = findfibo(pos-1,arr)+findfibo(pos-2,arr);
}

int main(){
    int n;cin>>n;
    vector<int>arr(n+1);
    cout<<findfibo(n,arr)<<endl;
    for(auto it:arr){
        cout<<it<<" ";
    }
}