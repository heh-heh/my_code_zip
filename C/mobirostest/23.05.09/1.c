#include <stdio.h>

int main(void){
    int a=0;
    double total;
    int arr[100]={0};
    printf("학생수 입력 : ");scanf("%d", &a);
    for(int i=0; i<a; i++){
        printf("%d 번째 학생의 점수 : ", i+1);
        scanf("%d", &arr[i]);total+=arr[i];
    }
    printf("학생들의 평균 점수 : %.2f",total/a);
}