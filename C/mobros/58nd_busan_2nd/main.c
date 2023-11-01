#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#define rr return
#define R 9 // 로봇
#define X -9 //장애물 or 벽
#define MR 6
#define MC 5

#define swap(x,y) temp=x; x=y; y=temp; 
/*
    *map : 맵 배열
    arr_x : x최대 좌표 값
    arr_y : y최대 좌표 값
    
*/

int n_dir = 0, r_now=23;
int sdir[5] = { 0,-MC,1,MC,-1 };
/*
    방향 포인터 기준

    0 : 현재 위치 
    1 : 위
    2 : 우
    3 : 하
    4 : 좌
*/


int Map[6][5] = {
    {X,X,X,X,X},
    {X,1,0,2,X},
    {X,3,0,0,X},
    {X,2,X,1,X},
    {X,0,0,3,X},
    {X,X,X,X,X}
};
int smt_Map[6][5] = {
    {X,X,X,X,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,X,X,X,X}
};
int Sort_Map[6][5] = {
    {X,X,X,X,X},
    {X,3,0,1,X},
    {X,2,0,2,X},
    {X,1,X,3,X},
    {X,0,0,0,X},
    {X,X,X,X,X}
};
int copy_Map[MR][MC] = {};           // sort 함수 돌리는 맵
int check_Map[MR][MC] = {};         // sort 함수 돌리고 이미 정렬되있는 퍽을 못 움직이게 하는 조건

int a_arry[3] = {1,2,3}; // 정렬 순서
int path[50][2], mptr = 0, mptr2 = 0, quit = 0, quit2 = 0;
int sdir1[5] = { 0,MC,1,-MC,1}; // 상하 제외한 나머지 6방향
int pos[2]; // 현재 로봇 좌표
bool clear = 0; // sort함수 탈출 조건

int in(int *arr, int ck){
    int ii=0;
    while(ii<MR*MC)
        if(*(arr+ii) == ck) return 1; ii++;
    return 0;
}


int smt(int n, int* dat) {  // smt는 디코로 다시 설명 함
    int i, j, * p, dir;
    do {
        j = 0;
        for (i = MC; i < (MR - 1) * MC; i++) if (*(dat + i) == n) {
            j++;
            for (dir = 1; dir < 5; dir++) {
                p = (dat + i) + sdir1[dir];
                if (!*p)*p = n + 1;
                else if (*p == 999) {
                    if (!quit) quit = i + sdir1[dir];
                    if (quit && mptr++ == 0) quit2 = i; // 도착지-1
                    else if (quit && !quit2) quit2 = i + sdir1[dir]; // 도착지-1
                    *(dat + i) = 999;
                    rr 1;
                }
            }
        }
    } while (j && smt(n + 1, dat));
    rr 0;
}

void print(int *arr, int arr_y, int arr_x){
    for(int ii=0; ii<arr_y*arr_x; ii++){
        if((ii)%arr_x == 0)printf("\n\n");
        printf("%3d ", *(arr+ii));
    }
}

void scan(int *arry, int r_dir, int sp){
    int sc_ck_arr[MR][MC] = {
        {X,X,X,X,X},
        {X,0,0,0,X},
        {X,0,0,0,X},
        {X,0,0,0,X},
        {X,0,0,0,X},
        {X,X,X,X,X}
    };// 스캔한곳 체크용

    while(in(&sc_ck_arr[0][0],0)){
        for(int i=1; i<5; i++){
            if(*(arry+sp+sdir1[i])!=X){
                
            }
        }
    }
    
}

int main(void) {
    print(&Map[0][0], MR, MC);

    printf("%d", in(&smt_Map[0][0],1 ));
    //scan(&smt_Map[0][0], 1, 23);
}


