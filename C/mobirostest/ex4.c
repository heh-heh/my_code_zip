#include<stdio.h>
int main(void){
    int a=scanf("%d",&a);
    for(int i=0; i<a; i++){
        if(i%2==0)printf("%d\n",i);
    }
}