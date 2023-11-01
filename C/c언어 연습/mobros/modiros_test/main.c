#include <stdio.h>
#include <math.h>
#include <time.h>

#define rr return
#define X 99
#define MC 7
#define MR 7

int sdir[5]={0,-MC,1,MC,-1};
int mptr=0;
int *p;
int path[50],quit = 0, quit2 = 0; 
int map[7][7]={
    {X,X,X,X,X,X,X},
    {X,0,0,0,0,1,X},
    {X,0,1,1,2,1,X},
    {X,0,3,2,0,1,X},
    {X,0,1,2,0,3,X},
    {X,0,3,3,1,3,X},
    {X,X,X,X,X,X,X}
};
/*

  0  1  2  3  4  5  6

  7  8  9 10 11 12 13

 14 15 16 17 18 19 20

 21 22 23 24 25 26 27

 28 29 30 31 32 33 34

 35 36 37 38 39 40 41

 42 43 44 45 46 47 48
*/
int smt_map[7][7]={0,};


void print(void);
void smt(int *s, int *e);
void smt_set(int s, int e);
int main(void){
    for(int i=0; i<MC; i++) for(int j=0; j<MR; j++)smt_map[i][j]=map[i][j];
    smt_set(8,40);
    smt(&smt_map[1][1],&smt_map[5][5]);
    print();
    p=&smt_map[0][0];
    return 0;
}
void print(void){
    for(int i=0; i<MC; i++){
        for(int j=0; j<MR; j++){
            printf("%3d", smt_map[i][j]);
        }
        printf("\n\n");
    }
}
/*
    s : 시작 좌표
    e : 갈좌표
    dir : 로봇 시작 방향
*/
void smt(int *s, int *e){
    for(int d=1; d<5; d++){
        if(*(e+sdir[d])==-1&&*(e+sdir[d])!=X){
            *(e+sdir[d])=++mptr;
        }
    }
}
void smt_set(int s, int e){
    //for(int i=0; i<MC; i++) for(int j=0; j<MR; j++) if(smt_map[i][j]==0)smt_map[i][j]=-1;
    *(p+s) = -1; *(p+e) = 88;
}
