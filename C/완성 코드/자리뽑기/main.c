
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


int main()
{
    int uer = 0;//�ִ��ο�
    int j=1;//�ѿ��� �ɴ� ��
    int random[40]={0};//�ڸ�or�ߺ�ó����

    while(1)
    {
        printf("�ִ� �ο� �Է� : ");

        if(0==scanf_s("%d",&uer)||uer<1)
        {
            printf("\n============================\n");
            printf("1�̻� Ȥ�� ���ڸ� �����մϴ�\n�ٽ� �Է����ּ���\n");
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
        printf("�ִ� �ο� : %d\n", uer);
        printf("�ѿ��� ���� ��� : ");
        if(0==scanf_s("%d",&j)||j<1)
        {
            printf("\n============================\n");
            printf("1�̻� Ȥ�� ���ڸ� �����մϴ�\n�ٽ� �Է����ּ���\n");
            printf("============================\n\n");
            sleep(3);
            system(" cls ");
            rewind(stdin);
        }
        else break;
    }

    srand(time(NULL));
    for(int i=0; i<uer; i++)//�ߺ� ���� ���� ������
    {

        random[i] = rand()%uer+1;
        for(int j=0; j<i; j++)
        {
            if(random[j]==random[i])//�ߺ�ó��
            {
                i--;
                break;
            }
        }
    }
    system(" cls ");
    printf("=========��� �Ϸ� �ڸ� ��÷ ���� =========\n\n");getchar();

    for(int i=0; i<uer; i++)
    {
        getchar();
        printf("%d ��° ����� �ڸ� : %d\n",i+1,random[i]);

    }
    getchar();
    system(" cls ");
    printf("\n\n=========���� ��� =========\n\n");getchar();


    for(int i=0; i<uer; i++)
    {
        printf("%2d:%2d ",i+1, random[i]);
        if((i+1)%j==0)printf("\n\n");
    }
    getchar(); getchar();
}
