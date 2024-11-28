#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the number n:");
    scanf("%d",&n);
    printf("Allocating the memory to the array...");
    int *arr = (int*)calloc(10,sizeof(int));
    printf("Allocation completed!");
    int *ptr = arr;
   
   // allocation of memory through the pointers 
    for(int i=0;i<n;i++){
        scanf("%d",&*(ptr+i)); // you can see that arr[i] = *(arr+i) = i[arr];
    }
    // accessing through the original pointer 
    for(int i=0;i<n;i++){
        printf("%d",*(arr+i));
    }
}