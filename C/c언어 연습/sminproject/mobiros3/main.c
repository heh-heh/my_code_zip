#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define x 99
#define X 88
#define R -99 //현 로봇 위치
#define r -88 //가야될 로봇 위치
#define fo(i1,sart,end) for(int i1=sart; i1<end; i1++)
#define swap(m1, m2) {int temp=m1; m1=m2; m2=temp;}


int C_map[12][5][5]={
    {{x,x,x,x,x},
    {x,2,0,2,x},
    {x,0,1,0,x},
    {x,2,0,1,x},
    {x,x,R,x,x}},

    {{x,x,x,x,x},
    {x,1,0,2,x},
    {x,0,2,0,x},
    {x,2,0,1,x},
    {x,x,R,x,x}},

    {{x,x,x,x,x},
    {x,1,0,1,x},
    {x,0,2,0,x},
    {x,2,0,2,x},
    {x,x,R,x,x}},

    {{x,x,x,x,x},
    {x,0,0,0,x},
    {R,0,0,0,x},
    {x,0,0,0,x},
    {x,x,x,x,x}},

    {{x,x,x,x,x},
    {x,0,0,0,x},
    {R,0,0,0,x},
    {x,0,0,0,x},
    {x,x,x,x,x}},

    {{x,x,x,x,x},
    {x,0,0,0,x},
    {R,0,0,0,x},
    {x,0,0,0,x},
    {x,x,x,x,x}},

    {{x,x,R,x,x},
    {x,0,0,0,x},
    {x,0,0,0,x},
    {x,0,0,0,x},
    {x,x,x,x,x}},

    {{x,x,R,x,x},
    {x,0,0,0,x},
    {x,0,0,0,x},
    {x,0,0,0,x},
    {x,x,x,x,x}},

    {{x,x,R,x,x},
    {x,0,0,0,x},
    {x,0,0,0,x},
    {x,0,0,0,x},
    {x,x,x,x,x}},

    {{x,x,x,x,x},
    {x,0,0,0,x},
    {x,0,0,0,R},
    {x,0,0,0,x},
    {x,x,x,x,x}},

    {{x,x,x,x,x},
    {x,0,0,0,x},
    {x,0,0,0,R},
    {x,0,0,0,x},
    {x,x,x,x,x}},

    {{x,x,x,x,x},
    {x,0,0,0,x},
    {x,0,0,0,R},
    {x,0,0,0,x},
    {x,x,x,x,x}},
};
int S_map[5][5]={
    {x,x,x,x,x},
    {x,1,0,0,x},
    {x,2,2,0,x},
    {x,2,0,1,x},
    {x,x,x,x,R}
};
int start_map[7][7]={
    {X,X,X,X,X,X,X},
    {X,X,X,X,X,X,X},
    {X,X,X,X,X,X,X},
    {X,X,X,X,X,X,X},
    {X,X,X,X,X,X,X},
    {X,X,X,X,X,X,X},
    {X,X,X,X,X,X,X},
};//

int move[50][2]={0};
int sdir[5]={0,-5,1,5,-1};
int sdir7[5]={0,-7,1,7,-1};
int sdir2[4]={-4,-6,4,6};
int ii=0;
int n_map=0;

void mapturn(void);
void mapcheck(void);
int mapcheck2(void);
int Xmap(void);//현재 맵이 x형태인지
void m_puck(void);//맵 모서리 퍽고정
void sort(void);
void R_move(void);
void M_sort(void);

int main(void)
{
    M_sort();

    return 0;
}
void mapturn(void)//배열을 돌리기 위한 함수
{
    for(int jj=0; jj<=6; jj+=3)
        for(int i=0; i<3; i++)
            for(int j=1; j<4; j++)
                for(int ii=1; ii<4; ii++)
                    C_map[i+3+jj][ii][4-j]=C_map[i+jj][j][ii];
}
void mapcheck(void)//맵 에 있는 퍽색갈에 따라 현재맵 값 반전을 위한함수
{
    int red=0,blue=0;
    for(int i=1; i<4; i++)
        for(int j=1; j<4; j++)
            if(S_map[i][j]==2)blue++;else if(S_map[i][j]==1)red++;
    if(red>blue)
        for(int z=0; z<12; z++)
            for(int i=1; i<4; i++)
                for(int j=1; j<4; j++)
                    C_map[z][i][j]=C_map[z][i][j]>0&&C_map[z][i][j]==1?2:C_map[z][i][j]==2?1:0;
}
int mapcheck2(void)
{
    int check[12]={0};
    for(int z=0; z<12; z++)
        for(int i=1; i<4; i++)
            for(int j=1; j<4; j++)
                if(C_map[z][i][j]==S_map[i][j]&&S_map[i][j]>0)check[i]++;
    int max=0;
    for(int i=0; i<12; i++)
        if(check[i]>check[max])
            max=i;
    return max;
}
int Xmap(void)
{
    if(S_map[1][1]>0&&S_map[3][3]>0&&S_map[1][3]>0&&S_map[3][1]&&S_map[2][2]>0)
    {
        return 1;
    }
    else if(S_map[1][1]<0&&S_map[3][3]<0&&S_map[1][3]<0&&S_map[3][1]&&S_map[2][2]<0)return 1;

    return 0;
}
void m_puck(void)
{
    S_map[1][1]*=-1;
    S_map[1][3]*=-1;
    S_map[3][1]*=-1;
    S_map[3][3]*=-1;
}

void sort(void)
{
    m_puck();
    int g_sum=0;
    fo(i,1,4)fo(j,1,4)if(S_map[i][j]<0)g_sum++;
    if(Xmap())return;
    int *puck;
    int check=0;
    fo(i,1,5)if(*(&S_map[2][2]+sdir[i])>0){puck=&S_map[2][2]+sdir[i];}
    fo(i,1,5)if(*(puck+sdir[i])==0&&(puck+sdir[i]==&S_map[1][1]||puck+sdir[i]==&S_map[1][3]||puck+sdir[i]==&S_map[3][1]||puck+sdir[i]==&S_map[3][3]))check=1;
    if(check==1){
        fo(i,1,5)if(*(puck+sdir[i])==0&&(puck+sdir[i]==&S_map[1][1]||puck+sdir[i]==&S_map[1][3]||puck+sdir[i]==&S_map[3][1]||puck+sdir[i]==&S_map[3][3])){
                if(puck+sdir[i]==&S_map[1][1]){
                    swap(*puck,S_map[1][1]);
                    move[ii][0]=&S_map[1][1];move[ii++][1]=i;
                }
                else if(puck+sdir[i]==&S_map[1][3]){
                    swap(*puck,S_map[1][3]);
                    move[ii][0]=&S_map[1][3];move[ii++][1]=i;
                }
                else if(puck+sdir[i]==&S_map[3][1]){
                    swap(*puck,S_map[3][1]);
                    move[ii][0]=&S_map[3][1];move[ii++][1]=i;
                }
                else if(puck+sdir[i]==&S_map[3][3]){
                    swap(*puck,S_map[3][3]);
                    move[ii][0]=&S_map[3][3];move[ii++][1]=i;
                }
        }
    }
    else{
        if(S_map[2][2]>0){
            if((S_map[1][1]==0||S_map[1][3]==0)){
                if(S_map[1][2]>0||S_map[3][2]==0){
                    if((S_map[1][1]==0 || S_map[3][1]==0)){
                        swap(S_map[2][2],S_map[2][1]);
                        move[ii][0]=&S_map[2][2];move[ii++][1]=4;
                    }
                    else if(S_map[2][1]==0){
                        swap(S_map[2][2],S_map[2][3]);
                        move[ii][0]=&S_map[2][2];move[ii++][1]=2;
                    }
                    else{
                        swap(S_map[2][2],S_map[1][2]);
                        move[ii][0]=&S_map[2][2];move[ii++][1]=1;
                    }
                }
                else if(S_map[3][2]==0){
                        swap(S_map[2][2], S_map[1][2]);
                        move[ii][0]=&S_map[2][2];move[ii++][1]=1;
                }
                else{
                    swap(S_map[2][2], S_map[2][1]);
                        move[ii][0]=&S_map[2][2];move[ii++][1]=4;
                }
            }

            else if(S_map[3][1]==0||S_map[3][3]==0){
                if(S_map[3][2]>0||S_map[1][2]==0){
                    if(S_map[1][1]==0||S_map[3][1]==0){
                        swap(S_map[2][2],S_map[2][1]);
                        move[ii][0]=&S_map[2][2];move[ii++][1]=4;
                    }
                    else if(S_map[2][1]==0){
                            swap(S_map[2][2],S_map[2][3]);
                            move[ii][0]=&S_map[2][2];move[ii++][1]=2;
                    }
                    else{
                            swap(S_map[2][2],S_map[3][2]);
                            move[ii][0]=&S_map[2][2];move[ii++][1]=3;
                    }
                }
                else if(S_map[1][2]==0){
                        swap(S_map[2][2], S_map[3][2]);
                        move[ii][0]=&S_map[2][2];move[ii++][1]=3;
                }
                else{
                    swap(S_map[2][2], S_map[2][3]);
                    move[ii][0]=&S_map[2][2];move[ii++][1]=2;
                }
            }
        }

        else{ // 시작
            for(int i=0; i<4; i++) // 고정하기
                if(*(&S_map[2][2]+sdir2[i])>0)
                    *(&S_map[2][2]+sdir2[i])*=-1; g_sum++;

            for(int m=0; m<4; m++){ // 퍽 옆으로 옮기기
                for(int i=1; i<4; i++)
                    for(int j=1; j<4; j++)
                        if(S_map[i][j]==1 || S_map[i][j]==2){
                            if(i==1 || i==3){
                                if(S_map[i][j+1]==0){
                                    *(&S_map[i][j]+sdir[2])=S_map[i][j]==1?1:2; S_map[i][j]=0;
                                    //printf("%d %d\n", i, j);
                                    move[ ii][0]=&S_map[i][j], move[ ii][1]=2,  ii++;
                                    i=6; j=6;
                                }
                                else if(S_map[i][j-1]==0){
                                    *(&S_map[i][j]+sdir[4])=S_map[i][j]==1?1:2; S_map[i][j]=0;
                                    //printf("%d %d\n", i, j);
                                    move[ ii][0]=&S_map[i][j], move[ ii][1]=4,  ii++;
                                    i=6; j=6;
                                }
                            }
                            else if(i==2){
                                if(S_map[i+1][j]==0){
                                    *(&S_map[i][j]+sdir[3])=S_map[i][j]==1?1:2; S_map[i][j]=0;
                                    //printf("%d %d\n", i, j);
                                    move[ ii][0]=&S_map[i][j], move[ ii][1]=3,  ii++;
                                    i=6; j=6;
                                }
                                else if(S_map[i-1][j]==0){
                                    *(&S_map[i][j]+sdir[1])=S_map[i][j]==1?1:2; S_map[i][j]=0;
                                   //printf("%d %d\n", i, j);
                                    move[ ii][0]=&S_map[i][j], move[ ii][1]=1,  ii++;
                                    i=6; j=6;
                                }
                                else
                                    //printf("test2 %d %d\n", i,j);
                                    i=6; j=6;
                            }
                        }
                for(int i=0; i<4; i++) // 고정하기
                    if(*(&S_map[2][2]+sdir2[i])>0)
                        *(&S_map[2][2]+sdir2[i])*=-1; g_sum++;
            }


            if(g_sum>=4){
                for(int i=0; i<5; i++){
                    if(*(&S_map[2][2]+sdir[i])==1 || *(&S_map[2][2]+sdir[i])==2){
                        if(i==1){
                            *(&S_map[1][2]+sdir[3])=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[1][2]=0; i=5;// 한칸 앞으로
                            move[ ii][0]=&S_map[1][2]; move[ ii][1]=3;  ii++;
                        }
                        else if(i==2){
                            *(&S_map[2][3]+sdir[4])=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[2][3]=0; i=5;
                            move[ ii][0]=&S_map[2][3]; move[ ii][1]=4;  ii++;
                        }
                        else if(i==3){
                            *(&S_map[3][2]+sdir[1])=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[3][2]=0; i=5;
                            move[ ii][0]=&S_map[3][2]; move[ ii][1]=1;  ii++;
                        }
                        else if(i==4){
                            *(&S_map[2][1]+sdir[2])=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[2][1]=0; i=5;
                            move[ ii][0]=&S_map[2][1]; move[ ii][1]=2;  ii++;
                        }
                    }
                }
            }
            else if(g_sum<4){
                for(int i=0; i<5; i++){
                    if(*(&S_map[2][2]+sdir[i])>0){
                        if(i==1){
                            S_map[3][2]=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[1][2]=0; i=5; // 두칸 앞으로
                            move[ ii][0]=&S_map[1][2]; move[ ii][1]=3,  ii++;
                            move[ ii][0]=&S_map[2][2]; move[ ii][1]=3,  ii++;

                            if(*(&S_map[3][2]+sdir[2])==0){
                                *(&S_map[3][2]+sdir[2])=S_map[3][2]==1?1:2; S_map[3][2]=0;
                                move[ ii][0]=&S_map[3][2]; move[ ii][1]=2;  ii++;
                            }
                            else{
                                *(&S_map[3][2]+sdir[4])=S_map[3][2]==1?1:2; S_map[3][2]=0;
                                move[ ii][0]=&S_map[3][2]; move[ ii][1]=4;  ii++;
                            }

                        }
                        else if(i==2){
                            S_map[2][1]=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[2][3]=0; i=5;
                            move[ ii][0]=&S_map[2][3]; move[ ii][1]=4;  ii++;
                            move[ ii][0]=&S_map[2][2]; move[ ii][1]=4;  ii++;

                            if(*(&S_map[2][1]+sdir[1])==0){
                                *(&S_map[2][1]+sdir[1])=S_map[2][1]==1?1:2; S_map[2][1]=0;
                                move[ ii][0]=&S_map[2][1]; move[ ii][1]=1;  ii++;
                            }
                            else{
                                *(&S_map[2][1]+sdir[3])=S_map[2][1]==1?1:2; S_map[2][1]=0;
                                move[ ii][0]=&S_map[2][1]; move[ ii][1]=3;  ii++;
                            }
                        }
                        else if(i==3){
                            S_map[1][2]=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[3][2]=0; i=5;
                            move[ ii][0]=&S_map[3][2]; move[ ii][1]=1;  ii++;
                            move[ ii][0]=&S_map[2][2]; move[ ii][1]=1;  ii++;

                            if(*(&S_map[1][2]+sdir[2])==0){ // 두칸 앞으로 간 퍽 옆으로 옮기기
                                *(&S_map[1][2]+sdir[2])=S_map[1][2]==1?1:2; S_map[1][2]=0;
                                move[ ii][0]=&S_map[1][2]; move[ ii][1]=2;  ii++;
                            }
                            else{
                                *(&S_map[1][2]+sdir[4])=S_map[1][2]==1?1:2; S_map[1][2]=0;
                                move[ ii][0]=&S_map[1][2]; move[ ii][1]=4;  ii++;
                            }
                        }
                        else if(i==4){
                            S_map[2][3]=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[2][1]=0; i=5;
                            move[ ii][0]=&S_map[2][1]; move[ ii][1]=2;  ii++;
                            move[ ii][0]=&S_map[2][2]; move[ ii][1]=2;  ii++;

                            if(*(&S_map[2][3]+sdir[1])==0){
                                *(&S_map[2][3]+sdir[1])=S_map[2][3]==1?1:2; S_map[2][3]=0;
                                move[ ii][0]=&S_map[2][3]; move[ ii][1]=1;  ii++;
                            }
                            else{
                                *(&S_map[2][3]+sdir[3])=S_map[2][3]==1?1:2; S_map[2][3]=0;
                                move[ ii][0]=&S_map[2][3]; move[ ii][1]=3;  ii++;
                            }

                        }
                    }
                }

                for(int i=0; i<4; i++) // 고정하기
                if(*(&S_map[2][2]+sdir2[i])==1 || *(&S_map[2][2]+sdir2[i])==2)
                    *(&S_map[2][2]+sdir2[i])*=-1; g_sum++;

                for(int i=0; i<5; i++){
                    if(*(&S_map[2][2]+sdir[i])==1 || *(&S_map[2][2]+sdir[i])==2){
                        if(i==1){
                            *(&S_map[1][2]+sdir[3])=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[1][2]=0; i=5;// 한칸 앞으로
                            move[ ii][0]=&S_map[1][2]; move[ ii][1]=3;  ii++;
                        }
                        else if(i==2){
                            *(&S_map[2][3]+sdir[4])=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[2][3]=0; i=5;
                            move[ ii][0]=&S_map[2][3]; move[ ii][1]=4;  ii++;
                        }
                        else if(i==3){
                            *(&S_map[3][2]+sdir[1])=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[3][2]=0; i=5;
                            move[ ii][0]=&S_map[3][2]; move[ ii][1]=1;  ii++;
                        }
                        else if(i==4){
                            *(&S_map[2][1]+sdir[2])=*(&S_map[2][2]+sdir[i])==1?1:2; S_map[2][1]=0; i=5;
                            move[ ii][0]=&S_map[2][1]; move[ ii][1]=2;  ii++;
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<4; i++) // 고정하기
                if(*(&S_map[2][2]+sdir2[i])==1 || *(&S_map[2][2]+sdir2[i])==2)
                    *(&S_map[2][2]+sdir2[i])*=-1; g_sum++;
    printf("-------------------------\n\n");
    fo(i,1,4)
    {
        fo(j,1,4)printf("%3d", S_map[i][j]);
        printf("\n\n");
    }
    getchar();getchar();
    if(Xmap())return;
    sort();
}
void R_move(void)
{
    int R_start = n_map+1/3;
    if(R_start==1)//돌리기전
    {

    }
    else if(R_start==2)//90돌린맵
    {

    }
    else if(R_start==3)//180돌린맵
    {

    }
    else if(R_start==4)//720돌린맵
    {

    }



}

void r_move(void)//로봇이 가야될 좌표를 계산 하는 용도
{
    for(int z=0; z<ii; z++)
    {
        fo(i,1,6){
            fo(j,1,6){
                if(S_map[i-1][j-1]==x&&*(&start_map[i][j]+((sdir7[move[z][1]]*-1)*i==3&&j==3?2:1))==x&& &S_map[i-1][j-1]==move[z][0])
                    *(&start_map[i][j]+((sdir7[move[z][1]]*-1)*i==3&&j==3?2:1))=r;return;
            }
        }
    }
}

void M_sort(void)//학교 소스에서 작동하기 위한 함수
{
    fo(i,1,6)fo(j,1,6)start_map[i][j]=S_map[i-1][j-1];
    fo(i,1,4)
    {
        fo(j,1,4)printf("%3d", S_map[i][j]);
        printf("\n\n");
    }
    printf("\n-------------------------\n\n");

    mapturn();
    mapcheck();
    m_puck();
    if(!Xmap())
        sort();

    fo(i,1,4)fo(j,1,4)if(S_map[i][j]<=0)S_map[i][j]*=-1;

    n_map=mapcheck2();

    fo(i,0,ii)printf("%d : %d\n", move[i][0],move[i][1]);

    fo(i,1,4)
    {
        fo(j,1,4)printf("%3d ", &S_map[i][j]);
        printf("\n\n");
    }
    //printf("%d", n_map);

    r_move();

    fo(i,1,6)
    {
        fo(j,1,6)printf("%3d ", start_map[i][j]);
        printf("\n\n");
    }
}
