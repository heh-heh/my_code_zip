#include <stdio.h>

int main(void){
    int a=1;
    int count=0;
    int arr[10]={0};

    while(a!=0){
        scanf("%d", &a);
        arr[a]++;count++;
    }
    int b=0;
    printf("확인 하고 싶은 수 : "); scanf("%d", &b);
    printf("%d 가 입력 받은 횟수 : %d",b,arr[b]);

}