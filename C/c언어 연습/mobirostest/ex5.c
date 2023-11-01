#include<stdio.h>
int main(void){
    int a=0;
    if(a==0) a=a+10;
    if(a>9) a=a+5;
    else if(a<5) a=a+1;
    if(a>15) a=a+3;

    printf("%d",a );
}