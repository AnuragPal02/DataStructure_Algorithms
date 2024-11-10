#include<stdio.h>
#include<math.h>


typedef struct{
     int type;// holding 0 for int and 1 for float;
     union // we can also nest union in the structure;
     {
         int i;
         float j;  /* data */
     }test;

     struct{
         int type;
        
     }secondstruct;
     
}mystruct;
void process(mystruct t){
     if(t.type == 0){
          printf("It is integer: %d",t.test.i);
     }else{
          printf("It is float: %d",t.test.j);
     }
}
#include <stdio.h>
int main()
{ 
     mystruct d = {0,.test.i = 9};
     mystruct e = {1,.test.j = 8.90};
     process(d);
    
}

