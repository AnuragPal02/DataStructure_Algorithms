#include<bits/stdc++.h>
using namespace std;

class parent{
    private:
    int y;
    protected:
    int z;
    public:
    int x;
    parent(int val) : y(val){};
    parent(int val) : x(val) {};

    void show(int x){
        cout<<x<<endl;
    }
    void display(){};
};

class child:public parent{
   private:
   int x;
   protected:
   int z;
   public:
    
    void display(){
        cout<<"child class display"<<endl;
    }
    void show(int x){
        cout<<x<<endl;
    }
};

int main(){
    parent obj(7);
    cout<<obj.x<<endl;
}