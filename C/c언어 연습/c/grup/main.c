#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    char * name;
    int age;
    char * character;
    int level;

} CAT;
void printfCat(select);
void initCats();
int checkCollect(void);

int collection[5]={0};

CAT cats[5];

int main()
{
    srand(time(NULL));

    initCats();
    while(1)
    {
        printf("어느 고양이의 집사가 되실까요요?\n\n");
        getchar();

        int select = rand() % 5;
        printfCat(select);
        collection[select]=1;
        int CATSALL=checkCollect();

        if(CATSALL==1)
        {
             printf("\n\n축하합니다 !모든 주인님이 오셧습니다 잘 모셔 주십시오\n\n");

             exit;
        }

    }


    return 0;
}

void initCats()
{
    cats[0].name="깜냥이";
    cats[0].age=5;
    cats[0].character="온순";
    cats[0].level=2;

    cats[1].name="아갱이";
    cats[1].age=2;
    cats[1].character="천진난만";
    cats[1].level=1;

    cats[2].name="견냥";
    cats[2].age=3;
    cats[2].character="도도함";
    cats[2].level=2;

    cats[3].name="꼬깜냥";
    cats[3].age=1;
    cats[3].character="매우 착함";
    cats[3].level=4;

    cats[4].name="왁두냥이 ";
    cats[4].age=7;
    cats[4].character="고집이쌤";
    cats[4].level=7;
}

void printfCat(selectd)
{
    printf("\n\n=====당신의 주인님입니다 =====\n\n");
    printf("이름      :   %s\n",cats[selectd].name);
    printf("나이      :   %d\n",cats[selectd].age);
    printf("성격      :   %s\n",cats[selectd].character);
    printf("레벨      :   ");

    for(int i=0; i<cats[selectd].level; i++)
    {
        printf("*");
    }
    printf("\n\n");

}

int checkCollect(void)
{
    int collectAll=0;
    printf("\n\n===현재 계신 주인닙입니다==\n\n");
    for(int i=0; i<5; i++)
    {
        if(collection[i]==0)
        {
            printf("%10s","(빈박스)");
            collectAll=0;
        }
        else
        {
            printf("%10s", cats[i].name);
        }
    }
    printf("\n=========================\n\n");
    while(1)
    {
        int i=0,j=0;
        if(collection[i]==0)
            break;
        else if(collection[i]==1)
        {
             j++;
             if(j>5)
             {
                 collectAll=1;
                 printf("\n\n축하합니다 !모든 주인님이 오셧습니다 잘 모셔 주십시오\n\n");
                 break;
             }

        }



    }

    return collectAll;
}
