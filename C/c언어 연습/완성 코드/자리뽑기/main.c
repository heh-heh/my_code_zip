
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


int main()
{
    int uer = 0;//최대인원
    int j=1;//한열에 앉는 수
    int random[40]={0};//자리or중복처리용

    while(1)
    {
        printf("최대 인원 입력 : ");

        if(0==scanf_s("%d",&uer)||uer<1)
        {
            printf("\n============================\n");
            printf("1이상 혹은 숫자만 가능합니다\n다시 입력해주세요\n");
            printf("============================\n\n");
            sleep(3);
            system(" cls ");
            rewind(stdin);
        }
        else break;
    }
    printf("\n\n");
    system(" cls ");
    while(1)
    {
        printf("최대 인원 : %d\n", uer);
        printf("한열에 앉을 명수 : ");
        if(0==scanf_s("%d",&j)||j<1)
        {
            printf("\n============================\n");
            printf("1이상 혹은 숫자만 가능합니다\n다시 입력해주세요\n");
            printf("============================\n\n");
            sleep(3);
            system(" cls ");
            rewind(stdin);
        }
        else break;
    }

    srand(time(NULL));
    for(int i=0; i<uer; i++)//중복 없는 난수 생성기
    {

        random[i] = rand()%uer+1;
        for(int j=0; j<i; j++)
        {
            if(random[j]==random[i])//중복처리
            {
                i--;
                break;
            }
        }
    }
    system(" cls ");
    printf("=========계산 완료 자리 추첨 시작 =========\n\n");getchar();

    for(int i=0; i<uer; i++)
    {
        getchar();
        printf("%d 번째 사람의 자리 : %d\n",i+1,random[i]);

    }
    getchar();
    system(" cls ");
    printf("\n\n=========최종 결과 =========\n\n");getchar();


    for(int i=0; i<uer; i++)
    {
        printf("%2d:%2d ",i+1, random[i]);
        if((i+1)%j==0)printf("\n\n");
    }
    getchar(); getchar();
}
