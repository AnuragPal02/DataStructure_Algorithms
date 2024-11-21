#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;cin>>n;
    vector<int> arrival,departure;
    while(n--){
        int x,y;
        cin>>x>>y;
        arrival.push_back(x);
        departure.push_back(y);
    }
    sort(begin(arrival),end(arrival));
    sort(begin(departure),end(departure));
    int i=0;
    int j=0;
    int max_count = 0;
    int temp_count = 0;
    while(i<arrival.size() && j<departure.size()){
        if(arrival[i] < departure[j]){
            temp_count += 1;
             max_count = max(max_count,temp_count);
            i++;
        }else{
            temp_count -= 1;
            j++;
        }
    }

    cout<<max_count<<endl;
}