#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int a;
long long int meney=100000;

void Janken();
void coin();
void Baskin();
void roulette();
void seullosmeosin();//�̿�
void wabawe();
void updwon();

void maininit();
void gambling();

int main()
{
    maininit();


}
/*
void menuw()
{
    a=0;
    system( "cls" );
    printf("\n\n=========================================================\n\n");
    printf("�⺻ �޴� â �Դϴ�\n ");
    printf("���� ���� �� ���� ���÷��� 1 \n �̴� ���� �� �Ͻ÷��� 2 \n�� �Է� ���ּ���");
    printf("\n\n=========================================================\n\n");
    scanf("%d",&a);
    if(a==1)
    {

        printf("\n\n============================================\n\n");
        printf("���� ���� ��  ���� �̵� �Դϴ�\n ���� ���� ���� �ʰ� ���� ���ּ���");
        printf("\n\n============================================\n\n");
        sleep(2);
        gambling();

    }

    else if(a==2)
    {

         printf("\n\n============================================\n\n");
         printf("�̴� ������ �̵� �մϴ�\n�����ϰԸ� ��� �ּ���\n");
         printf("\n\n============================================\n\n");
         sleep(2);
         maininit();
    }


}
*/
void maininit()
{
    system( "cls" );
    a=0;
    printf("\n\n=========================================================\n\n");
    printf("���� �̴ϰ���\n\n");
    printf("���� �̿��� ���� �Է��ϸ�\n������ ������ ���� ������\n");
    printf("1 : ����������\n2 : ���� �յ� ���߱�\n3 : ����Ų��� 31\n4 : ���þȷ귿\n5 : ���ٿ� ����\n6 : �ű�\n0 : ����");
    printf("\n���ڸ� �Է��ϼ���\n");
    scanf("%d", &a);
    printf("\n\n=========================================================\n\n");
    if(a==1)
    {
        printf("���������� ������ ���� �մϴ�\n");
        sleep(1);
        Janken();

    }

    else if(a==2)
    {
        printf("���� �յ� ���߱� ������ ���� �մϴ�\n");
        sleep(1);
        coin();
    }

    else if(a==3)
    {
        printf("����Ų ��� 31 ������ ���� �մϴ�");
        sleep(1);
         Baskin();
    }

    else if(a==4)
    {
        printf("���þ� �귿 ������ ���� �մϴ�\n");
        sleep(1);
         roulette();
    }
    else if(a==5)
    {
        printf("���ٿ� ������ ���� �մϴ�\n");
        sleep(1);
        updwon();
    }
    else if(a==6)
    {
        printf("�ű� ������ �����Դϴ�");
        sleep(1);
        wabawe();

    }
    else if(a==0)
    {
        printf("������ �����Դϴ�");
        sleep(1);
        return 0;
    }


    return 0;
}
/*
void gambling()
{
    system( "cls" );
    a=0;
    printf("\n\n============================================\n\n");
    printf("���� ���� �濡 ���Ű��� ȯ���Դϴ�\n");
    printf("���� ������ �� %d �Դϴ�\n",meney);
    printf("������ ������ �� ������ ���� ���� �ּ���\n");
    printf("\n\n============================================\n\n");
    printf("�ϰ� ���� ������ ���ڸ� �Է��ϼ���\n");
    printf("1:�ž��� ���� ã��\n0:���� �޴�\n");
    scanf("%d", &a);
    if(a==1)
    {
         printf("\n\n============================================\n\n");
        printf("��.���� �̵� �մϴ�");
        printf("\n\n============================================\n\n");
        sleep(2);
        wabawe();
    }
    else if(a==0)
    {
         printf("\n\n============================================\n\n");
         printf("���� �޴��� �̵��մϴ�");
          printf("\n\n============================================\n\n");
            sleep(2);
            menuw();
    }
}
*/
void coin()//���� ���߱�
{
    int usr=0;
    int coin=0;
    int lost=0;
    int win=0;
    srand(time(NULL));

    system( "cls" );
    while(1)
    {

        coin=rand()%2+1;
        printf("\n\n============================================\n\n");
        printf("����� �����ϴ� ����� ��������(1:�� 2:��,0 �Է½� ����)");
        scanf("%d", &usr);
        printf("\n\n============================================\n\n");
        if(usr==0)
            break;
        if(usr==1&&coin==2)
        {
            printf("\n\n============================================\n\n");
            printf("����� ���Դϴ�\n");
            printf("�����ϴ�");
            printf("\n\n============================================\n\n");
            lost++;
        }
        else if(usr==2&&coin==1)
        {
            printf("\n\n============================================\n\n");
            printf("����� ���Դϴ�\n");
            printf("�����ϴ�");
            printf("\n\n============================================\n\n");
            lost++;
        }
        else if(usr==coin)
        {
            printf("\n\n============================================\n\n");
            printf("����� �̰���ϴ�");
            printf("\n\n============================================\n\n");
            win++;
        }
        else
        {
            printf("\n\n============================================\n\n");
            printf("�߸� �Է� �߽��ϴ�\n�ٽ� �Է����ּ���");
            printf("\n\n============================================\n\n");
        }

    }
    system( "cls" );
    printf("\n\n============================================\n\n");
    printf("����� �̱� Ƚ�� %d\n", win);
    printf("����� �� Ƚ�� %d\n", lost);
    printf("\n\n�̴� ���� ������ ���ư��ϴ�");
    printf("\n\n============================================\n\n");
    sleep(1);
    maininit();

}

void Janken()//���������� �Լ�
{
    int a=0;
    int test=0;
    int lost=0;
    int win=0;
    srand(time(NULL));
    system( "cls" );
    while(1)
    {

        a=rand()%3+1;
        printf("\n\n============================================\n\n");
        printf("����������(1:����,2:����, 3:��,0:��������)");
        scanf("%d", &test);
        printf("\n\n============================================\n\n");
        if(a==test)
        {

            printf("\n\n============================================\n\n");
            printf("���� : %d\n�� : %d\n", a,test);
            printf("�����ϴ�\n");
            printf("\n\n============================================\n\n");
            lost++;
        }
        else if((a==1&test==3)||(a==2&&test==1)||(test==2&&a==3))
        {

            printf("\n\n============================================\n\n");
            printf("���� : %d\n�� : %d\n", a,test);
            printf("�����ϴ�\n");
            printf("\n\n============================================\n\n");
            lost++;
        }
        else if(test>3)
        {

            printf("\n\n============================================\n\n");
            printf("�߸� �Է��߽��ϴ� �ٽ� �Է� ���ּ���\n");
            printf("\n\n============================================\n\n");
        }
        else
        {

            printf("\n\n============================================\n\n");
            printf("���� : %d\n�� : %d\n", a,test);
            printf("�̰���ϴ�\n");
            printf("\n\n============================================\n\n");
            win++;

        }
        if(test==0)
            break;


    }
    system( "cls" );
    printf("\n\n============================================\n\n");
    printf("�̱�Ƚ�� %d\n", win);
    printf("�� Ƚ�� : %d", lost);
    printf("\n\n�̴� ���� �� ���� ���� ���ϴ�");
    printf("\n\n============================================\n\n");
    sleep(1);
    maininit();
}


void Baskin()//����Ų���31
{
    int plar1=0;
    int pleat2=0;
    int numberBas=0;
    int b;
    int a;
    int c=0;
    while(1)
    {
        system( "cls" );
        printf("\n\n============================================\n\n");
        printf("����Ų��� 31 ���� �Դϴ�\n �ѹ��� 1~3��° �� ������ �Է� �����մϴ�\n");
        printf("�ѹ��� �� ���ڸ� �Է� ���� �մϴ�\n");
        printf("�÷��̾� ��(2�̻�)�� �Է����ּ��� : ");
        scanf("%d",&b);
        printf("\n\n============================================\n\n");
        if(b<2)
        {

            printf("�÷��̾� ���� �ʹ� �����ϴ�\n�ٽ� �Է����ּ���");
            continue;
        }
        else
            break;
    }

    while(1)
    {
        for(int i=1;i<=b; i++)
        {
            if(numberBas==31)
            {
                system( "cls" );
                printf("\n\n============================================\n\n");
                printf("�÷��̾� %d �������ϴ�", i==1?2:1);
                printf("\n\n============================================\n\n");
                break;
            }

            printf("\n\n============================================\n\n");
            printf("�÷��̾� %d ���� �θ��� ���ڸ� �Է����ּ���\n",i);
            printf("���� ���ڴ� %d �Դϴ�\n", numberBas);
            scanf("%d",&a);
            printf("\n\n============================================\n\n");
            if(a>numberBas+3)
            {
                printf("���ڰ� �ʹ� Ů�ϴ�\n�ٽ� �Է��� �ּ���\n");
                printf("\n\n============================================\n\n");
                i--;
                continue;

            }
            else if(a<=numberBas)
            {
                printf("���ڸ� �߸� �Է� �ϼ� ���ϴ�\n�ٽ��Է����ּ���\n");
                printf("\n\n============================================\n\n");
                continue;

            }
            else
            {
                numberBas=a;
                continue;
            }
            system( "cls" );
        }
        if(numberBas<31)
            continue;

        printf("\n\n ��� �Ͻ÷��� 1 �������� ���� ���÷��� 0�� �Է��ϼ���");
        scanf("%d",&c);
        printf("\n\n============================================\n\n");

        if(c==0)
            break;
    }
    printf("�̴� ���� �� ���� ���ư��ϴ�");
    printf("\n\n============================================\n\n");
    sleep(1);
    maininit();
}


void roulette()//���þ� �귿
{
    int user=0;
    int you=0;
    int plear=1;
    int gun=1;
    int minin;
    char test;
    srand(time(NULL));
    system( "cls" );
    printf("\n\n============================================\n\n");
    printf("���� ����\n");
    printf("�������� �������� ź�� ���ϴ�\n");
    printf("�ѻ���� ���ư��� ���� �߻� �մϴ�\n");
    printf("�׷��� �Ѿ��� ������ �ɸ��� �Ǹ�\n");
    printf("�й� �ϰ� �ʴϴ�\n");
    printf("\n\n============================================\n\n");

    printf("\n\n============================================\n\n");
    while(1)
    {
         while(1)
        {
            printf("�÷��̾� ���� �Է� ���ּ���(2�� �̻�)  : " );
            scanf("%d", &user);

            if(user<2)
            {
                printf("�÷��̾� ���� �����ϴ� �ٽ� �Է� ���ּ���\n");
                continue;
            }
            else
                break;
        }
        gun=rand()%6+1;
        while(1)
        {
            printf("%d �÷��̾� �� ���Դϴ� ���� �߻� �Ͻðڽ��ϱ�?\n",plear);
            printf("(�ƹ� Ű�� ���� �ּ���)\n");
            getchar();


            if(gun==you)
            {
                system( "cls" );
                plear=1;
                printf("\n\n============================================\n\n");
                printf("%d �÷��̾� ��/�� �ѿ� �¾�\n �й� �Ͽ����ϴ�\n",plear);
                printf("������ ���� �Դϴ�\n");
                printf("\n\n============================================\n\n");
                break;
            }

            else
            {
                plear++;
                you++;
                getchar();
            }
            if(plear>user)
                plear=1;

        }
        printf("������ �Լ� �Ͻ÷��� 1 ���� �޴��� ���� ���÷��� 0�� �Է� ���ּ���\n");
        scanf("%d", &minin);
        if(minin==0)
            break;
        else
            continue;

    }
    printf("�̴� ���� �� ���� ���ư��ϴ�\n");
    printf("\n\n============================================\n\n");
    sleep(1);
    system( "cls" );
    maininit();

}


void wabawe()
{
    int difficulty=0;
    int ii=0;
    int cap=0;
    int you=0;
    int beting=0;
    int aa=0;

    system( "cls" );
    printf("\n\n============================================\n\n");
    printf("��.���� ���Ű��� ȯ�� �մϴ�");
    printf("������ ��Ģ�� ���̵� ��ַ� ���� �ϰڽ��ϴ�?\n");
    printf("3���� ���� �ϳ��� ��� �ִ� ���� ���߸� �Ǵ� ���� �Դϴ�\n");
    printf("���� �� ���� ������ ���̵����� ���� ������ \n������ ����� �ٸ��ϴ�\n");
    printf("������ ����� ������ ���� ���� ���� Ȯ���� �Ҵ� �޾��� Ů�ϴ�\n");
    printf("���̵� ����â ���̵� ���� ��ȣ�� ���� ������ ���� ����(�Ҵ� �ݾ�) �Դϴ�\n");
    printf("�����ϰ� ���� ���ּ���\n");
    printf("\n\n============================================\n\n");
    printf("(��Ģ�� �� �о����� �ƹ� Ű�� ���� �ּ���)");
    getchar();
    getchar();
    system( "cls" );
    while(1)
    {
        while(1)
        {
             system( "cls" );
            printf("\n\n============================================\n\n");
            printf("���� �������� %lld �Դϴ�\n",meney);
            printf("���� �й��� ��� ���þ�*���� ���� ��ŭ �ҽ��ϴ�\n");
            printf("���Ͻô� ���̵� �� �Է����ּ��� \n");
            printf("1:���(3:2)\n2:����(5:5)\n3:�ϵ�(6:7)\n4:��(7:10)\n");
            scanf("%d",&difficulty);
            printf("\n\n============================================\n\n");
            if(difficulty==1)
            {
                ii=3;
                break;
            }
            else if(difficulty==2)
            {
                ii=5;
                break;
            }
            else if(difficulty==3)
            {
                ii=6;
                break;
            }
            else if(difficulty==4)
            {
                ii=7;
                break;
            }
            else if(difficulty>4)
            {
                printf("���̵� �� �ִ� 4������ �ֽ��ϴ�\n�ٽ� �Է����ּ���\n");
                continue;
            }
        }
        while(1)
        {
            printf("�ŷ� �� �ݾ��� ���� �ּ��� ");
            scanf("%d", &beting);
            if(beting>meney)
            {
                printf("������ ���� ���� �������ϴ� �ٽ� ���ּ���\n");
                continue;
            }
            if(beting<1000)
            {
                printf("�ŷ� �ݾ� �� �ּ� 1000�Դϴ� �ٽ� �Է� ���ּ���\n");
                continue;
            }
            else
                break;
        }
        while(1)
        {

            system( "cls" );
            cap=rand()%ii+1;
             printf("\n\n============================================\n\n");
             printf("���� �ŷ� �ݾ� : %lld\n", beting);
            printf("���° ���� ���� �Ͻðڽ��ϱ�(%d)",ii);
            scanf("%d",&you);
            if(cap==you)
            {
                if(difficulty==1)
                {
                    meney=meney+(beting*2);
                    printf("�¸� �Ͽ����ϴ� %lld ���� �����˽��ϴ�\n",beting*2);
                     break;
                }
                else if(difficulty==2)
                {
                    meney=meney+(beting*5);
                    printf("�¸� �Ͽ����ϴ� %lld ���� �����˽��ϴ�\n",beting*5);
                     break;
                }
                else if(difficulty==3)
                {
                    meney=meney+(beting*7);
                    printf("�¸� �Ͽ����ϴ� %lld ���� �����˽��ϴ�\n",beting*7);
                     break;
                }
                else if(difficulty==4)
                {
                    meney=meney+(beting*10);
                    printf("�¸� �Ͽ����ϴ� %lld ���� �����˽��ϴ�\n",beting*10);
                     break;
                }

            }
            else
            {
                printf("��� ������ ���� �Ͽ� ���� �Ҿ����ϴ�\n������ ��� ������\n");
                printf("��� : %d\n", cap);
                printf("���� �ݾ� %lld", beting*ii);

                meney=meney-(beting*ii);

                break;
            }
        }
            printf("\n\n============================================\n\n");
            printf("������ : %lld\n",meney);
            printf("�ٽ� ���� �Ͻ÷��� 0\n�ٽ� ���� ���� �� �� ���÷��� 1�� �Է����ּ���\n");
            scanf("%d", &aa);
            if(aa==0)
                continue;
            else if(aa==1)
            {
                printf("\n\n============================================\n\n");
                printf("���� ���� �� ���� �̵� �Դϴ�");
                printf("\n\n============================================\n\n");
                sleep(2);
                maininit();
            }


    }
}
void updwon()
{
    int you=0;
    int trynum=0;
    int rendom=0;
    int def=0,def1;
    int aa=0;
    while(1)
    {
        system( "cls" );
        printf("\n\n============================================\n\n");
        printf("���ٿ� ���� �Ӵϴ�\n");
        printf("�⺻������ 20���� ��ȸ�� �ָ� �� �ȿ� ���ڸ� ���߽ø� �ʴϴ�\n");
        printf("\n\n============================================\n\n");
        getchar();
        getchar();
        while(1)
        {
            printf("���̵��� ���� ���ּ���\n\n");
            printf("1:���(1~100)\n2:����(1~250)\n3:�����(1~500)\n");
            scanf("%d", &def);
            if(def==1)
            {
                def1=100;
                break;
            }

            else if(def==2)
            {
                def1=250;
                break;
            }

            else if(def==3)
            {
                def1=500;
                break;
            }

            else
            {
                printf("�߸��� ���ڸ� �Է� �Ͽ����ϴ� �ٽ� �Է� �ϼ���\n");
            }

        }
        while(1)
        {
            srand(time(NULL));
            rendom=rand()%def1+1;
            while(1)
            {
                printf("\n\n============================================\n\n");
                printf("1~%d ������ ���ڸ� �Է����ּ��� : ",def1);
                scanf("%d",&you);
                printf("\n\n============================================\n\n");

                if(rendom<you)
                {
                    trynum++;
                    printf("���� ���� ��ȸ:%d\n",20-trynum);
                    printf("�ٿ�\n\n");

                    continue;
                }
                else if(rendom>you)
                {
                    trynum++;
                    printf("���� ���� ��ȸ:%d\n",20-trynum);
                    printf("��\n\n");

                    continue;

                }
                else if(rendom==you)
                {
                    printf("������ ���߼̽��ϴ�\n");
                    break;
                }
                else if(you<0||you>def1)
                {
                    printf("���ڸ� �߸� �Է� �ϼ̽��ϴ�\n�ٽ� �Է� ���ּ���\n");
                    continue;
                }
                if(trynum>=20)
                {
                    printf("��� ��ȸ�� ���� �Ͽ����ϴ�\n���ٿ� ������ ���� �ῴ���ϴ�\n");
                    break;
                }
            }
             printf("\n\n============================================\n\n");
            printf("����� ��ȸ�� %d\n", trynum);
            printf("��� �Ͻ÷��� 1�� �̴ϰ��� ������ ���÷��� 0�� �Է� ���ּ���\n");
            scanf("%d",&aa);
             printf("\n\n============================================\n\n");
            if(aa=0)
                continue;
            else
            {
                printf("�̴ϰ��� ������ �̵� �մϴ�");
                sleep(2);
                maininit();
            }


        }

    }
}
