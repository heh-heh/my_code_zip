#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define fo(x,start,end) for(int x=start; x<end; x++)
#define x 99
#define swap(m1, m2) {int temp=m1; m1=m2; m2=temp;}


int complete_map[8][3][3]={//�ϼ���
{
        {2,1,1},
        {2,0,0},
        {2,0,0}
    },

    {
        {2,0,0},
        {2,0,0},
        {2,1,1}
    },

    {
        {1,1,2},
        {0,0,2},
        {0,0,2}
    },

    {
        {0,0,2},
        {0,0,2},
        {1,1,2}
    },

    {
        {2,2,2},
        {0,0,1},
        {0,0,1}
     },

    {
        {2,2,2},
        {1,0,0},
        {1,0,0}
     },

    {
        {0,0,1},
        {0,0,1},
        {2,2,2}
     },

    {
        {1,0,0},
        {1,0,0},
        {2,2,2}
    }
};


int Amap[5][5]={//���� ��
{x,x,x,x,x},
{x,2,0,2,x},
{x,0,1,2,x},
{x,0,0,1,x},
{x,x,x,x,x},
};
int Amap2[3][3]={0};//���̺�� ��
int sortAmap[3][3]={0};//sort_puck ���� ���
int sdir[5]={0,-5,1,5,-1};
int sdir3[5]={0,-3,1,3,-1};

int move[100][2]={0};//�� �������� ������ �迭(�� ��ȣ�� 10+����+�켱 ����
int *p;//��ǥ�� �� ����ų �뵵
int *puck;//������ ���� ����ų �뵵
int Apuck=0;
int Apuck2=0;
int ii=0;

void puckcheck(void);
void puckcheck2(void);
void sort_puckcheck(int *map2);
void sort_puck(int *map,int *map2);

int main(void)
{
    puckcheck();


    fo(i,1,4){
        fo(j,1,4) printf("%3d ", Amap[i][j]);
        printf("\n\n");
    }
    puckcheck2();
    printf("%d\n", p);

    fo(i,1,4) fo(j,1,4) Amap2[i-1][j-1]=Amap[i][j];
    sort_puckcheck(&Amap2[0][0]);


    fo(i,1,10)if(i%3==0)printf("%3d \n\n", *(p+(i-1)));else printf("%3d ", *(p+(i-1)));
    printf("%d\n", Apuck);
    sort_puck(&Amap2[0][0],&sortAmap[0][0]);

    fo(i,0,3){
        fo(j,0,3) printf("%3d ", Amap2[i][j]);
        printf("\n\n");
    }
    fo(i,0,10)printf("%d : %d\n", move[i][0], move[i][1]);
}
void puckcheck(void)//�ϼ��� ���� ��ȯ��
{
    int red=0,blue=0;
    fo(i, 1, 4)
        fo(j,1,4)
        {
            Amap[i][j]==1?red++:Amap[i][j]==2?blue++:0;
        }

    if(red>blue)
    {
        Apuck=1;Apuck2=2;
        fo(i,0,8)
            fo(j,0,3)
                fo(z,0,3)
                    complete_map[i][j][z]=complete_map[i][j][z]==1?2:complete_map[i][j][z]==2?1:0 ;
    }
    else {Apuck=2;Apuck2=1;}


}
void puckcheck2(void)//���� �ϼ��� ���� ��
{
    int check[8]={0};
    fo(i,0,8)
    {
        fo(ii,0,3)
            fo(j,0,3)
                if(complete_map[i][ii][j]==Amap[ii+1][j+1])check[i]++;
    }
    int max=0;
    for(int i=0; i<8; i++)
        if(check[i]>check[max])
            max=i;
    p=&complete_map[max][0][0];//�����Ϳ� ��ǥ�� ����
}
void sort_puckcheck(int *map2)//�� �񱳿�
{
    fo(i,0,9) *(map2+i) = *(map2+i)==*(p+i) ? *(map2+i)*-1 : *(map2+i);
}
void sort_puck(int *map,int *map2)//����
{
    int check=0;
    int puck2 =0;
    int pp=0;//���� ǥ�ÿ�
    fo(i,0,9)if(*(map+i)>0){puck=map+i; puck2=i; break;}//���� ������

    //fo(i,1,10)if(i%3==0)printf("%3d \n\n", (map+(i-1)));else printf("%3d ", (map+(i-1)));
    if(puck2==4)//����ġ�� �� �߾� �϶�
    {
        printf("%d -----if\n", puck2);
        if(*(map+puck2)!=Apuck)
        {
            fo(i,1,5)if(*(map+puck2+sdir3[i])==0&&*(p+puck2+sdir3[i])==0){
            swap(*puck,*(puck+sdir3[i]));
            move[ii][0]=puck;move[ii++][1]=i;//������ ����
            break;
            }
        }

        else if(*(map+puck2)==Apuck)
        {
            fo(i,1,5)if(*(map+puck2)==Apuck&&*(map+puck2)==*(p+puck2+sdir3[i])&&*(p+puck2+sdir3[i])!=x){pp=i;break;}

            if(*(map+puck2+(sdir3[pp]*-1))>0)puck=(map+puck2+(sdir3[pp]*-1));

            fo(i,1,5)if(*(puck+(sdir[i]*-1))==0){
                swap(*puck,*(puck+sdir3[i]));
                move[ii][0]=puck;move[ii++][1]=i;//������ ����
                break;
            }

            swap(*(map+puck2),*(map+puck2+sdir[pp]));//���߾Ӿ� �� ������
        }

    }
    else
    {
        printf("%d -----else \n ", puck2);
        fo(i,1,5)
            if(*(map+puck2+sdir3[i])==0&&*(map2+puck2+sdir[i])!=*(map+puck2)&&puck2+sdir3[i]>=0&&*(p+puck2+sdir3[i])!=x){
                swap(*(map+puck2),*(map+puck2+sdir3[i]));
                move[ii][0]=puck;move[ii++][1]=i;//������ ����
                break;

            }
            getchar();getchar();

    }

    move[ii][0]=map+puck2;move[ii++][1]=pp;//������ ����
    sort_puckcheck(map);
    printf("map------------------------\n");
    fo(i,1,10)if(i%3==0)printf("%3d \n\n", *(map+(i-1)));else printf("%3d ", *(map+(i-1)));
    printf("------------------------\n");
    if(check==1)return;
    sort_puck(map,map2);


}
