#include<stdio.h>

void solve(void (*function)(int,int),int a,int b){
    printf("%d ",function(a,b));
}
int product(int a,int b){
    return a*b;
}

int main(){
    int (*function)(int,int);
    function = product;
    solve(function,1,3);
}