#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
     vector<int>arr;
    while(n--){
       int x;cin>>x;
       arr.push_back(x);
    }
    sort(begin(arr),end(arr));
    vector<int> flats;
    while(m--){
        int x;cin>>x;
        flats.push_back(x);
    }
    sort(begin(flats),end(flats));
//***********Passed all the test cases****************/
    int i=0;
    int j=0;
    int count = 0;
    while(i<arr.size() && j<flats.size()){
          int low_r = arr[i]-k;
          int high_r = arr[i]+k;
          if(flats[j] <= high_r && flats[j]>=low_r){
              count ++;
              i++;
              j++;
          }else if(high_r > flats[j]){
              j++;
          }else{
            i++;
          }
    }
   cout<<count<<endl;
}