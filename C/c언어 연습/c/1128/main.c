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
void seullosmeosin();//미완
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
    printf("기본 메뉴 창 입니다\n ");
    printf("현대 놀이 장 으로 가시려면 1 \n 미니 게임 을 하시려면 2 \n를 입력 해주세요");
    printf("\n\n=========================================================\n\n");
    scanf("%d",&a);
    if(a==1)
    {

        printf("\n\n============================================\n\n");
        printf("현대 놀이 장  으로 이동 함니다\n 돈을 낭비 하지 않게 조심 해주세요");
        printf("\n\n============================================\n\n");
        sleep(2);
        gambling();

    }

    else if(a==2)
    {

         printf("\n\n============================================\n\n");
         printf("미니 게임을 이동 합니다\n간단하게만 즐겨 주세요\n");
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
    printf("종합 미니게임\n\n");
    printf("숫자 이외의 것을 입력하면\n에러가 남으로 하지 마세요\n");
    printf("1 : 가위바위보\n2 : 동전 앞뒤 맞추기\n3 : 베스킨라빈스 31\n4 : 러시안룰렛\n5 : 업다운 게임\n6 : 컵구\n0 : 종료");
    printf("\n숫자를 입력하세요\n");
    scanf("%d", &a);
    printf("\n\n=========================================================\n\n");
    if(a==1)
    {
        printf("가위바위보 게임을 실행 합니다\n");
        sleep(1);
        Janken();

    }

    else if(a==2)
    {
        printf("동전 앞뒤 맞추기 게임을 실행 합니다\n");
        sleep(1);
        coin();
    }

    else if(a==3)
    {
        printf("베스킨 라빈스 31 게임을 실행 합니다");
        sleep(1);
         Baskin();
    }

    else if(a==4)
    {
        printf("러시안 룰렛 게임을 실행 합니다\n");
        sleep(1);
         roulette();
    }
    else if(a==5)
    {
        printf("업다운 게임을 실행 합니다\n");
        sleep(1);
        updwon();
    }
    else if(a==6)
    {
        printf("컵구 게임을 실행함니다");
        sleep(1);
        wabawe();

    }
    else if(a==0)
    {
        printf("게임을 종료함니다");
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
    printf("현대 놀이 방에 오신것을 환영함니다\n");
    printf("현재 소지금 은 %d 입니다\n",meney);
    printf("게임은 게임일 뿐 과몰입 하지 말아 주세ㅇ\n");
    printf("\n\n============================================\n\n");
    printf("하고 싶은 게임의 숫자를 입력하세요\n");
    printf("1:컵안의 구슬 찾기\n0:메인 메뉴\n");
    scanf("%d", &a);
    if(a==1)
    {
         printf("\n\n============================================\n\n");
        printf("컵.구로 이동 합니다");
        printf("\n\n============================================\n\n");
        sleep(2);
        wabawe();
    }
    else if(a==0)
    {
         printf("\n\n============================================\n\n");
         printf("메인 메뉴로 이동합니다");
          printf("\n\n============================================\n\n");
            sleep(2);
            menuw();
    }
}
*/
void coin()//동전 맞추기
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
        printf("당신이 생각하는 결과를 적으세요(1:앞 2:뒤,0 입력시 종료)");
        scanf("%d", &usr);
        printf("\n\n============================================\n\n");
        if(usr==0)
            break;
        if(usr==1&&coin==2)
        {
            printf("\n\n============================================\n\n");
            printf("결과는 뒤입니다\n");
            printf("졌습니다");
            printf("\n\n============================================\n\n");
            lost++;
        }
        else if(usr==2&&coin==1)
        {
            printf("\n\n============================================\n\n");
            printf("결과는 앞입니다\n");
            printf("졋습니다");
            printf("\n\n============================================\n\n");
            lost++;
        }
        else if(usr==coin)
        {
            printf("\n\n============================================\n\n");
            printf("당신이 이겼습니다");
            printf("\n\n============================================\n\n");
            win++;
        }
        else
        {
            printf("\n\n============================================\n\n");
            printf("잘못 입력 했습니다\n다시 입력해주세요");
            printf("\n\n============================================\n\n");
        }

    }
    system( "cls" );
    printf("\n\n============================================\n\n");
    printf("당신이 이긴 횟수 %d\n", win);
    printf("당신이 진 횟수 %d\n", lost);
    printf("\n\n미니 게임 장으로 돌아갑니다");
    printf("\n\n============================================\n\n");
    sleep(1);
    maininit();

}

void Janken()//가위바위보 함수
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
        printf("가위바위보(1:가위,2:바위, 3:보,0:게임종료)");
        scanf("%d", &test);
        printf("\n\n============================================\n\n");
        if(a==test)
        {

            printf("\n\n============================================\n\n");
            printf("상대방 : %d\n나 : %d\n", a,test);
            printf("비겼습니다\n");
            printf("\n\n============================================\n\n");
            lost++;
        }
        else if((a==1&test==3)||(a==2&&test==1)||(test==2&&a==3))
        {

            printf("\n\n============================================\n\n");
            printf("상대방 : %d\n나 : %d\n", a,test);
            printf("졌습니다\n");
            printf("\n\n============================================\n\n");
            lost++;
        }
        else if(test>3)
        {

            printf("\n\n============================================\n\n");
            printf("잘못 입력했습니다 다시 입력 해주세요\n");
            printf("\n\n============================================\n\n");
        }
        else
        {

            printf("\n\n============================================\n\n");
            printf("상대방 : %d\n나 : %d\n", a,test);
            printf("이겼습니다\n");
            printf("\n\n============================================\n\n");
            win++;

        }
        if(test==0)
            break;


    }
    system( "cls" );
    printf("\n\n============================================\n\n");
    printf("이긴횟수 %d\n", win);
    printf("진 횟수 : %d", lost);
    printf("\n\n미니 게임 장 으로 돌아 갑니다");
    printf("\n\n============================================\n\n");
    sleep(1);
    maininit();
}


void Baskin()//베스킨라빈스31
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
        printf("베스킨라빈스 31 게임 입니다\n 한번에 1~3번째 수 까지만 입력 가능합니다\n");
        printf("한번에 한 숫자만 입력 가등 합니다\n");
        printf("플레이어 수(2이상)를 입력해주세요 : ");
        scanf("%d",&b);
        printf("\n\n============================================\n\n");
        if(b<2)
        {

            printf("플레이어 수가 너무 적습니다\n다시 입력해주세요");
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
                printf("플레이어 %d 가졌습니다", i==1?2:1);
                printf("\n\n============================================\n\n");
                break;
            }

            printf("\n\n============================================\n\n");
            printf("플레이어 %d 께서 부르실 숫자를 입력해주세요\n",i);
            printf("현재 숫자는 %d 입니다\n", numberBas);
            scanf("%d",&a);
            printf("\n\n============================================\n\n");
            if(a>numberBas+3)
            {
                printf("숫자가 너무 큽니다\n다시 입력해 주세요\n");
                printf("\n\n============================================\n\n");
                i--;
                continue;

            }
            else if(a<=numberBas)
            {
                printf("숫자를 잘못 입력 하셨 습니다\n다시입력해주세요\n");
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

        printf("\n\n 계속 하시려면 1 메인으로 돌아 가시려면 0을 입력하세요");
        scanf("%d",&c);
        printf("\n\n============================================\n\n");

        if(c==0)
            break;
    }
    printf("미니 게임 장 으로 돌아감니다");
    printf("\n\n============================================\n\n");
    sleep(1);
    maininit();
}


void roulette()//러시안 룰렛
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
    printf("게임 설명\n");
    printf("리볼버에 랜덤으로 탄이 들어감니다\n");
    printf("한사람씩 돌아가며 총을 발사 합니다\n");
    printf("그러다 총알이 들어간곳에 걸리게 되면\n");
    printf("패배 하게 됨니다\n");
    printf("\n\n============================================\n\n");

    printf("\n\n============================================\n\n");
    while(1)
    {
         while(1)
        {
            printf("플레이어 수를 입력 해주세요(2명 이상)  : " );
            scanf("%d", &user);

            if(user<2)
            {
                printf("플레이어 수가 적습니다 다시 입력 해주세요\n");
                continue;
            }
            else
                break;
        }
        gun=rand()%6+1;
        while(1)
        {
            printf("%d 플레이어 의 턴입니다 총을 발사 하시겠습니까?\n",plear);
            printf("(아무 키나 눌러 주세요)\n");
            getchar();


            if(gun==you)
            {
                system( "cls" );
                plear=1;
                printf("\n\n============================================\n\n");
                printf("%d 플레이어 이/가 총에 맞아\n 패배 하였습니다\n",plear);
                printf("게임을 종료 함니다\n");
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
        printf("게임을 게속 하시려면 1 메인 메뉴로 돌아 가시려면 0을 입력 해주세요\n");
        scanf("%d", &minin);
        if(minin==0)
            break;
        else
            continue;

    }
    printf("미니 게임 장 으로 돌아갑니다\n");
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
    printf("컵.구에 오신것을 환영 합니다");
    printf("게임의 규칙은 난이도 노멀로 설명 하겠습니다?\n");
    printf("3개의 컵중 하나에 들어 있는 공을 맞추면 되는 게임 입니다\n");
    printf("간단 한 게임 이지만 난이도별로 컵의 갯수와 \n보상의 배수가 다릅니다\n");
    printf("보상의 배수가 높으면 높을 수록 잃을 확율과 잃는 급액이 큽니다\n");
    printf("난이도 선택창 난이도 옆의 괄호는 컵의 갯수와 보상 배율(잃는 금액) 입니다\n");
    printf("신중하게 선택 해주세요\n");
    printf("\n\n============================================\n\n");
    printf("(규칙을 다 읽었으면 아무 키나 눌러 주세요)");
    getchar();
    getchar();
    system( "cls" );
    while(1)
    {
        while(1)
        {
             system( "cls" );
            printf("\n\n============================================\n\n");
            printf("현재 소지금은 %lld 입니다\n",meney);
            printf("만약 패배할 경우 베팅액*컵의 갯수 만큼 잃습니다\n");
            printf("원하시는 난이도 를 입력해주세요 \n");
            printf("1:노멀(3:2)\n2:보통(5:5)\n3:하드(6:7)\n4:헬(7:10)\n");
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
                printf("난이도 는 최대 4까지만 있습니다\n다시 입력해주세요\n");
                continue;
            }
        }
        while(1)
        {
            printf("거래 할 금액을 적어 주세요 ");
            scanf("%d", &beting);
            if(beting>meney)
            {
                printf("소지금 보다 많이 적었습니다 다시 해주세요\n");
                continue;
            }
            if(beting<1000)
            {
                printf("거래 금액 은 최소 1000입니다 다시 입력 해주세요\n");
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
             printf("현재 거래 금액 : %lld\n", beting);
            printf("몇번째 컵을 선택 하시겠습니까(%d)",ii);
            scanf("%d",&you);
            if(cap==you)
            {
                if(difficulty==1)
                {
                    meney=meney+(beting*2);
                    printf("승리 하였습니다 %lld 원을 얻으셧습니다\n",beting*2);
                     break;
                }
                else if(difficulty==2)
                {
                    meney=meney+(beting*5);
                    printf("승리 하였습니다 %lld 원을 얻으셧습니다\n",beting*5);
                     break;
                }
                else if(difficulty==3)
                {
                    meney=meney+(beting*7);
                    printf("승리 하였습니다 %lld 원을 얻으셧습니다\n",beting*7);
                     break;
                }
                else if(difficulty==4)
                {
                    meney=meney+(beting*10);
                    printf("승리 하였습니다 %lld 원을 얻으셧습니다\n",beting*10);
                     break;
                }

            }
            else
            {
                printf("결과 예측에 실패 하여 돈을 잃었습니다\n다음을 노려 보세요\n");
                printf("결과 : %d\n", cap);
                printf("읽은 금액 %lld", beting*ii);

                meney=meney-(beting*ii);

                break;
            }
        }
            printf("\n\n============================================\n\n");
            printf("남은돈 : %lld\n",meney);
            printf("다시 도전 하시려면 0\n다시 현대 놀이 장 을 가시려면 1을 입력해주세요\n");
            scanf("%d", &aa);
            if(aa==0)
                continue;
            else if(aa==1)
            {
                printf("\n\n============================================\n\n");
                printf("현대 놀이 장 으로 이동 함니다");
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
        printf("업다운 게임 임니다\n");
        printf("기본적으로 20번의 기회를 주며 그 안에 숫자를 맟추시면 됨니다\n");
        printf("\n\n============================================\n\n");
        getchar();
        getchar();
        while(1)
        {
            printf("난이도를 설정 해주세요\n\n");
            printf("1:노멀(1~100)\n2:보통(1~250)\n3:어려움(1~500)\n");
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
                printf("잘못된 숫자를 입력 하였습니다 다시 입력 하세요\n");
            }

        }
        while(1)
        {
            srand(time(NULL));
            rendom=rand()%def1+1;
            while(1)
            {
                printf("\n\n============================================\n\n");
                printf("1~%d 사이의 숫자를 입력해주세요 : ",def1);
                scanf("%d",&you);
                printf("\n\n============================================\n\n");

                if(rendom<you)
                {
                    trynum++;
                    printf("현재 남은 기회:%d\n",20-trynum);
                    printf("다운\n\n");

                    continue;
                }
                else if(rendom>you)
                {
                    trynum++;
                    printf("현재 남은 기회:%d\n",20-trynum);
                    printf("업\n\n");

                    continue;

                }
                else if(rendom==you)
                {
                    printf("정답을 맞추셨습니다\n");
                    break;
                }
                else if(you<0||you>def1)
                {
                    printf("숫자를 잘못 입력 하셨습니다\n다시 입력 해주세요\n");
                    continue;
                }
                if(trynum>=20)
                {
                    printf("모든 기회를 소진 하였습니다\n업다운 게임을 실패 햐였습니다\n");
                    break;
                }
            }
             printf("\n\n============================================\n\n");
            printf("사용한 기회수 %d\n", trynum);
            printf("계속 하시려면 1을 미니게임 장으로 가시려면 0을 입력 해주세요\n");
            scanf("%d",&aa);
             printf("\n\n============================================\n\n");
            if(aa=0)
                continue;
            else
            {
                printf("미니게임 장으로 이동 합니다");
                sleep(2);
                maininit();
            }


        }

    }
}
