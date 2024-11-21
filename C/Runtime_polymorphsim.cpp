#include<bits/stdc++.h>
using namespace std;

class parent{
  public:
    parent(){
        cout<<"parent object is created and this is parent constructor called!"<<endl;
    }
     virtual void display(){
        cout<<"this is parent class display"<<endl;
    }
};

class child1:public parent{
    public:
    child1(){
        cout<<"This is child1 constructor!"<<endl;
    }
    void display(){
        cout<<"This is the child1 display"<<endl;
    }
    void show(){
        cout<<"This is show of child1:"<<endl;
    }
};

int main(){
    child1 obj;
    obj.display();
    parent ob;
    ob.display();
    parent *ptr = new child1();
    ptr->display();
}