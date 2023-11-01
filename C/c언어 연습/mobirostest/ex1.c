#include<stdio.h>
int main(void){
    int a,b;
    printf("숫자 두개 입력 : ");
    scanf("%d %d", &a,&b);
    printf("%d + %d = %d\n", a,b,a+b);
    printf("%d - %d = %d\n", a,b,a-b);
    printf("%d * %d = %d\n", a,b,a*b);
    printf("%d / %d = %d\n", a,b,a/b);
    
}