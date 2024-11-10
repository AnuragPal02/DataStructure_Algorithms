#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&arr,int target,unordered_map<int,int>&visited){
     int l = 0;
     int h = arr.size()-1;
     int ans = -1;
     
     // here l <= h it is because we can find the ans at the high, who know's! we find better ans
     while(l<=h){
        int mid = l + (h-l)/2;
        if(arr[mid] <= target){
            ans = arr[mid];
            l = mid + 1;
        }else{
            h = mid - 1;
        }
     }
       while (ans != -1 && visited[ans] == 0) {
        // If this ans is not available, decrement ans and check again
        ans--;
    }

    // If ans is still valid and available, decrement its count
    if (ans != -1 && visited[ans] > 0) {
        visited[ans]--;
        return ans;
    }

    return -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arrn(n),arrm(m);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arrn[i];
        mp[arrn[i]]++;
    }
    for(int i=0;i<m;i++){
        cin>>arrm[i];
    }

    sort(arrn.begin(),arrn.end());
   
    for(int i=0;i<m;i++){
        int ans = binary_search(arrn, arrm[i],mp);
        cout<<ans<<endl;
    }
}

