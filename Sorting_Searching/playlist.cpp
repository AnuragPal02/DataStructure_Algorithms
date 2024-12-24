#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<int> st;
    int maxlen = INT_MIN;
    int i=0,j=0;
    while(j<n){
      if(st.find(arr[j])!=st.end()){
         while(st.find(arr[j])!=st.end()){
            st.erase(arr[i]);
            i++;
         }
      }
      st.insert(arr[j]);
      maxlen = max(maxlen,j-i+1);
      j++;
    }
    cout<<maxlen<<endl;
}