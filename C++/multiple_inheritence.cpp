#include<iostream>
using namespace std;

class A
{
  int x;
public:
  void setX(int i) {x = i;}
  void print() { cout << x <<endl; }
};

class B: virtual public A
{
public:
  B()  { setX(10); }
};

class C: virtual public A  
{
public:
  C()  { setX(20); }
};

class D: public B, public C {
};

int main()
{
    D d;
    d.print();
    A a1;
    a1.setX(2);
   A a2;
   a2.print();
    return 0;
}