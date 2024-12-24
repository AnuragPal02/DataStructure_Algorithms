#include<stdio.h>
#include<conio.h>

int main(){
    FILE *file = fopen("example.txt","r");
    if(file){
        int ch = getc(file);
        printf("getc():%c\n",ch);
        fclose(file);
    }

    printf("Enter characters:\n");
    int getchari = getchar();
    printf("getchar():%c\n",getchari);

    printf("Enter character for getch:\n");
    int getchi = getch();
    // printf("getch():%c\n",getchi);

    printf("Enter character for getche:\n");
    int getchei = getche();
    

}