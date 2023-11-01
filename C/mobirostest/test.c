#include <stdio.h>

void sum(int a){
    a=a+30;
}
int main(void){
    int a=10;
    sum(a);
    printf("%#d",a);
}