#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> mp;
   string s,t;
   getline(cin,s);
   getline(cin,t);

   stringstream ss(t);
   string temp;
   while(ss>>temp){
     mp[temp]++;
   }

    stringstream z(s);
    string u;
    while(z>>u){
        if(mp.find(u)!=mp.end()){
            if(mp[u]>1){
                cout<<u<<" ";
                mp[u]--;
            }
        }else {
            cout<<u<<" ";
        }
    }
}