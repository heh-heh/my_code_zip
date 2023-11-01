#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define mine -1
int map[40][40]={0};
int mapsiz=0;


int main(void)
{
    int map[42][42]={99};
    int minemap[42][42]={0};//배열에 1차원값을 채워 넣을 용도

    int def=0;
    int minespwon[300]={0};
    int ii=0;
    int x=0,y=0;



    while(1)
    {
        printf("맵의 크기를 입력해주세요(5이상,40이하) : ");
        if(0==scanf_s("%d",&mapsiz)||(mapsiz<5||mapsiz>40))
        {
            printf("잘못 입력 되었습니다\n다시 입력 해주세요");
            sleep(2);
            system(" cls ");
            rewind(stdin);
        }
        else break;
    }
    for(int i=1; i<=mapsiz; i++)
        for(int j=1; j<=mapsiz; j++)
            minemap[i][j]=ii++;
    while(1)
    {
        printf("1 : 쉬움\n");
        printf("2 : 보통\n");
        printf("3 : 어려움\n");
        printf("4 : 하드(매우어려움)\n");
        printf("난이도를 선택해주세요 : ");
        if(0==scanf_s("%d",&def)||(def<1||def>4))
        {
            printf("잘못 입력 되었습니다\n다시 입력 해주세요");
            sleep(2);
            system(" cls ");
            rewind(stdin);
        }
        else break;
    }
    int sdir[4]={-1*mapsiz,1,1*mapsiz,-1};
    int minecount = (mapsiz*1.5)*(def*0.5);//지뢰 겟수
    //printf("%d", minecount);테스트
    srand(time(NULL));
    for(int i=0; i<minecount; i++)//지뢰 배치용 반복문
    {
        minespwon[i]=rand()%(mapsiz*mapsiz);
        for(int j=i+1; j<minecount-1; j++)
            if(minespwon[i]==minespwon[j])
            {
                i--;
                break;
            }
    }

    //for(int i=0; i<minecount; i++)
    //    printf("%d\n", minespwon[i]);

    for(int i=1; i<=mapsiz; i++) //지뢰 배치
    {
         for(int j=1; j<=mapsiz; j++)
            for(int jj=0; jj<minecount;jj++)
                if(minemap[i][j]==minespwon[jj])map[i][j]=-1;
    }

    for(int i=1; i<=mapsiz; i++)
    {
         for(int j=1; j<=mapsiz; j++)
            if(map[i][j]==0)
            {
                for(int iii=i-1<1?1:i-1; iii<=(i+1>=mapsiz?mapsiz:i+1); iii++)
                    for(int jjj=j-1<1?1:j-1; jjj<=(j+1>=mapsiz?mapsiz:j+1); jjj++)
                        if(map[iii][jjj]<=-1)
                        {
                            ++map[i][j];
                        }
            }
    }/*
    for(int i=1; i<=mapsiz; i++)//맵 배열 확인용
    {
         for(int j=1; j<=mapsiz; j++)
            printf("%3d", map[i][j]);
         printf("\n");
    }getchar();getchar();*/
    for(int i=0; i<4; i++)//이건 혹시나할 방향 확인용
        printf("%d ",sdir[i]);
    while(1)
    {
        system(" cls ");
        for(int i=1; i<=mapsiz; i++)
        {
            for(int j=1; j<=mapsiz; j++)
            {
                if(map[i][j]==-2)
                    printf("▣");
                else if(map[i][j]==5)
                    printf("□");
                else
                    printf("■");
            }
            printf("\n");
        }

        if(map[x][y]==-2) break;

        printf("x,y 좌표를 입력하세요(1이상,%d이하) : ",mapsiz);
        if(0==scanf_s("%d %d",&x, &y)||x<1||x>mapsiz||y<1||y>mapsiz)
        {
            printf("잘못 입력 되었습니다\n다시 입력 해주세요");
            sleep(2);
            system(" cls ");
            rewind(stdin);
        }
        else
            map[x][y]=map[x][y]>=0?map[x][y]+5:-2;

        for(int i=1; i<=mapsiz; i++)
        {
            for(int j=1; j<=mapsiz; j++)
                printf("%3d ",map [i][j]);
            printf("\n\n");
        }
        getchar();getchar();

    }

}

