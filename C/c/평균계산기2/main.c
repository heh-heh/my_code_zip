#include <stdio.h>
#include <stdlib.h>

int main()
{
    double total=0, sum=0, a=0;
    int num=0;
    printf("과목수를 입력하세요 : ");
    scanf("%d", &num);

    for(int i=0; i<num; i++){
            printf("%d 번째 과목 : ",i+1);
            scanf("%lf", &a);
            sum+=a;

    }
    total=sum/num;
    printf("평균 : %lf, 총점 : %lf", total, sum);
    return 0;
}
