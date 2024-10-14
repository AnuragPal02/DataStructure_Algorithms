//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
              sort(arr,arr+n);
              int res = INT_MAX;
              for(int i=0;i<n;i++){
                  int l = i+1;
                  int r = n-1;
                  while(l<=r){
                      int mid = l + (r-l)/2;
                      int x = arr[mid];
                      int y = arr[i];
                      int z = x + y;
                      if(z == 0){
                          return 0;
                      }
                      // Here take example of -1 and 1 the ans should be 1 as per given question
                      if(abs(z) < abs(res) || (abs(z) == abs(res)) && z > res){
                          res = z;
                      }
                      if(z > 0){
                          r = mid - 1;
                      }else{
                          l = mid + 1;
                      }
                  }
                  
                  
              }
              return res;
        }
};
