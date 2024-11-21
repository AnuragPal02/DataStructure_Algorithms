#include<bits/stdc++.h>
using namespace std;

void primeupto_n(int n){

    vector<int>temp(n+1,1);
    temp[0] = temp[1] = 0;
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i){
            if(temp[j]==0)continue;
            if(temp[j]!=0){
                temp[j] = 0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(temp[i]==1){
            cout<<i<<" ";
        }
    }
}
int main(){
    int n;cin>>n;
    primeupto_n(n);

}