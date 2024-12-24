#include<stdio.h>

void operation(int a,int b){
    printf("%d ",a+b);
}
int main(){
    void (*pointer)(int,int);
    pointer = operation;
    solve(pointer,2,3);
}
