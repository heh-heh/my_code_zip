#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define fo(x,start,end) for(int x=start; x<end; x++)
#define x 99
#define swap(m1, m2) {int temp=m1; m1=m2; m2=temp;}

int Apuck = 0;
int Amap[5][5]={//메인 맵
{x,x,x,x,x},
{x,2,0,2,x},
{x,2,1,0,x},
{x,0,0,1,x},
{x,x,x,x,x},
};


int Amap2[3][3]={0};//정렬 된애들 고정용
int sortAmap[3][3]={0};//정렬을 위한 맵
int test[9]={0};
int sdir[5]={0,-5,1,5,-1};
int sdir3[5]={0,-3,1,3,-1};

int move[100][2]={0};//퍽 움직임을 저장할 배열(퍽 번호는 10+색갈+우선 순위
int ii=0,jj=0;
int ii2=1, jj2=0;
int *p;


int puckcheck(void);
void sort_puckcheck(int *map);
void sort_Amap(int *map,int *map2);
void boublesort(void);
void pucknum(int *map);



int main(void)
{
    Apuck = puckcheck();
    fo(i,1,4) fo(j,1,4) Amap2[i][j]=Amap2[i][j]==-1?-1:Amap[i][j];
    printf("%d %d\n",ii, jj);
    printf("%d\n", Apuck);

    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++){
            printf("%3d ",Amap2[i][j]);
            sortAmap[i][j]=Amap2[i][j]==-1?Apuck:Amap2[i][j];
        }
        printf("\n\n");
    }

    printf("\n\n");
    p=&sortAmap[1][1];
    fo(i,0,9) {test[i]=*(p+(i));}

    boublesort();


    fo(i,1,10) {if(i%3==0)printf("%3d \n\n",test[i-1]); else printf("%3d ",test[i-1]);}
    p=&sortAmap[0][0];


    sort_puckcheck(&Amap2[1][1]);

    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++){
            printf("%3d ",&Amap2[i][j]);
            sortAmap[i-1][j-1]=Amap2[i][j];
        }
        printf("\n\n");
    }


    p=&sortAmap[0][0];
    sort_Amap(&Amap2[0][0],&sortAmap[0][0]);

    fo(i,1,10)if(i%3==0)printf("%3d \n\n",test[i-1]);else printf("%3d ",test[i-1]);
    fo(i,0,15) printf("%3d : %d\n", move[i][0], move[i][1]);
}
int puckcheck(void)//우선 정렬 퍽을 지정 하기 위한 것
{
    int red=0,blue=0;
    fo(i, 1, 4)
        fo(j,1,4)
        {
            Amap[i][j]==1?red++:Amap[i][j]==2?blue++:0;
        }
    if(red>blue)
        return 1;
    return 2;
}

void sort_puckcheck(int *map)//목표맵과 현재 비교용
{
    fo(i,0,9)if(*(map+i)==test[i])*(map+i)*=-1;
}
void sort_Amap(int *map,int *map2)
{
    int check=0;
    int *puck;

    fo(i,0,9)if(*(map2+i)>0){puck=(map2+i);break;}
    move[ii][0]=puck;

    fo(i,1,4)
        if(*(puck+sdir3[i])==0){
                swap(*puck, *(puck+sdir3[i]));
                move[ii++][1]=i;
                fo(i,0,9) *(map2+i)=test[i]==*(map2+i)?*(map2+i)*-1:*(map2+i);break;
        }
    fo(i,0,9)*(map+i)=*(map2+i);
    fo(i,0,9)if(*(map+i)>0){puck=(map+i);break;}

    fo(i,1,10)if(i%3==0)printf("%3d \n\n",*(map2+(i-1)));else printf("%3d ",*(map2+(i-1)));
    //fo(i,1,4)if(*(puck+(sdir3[i]*-1)!=0){
    fo(i,0,9){check=test[i]!=*(map2+i)?1:0;}
    if(check==0)return;
    else sort_Amap(&Amap2[1][1],&sortAmap[0][0]);
}

void boublesort(void)//버블정렬
{

}
