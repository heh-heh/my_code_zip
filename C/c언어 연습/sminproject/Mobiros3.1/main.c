#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define x 99
#define R -9
#define b 77

#define swap(m1,m2) {int temp=m1; m1=m2; m2=temp;}
#define MR 6
#define MC 11

void mapinit(void);
void sort(void);
void smt(int index);
void updata(int *map, int *map2);//sort맵 업데이트용
int checkmap(int *map, int *map2);

int M_map[11][6]={
    {x,x,x,x,x,x},
    {x,2,3,1,0,x},
    {x,0,0,0,1,x},
    {x,2,3,2,0,x},
    {x,0,0,0,3,x},
    {x,0,0,0,0,x},
    {x,x,x,x,x,x},
    {x,0,0,0,0,x},
    {x,0,2,0,0,x},
    {x,0,0,1,1,x},
    {x,x,x,x,x,x},
};
int copy_map[11][6]={
    {x,x,x,x,x,x},
    {x,0,0,0,0,x},
    {x,0,0,0,0,x},
    {x,0,0,0,0,x},
    {x,0,0,0,0,x},
    {x,0,0,0,0,x},
    {x,x,x,x,x,x},
    {x,0,0,0,0,x},
    {x,0,0,0,0,x},
    {x,0,0,0,0,x},
    {x,x,x,x,x,x},
};
int sort_map[11][6]={{0,},};

int F_map[11][6]={{0,},};

int sdir[5]={0,-6,1,6,-1};
int Ssdir[4]={0,1,6,7};
int ri=0,rj=0;
int eatP[2]={0,0};//[0]:퍽을 먹었는지 판단 [1] : 먹은 퍽의 색갈
int mpt[10][2]={{0,},};// 움직임을 저장 하기 위한
int disx = 100;


int main(void)
{
    mapinit();


    printf("\n\n");

    for(int i=1; i<6; i++)
    {
        for(int j=1; j<5; j++)
            printf("%3d ", F_map[i][j]);
        printf("\n\n");
    }
    printf("\n\n");
    printf("%d %d\n",ri,rj);
    updata(&sort_map[0][0],&copy_map[0][0]);
    printf("_________________\n|");
    for(int i=1; i<10; i++)
    {
        for(int j=1; j<5; j++)
            printf("%3d ", copy_map[i][j]);
        printf("|\n|                |\n|");
    }
    printf("%d", checkmap(&sort_map[0][0],&F_map[0][0]));
    return 0;
}

void mapinit(void)
{
    if(disx>110){M_map[6][1]=b;copy_map[6][1]=b;}
    else if(disx>80){M_map[6][2]=b;copy_map[6][2]=b;}
    else {M_map[6][3]=b;copy_map[6][3]=b;}

    for(int i=0; i<11; i++)for(int j=0; j<6; j++)F_map[i][j]=M_map[i][j]<3?0:M_map[i][j]==3?M_map[i][j]*-1:M_map[i][j];
    for(int i=0; i<11; i++)for(int j=0; j<6; j++)M_map[i][j]=M_map[i][j]==3?M_map[i][j]*-1:M_map[i][j];
    for(int i=1; i<10; i++)for(int j=1; j<5; j++)copy_map[i][j]=M_map[i][j];


    for(int i=0; i<7; i++)for(int j=0; j<6; j++)if(copy_map[i][j]==77){*(&copy_map[i][j]+sdir[1])=R;ri=i-1;rj=j;break;}

    int ck2=0;
    for(int i=1; i<5; i++)
    {
        for(int j=1; j<6; j++)
        {
            int ck=0;
            for(int z=0; z<4; z++){if(*(&F_map[i][j]+Ssdir[z])!=0||*(&F_map[i][j]+Ssdir[z])==x){ck++;break;}}
            if(ck==0&&ck2<2){ck2++;for(int z=0; z<4; z++) *(&F_map[i][j]+Ssdir[z])=9;}
        }
    }
    int ck3=0;
    for(int i=1; i<5; i++)
    {
        for(int j=1; j<6; j++)
        {
            if(F_map[i][j]==9){
                int red=0,blue=0;
                for(int z=0; z<4; z++){
                    if(*(&M_map[i][j]+Ssdir[z])==1)red++;
                    else if(*(&M_map[i][j]+Ssdir[z])==2)blue++;
                }
                if(red||blue){
                    if(red>=blue){ck3=1; for(int z=0; z<4; z++) *(&F_map[i][j]+Ssdir[z])=1;}
                    else{ck3=2; for(int z=0; z<4; z++) *(&F_map[i][j]+Ssdir[z])=2;}
                }
                else
                {
                    if(ck3==1)for(int z=0; z<4; z++) *(&F_map[i][j]+Ssdir[z])=2;
                    else if(ck3==2)for(int z=0; z<4; z++) *(&F_map[i][j]+Ssdir[z])=1;
                }
            }
        }
    }
}

int checkmap(int *map, int *map2)//정렬 체크용
{
    for(int i=0; i<MR*MC; i++)if(*(map+i)!=*(map2+i))return 0;
    return 1;
}
void updata(int *map, int *map2){
    for(int i=0; i<MR*MC; i++) *(map+i)=*(map2+i)==R?0:*(map2+i)==b?x:*(map2+i);
}
