#include<bits/stdc++.h>
using namespace std;

// Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
      unordered_map <int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]] = i;
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int key = x - (arr[i]+arr[j]);
            if(mp.find(key)!=mp.end()){
                if(mp[key]!= i && mp[key]!=j){
                    return 1;
                }
            }
        }
    }
    return 0;
    }