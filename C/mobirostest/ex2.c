#include<stdio.h>
//숫자 입력 받고 받은 만큼 hello world 출력
int main(void){
    int a;
    printf("숫자 입력 하기 : ");scanf("%d",&a);
    for(int i=0; i<a; i++){printf("Hello World!!\n");}
}