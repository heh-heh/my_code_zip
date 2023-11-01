#include <stdio.h>
int main(void){
    int b=0,a=0;
    scanf("%d",&a);
    for(int i=100; i>=0; i/=10){
        if(i==0)break;b=a%i;
        if((a/i)%2==1)printf("%d 는 홀수 입니다",a/i);
        else printf("%d 는 짝수 입니다",a/i);
        printf("\n");
        a=b;
    }
}