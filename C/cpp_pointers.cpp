
#include <bits/stdc++.h>
using namespace std;

int main() {
  // These below both are smart pointers that there is not need to manually delete the memory it will auto
  // matically deleted when the variable goes outof scope or programm exits 
    // shared_ptr and unique_ptr
    shared_ptr<int> ptr1(new int(20));
    {
        shared_ptr<int> ptr2 = ptr1;
        cout<<"Reference count: "<< ptr2.use_count()<<endl;
    }
    cout<<*ptr1<<endl;
    cout<<"Reference count: "<<ptr1.use_count()<<endl;

    // using unique pointer 
    unique_ptr<int>ptr(new int(30));
    cout<<*ptr<<endl;

    

}