#include<bits/stdc++.h>
using namespace std;

int main(){
    // this is just kadane's algorithm 
    // this is for every index, you will check which subarray ending with that index have maximum sum

    int n;cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
     long long temp = 0;
     long long maxsum = LLONG_MIN;
     for(int i=0;i<n;i++){
        long long curr = arr[i];
        temp = max(curr+temp,curr); 
        maxsum = max(temp,maxsum);
     }
    cout<<maxsum<<endl;
}