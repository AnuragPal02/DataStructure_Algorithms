#include<bits/stdc++.h>
using namespace std;

// design of stack using template concepts 
template <typename t>

class sstack{
    public:
      vector<t> arr;
      void push(t a){
         arr.push_back(a);
      }
      void pop(){
         if(!arr.empty()){
            arr.pop_back();
         }
      }
      
      t top(){
          return arr.back();
      }

      bool isempty(){
         return arr.empty();
      }
};

int main(){
    sstack<int> st;
    st.push(1);
    st.push(2);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.isempty()<<endl;
}