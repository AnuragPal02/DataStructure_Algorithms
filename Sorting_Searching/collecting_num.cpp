#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;cin>>n;
    vector<int>arr;
     unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
        mp[x] = i;
    }

    int round=1;
    for(int i=1;i<n;i++){
        // the current element is collected 
        int x = i;
        // decision whether go for another round or we can find the next element after this
        if(mp[x+1] > mp[x]){
            continue;
        }else{ // round++ kyuki it can't be found after this because it is located at index which is in back to track 
        // we have to go back and traverse again 
            round++;
        }
    }
   cout<<round<<endl;
}