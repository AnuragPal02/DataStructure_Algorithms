#include<bits/stdc++.h>
using namespace std;

class parent{
   public:
   int real;
   int imaginary;
       parent(int real,int imaginary): real(real), imaginary(imaginary){};
       parent operator + (parent& obj){
          return parent(real - obj.real,imaginary - obj.imaginary);
       }
       void display(){
        cout<<real<<" + i"<<imaginary<<endl;
       }
};

int main(){
    parent obj(5,4);
    parent obj2 (4,6);
    parent obj3 = obj + obj2;
    obj3.display();
}