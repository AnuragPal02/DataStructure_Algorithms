#include<stdio.h>


int add(int a,int b){
    return a+b;
}
void subtract(int a,int b){
    printf("%d",b-a);
}

void solve(void (*operation)(int,int),int a,int b){
      operation(a,b);
}
int main(){
    void (*operation)(int,int);
    
    
    operation = subtract;
    
    solve(operation,8,3);
}
