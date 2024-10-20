#include<bits/stdc++.h>
using namespace std;

class base{
    private:
    int x;
    protected:
    int y;
    public:
    base(int x,int y){
        this.x = x;
        this.y = y;
       cout<<"This is base class constructor"<<endl;
    }
     void show(){
        cout<<"base class"<<endl;
     }
};
class derived:public base{
    public:
    derived(){
        cout<<"This is derived constructor"<<endl;
    }
    void show(){
        cout<<"derived class"<<endl;
    }
};

int main(){
    base *p = new derived();
    p->show();
    
    derived obj;
    obj.show();
}