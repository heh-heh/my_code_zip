#include <stdio.h>
#include <stdlib.h>

int main()
{
    double total=0, sum=0, a=0;
    int num=0;
    printf("������� �Է��ϼ��� : ");
    scanf("%d", &num);

    for(int i=0; i<num; i++){
            printf("%d ��° ���� : ",i+1);
            scanf("%lf", &a);
            sum+=a;

    }
    total=sum/num;
    printf("��� : %lf, ���� : %lf", total, sum);
    return 0;
}
