#include<bits/stdc++.h>
using namespace std;

class parent{
   public:
     parent(){
        cout<<"Parent class constructor!"<<endl;
     }
     void method(){
        cout<<"This is parent method"<<endl;
     }
};

class child:public parent{
  public:
     child(){
        cout<<"child class constructor!"<<endl;
     }  
     
     void method(){
        cout<<"This is child class method!"<<endl;
     }
};
void calls_parent_method(parent &p){
    p.method();
}
void calls_child_method(child &c){
    c.method();
}
int main(){
    parent t;
    child c;
    calls_child_method(c);
    calls_parent_method(c);
}