#include<stdio.h>
typedef int integer;

void function(int a,int b){
    printf("%d",a+b);
}
const int solve(const int a, const int b){
    return a+b;
}
int main(){
    const int b = 2;
    printf("%d ",solve(1,5));
    printf("%d ",solve(4,3));
    printf("%d ",b*3);
    printf("%d ",b);
}

