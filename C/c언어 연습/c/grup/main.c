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
        printf("��� ������� ���簡 �ǽǱ���?\n\n");
        getchar();

        int select = rand() % 5;
        printfCat(select);
        collection[select]=1;
        int CATSALL=checkCollect();

        if(CATSALL==1)
        {
             printf("\n\n�����մϴ� !��� ���δ��� ���˽��ϴ� �� ��� �ֽʽÿ�\n\n");

             exit;
        }

    }


    return 0;
}

void initCats()
{
    cats[0].name="������";
    cats[0].age=5;
    cats[0].character="�¼�";
    cats[0].level=2;

    cats[1].name="�ư���";
    cats[1].age=2;
    cats[1].character="õ������";
    cats[1].level=1;

    cats[2].name="�߳�";
    cats[2].age=3;
    cats[2].character="������";
    cats[2].level=2;

    cats[3].name="������";
    cats[3].age=1;
    cats[3].character="�ſ� ����";
    cats[3].level=4;

    cats[4].name="�εγ��� ";
    cats[4].age=7;
    cats[4].character="�����̽�";
    cats[4].level=7;
}

void printfCat(selectd)
{
    printf("\n\n=====����� ���δ��Դϴ� =====\n\n");
    printf("�̸�      :   %s\n",cats[selectd].name);
    printf("����      :   %d\n",cats[selectd].age);
    printf("����      :   %s\n",cats[selectd].character);
    printf("����      :   ");

    for(int i=0; i<cats[selectd].level; i++)
    {
        printf("*");
    }
    printf("\n\n");

}

int checkCollect(void)
{
    int collectAll=0;
    printf("\n\n===���� ��� ���δ��Դϴ�==\n\n");
    for(int i=0; i<5; i++)
    {
        if(collection[i]==0)
        {
            printf("%10s","(��ڽ�)");
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
                 printf("\n\n�����մϴ� !��� ���δ��� ���˽��ϴ� �� ��� �ֽʽÿ�\n\n");
                 break;
             }

        }



    }

    return collectAll;
}
