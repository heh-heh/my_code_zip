#include<stdio.h>
int main(void){
    int arr[10]={0};
    for(int i=0; i<10; i++){
        printf("%d 번째 배열 값 입력 : ",i);
        scanf("%d",&arr[i]);
    }
    printf("반대로 출력\n");
    for(int i=9; i>=0; i--)
        printf("%d ", arr[i]);
}