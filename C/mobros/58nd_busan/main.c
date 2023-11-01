#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#define rr return

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
    {X,0,X,0,X},
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


int path[50][2], mptr = 0, mptr2 = 0, quit = 0, quit2 = 0;
int sdir1[5] = { 0,MC,1,-MC,1}; // 상하 제외한 나머지 6방향
int pos[2]; // 현재 로봇 좌표
bool clear = 0; // sort함수 탈출 조건



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

void update(void) { // 현재 맵을 copy_Map에 update 해주는 함수
    for (int y = 0;y < MR;y++) for (int x = 0;x < MC;x++) copy_Map[y][x] = Map[y][x];
    copy_Map[3][3] = X; // 맨 중앙을 X 해줘야 smt에서 길을 찾을 때 올바르게 찾음 해주지 않으면 중앙으로 로봇이 이동함
    mptr2 = clear = false;  // update가 맨 처음 해주는 용도라서 sort함수 끝나고 sort함수에서 사용한 변수들 초기화 
}
void copyy(void) {  // copyy함수는 퍽을 옮기는 함수를 안만들어서 임시로 sort함수 끝나고 정렬된 맵을 현재 맵에 넣어줌
    copy_Map[3][3] = Map[3][3]; 
    for (int y = 1;y < MR - 1;y++) for (int x = 1;x < MC - 1;x++) Map[y][x] = copy_Map[y][x];
}
/*
    자기가 원하는 맵을 출력
    사용방법

    1. 배열 이름만 넣어주면 됨
    print(copy_Map);
    print(Map);
    print(smt_Map);

    로봇에서 출력할 땐 display창 부족해서 함수 수정해서 사용바람
*/
void print(int dat[MR][MC]) {
    for (int y = 1;y < MR - 1;y++,puts("")) for (int x = 1;x < MC - 1;x++) {
        if (dat[y][x] == X) printf("X ");   // X가 -9라서 -9가 출력되기에 X로 출력해주기 위함
        else printf("%d ", dat[y][x]);
    }puts("");  // printf("\n") 동일
}
/*
    sy : start y pos
    sx : start x pos
    ey : end y pos
    ex : end x pos

    (sy,sx) 에서 출발해서 (ey,ex)로 로봇이 이동할 수 있는지 체크
*/
bool check(int sy, int sx, int ey, int ex) {
    for (int y = 1;y < MR - 1;y++) for (int x = 1;x < MC - 1;x++) {
        if (copy_Map[y][x]) smt_Map[y][x] = X;  // 퍽이 있으면 장애물 처리( X )
        else smt_Map[y][x] = 0; // 퍽이 없으면 0
    }   // 조건 보기전 smt 돌리는 맵을 셋팅 해줌

    smt_Map[sy][sx] = 1;    // start
    smt_Map[ey][ex] = 999;  // end
    quit = quit2 = mptr = 0;    // smt 돌릴때 사용하는 변수 초기화
    return smt(1, &smt_Map[0][0]);   // start 지점에서 end 지점으로 로봇이 이동할 수 있다면 true 못하면 false
}
void sort(int loop, int index, int yy, int xx, int ey, int ex, int sdir) {
    int temp = 0;   // swap 할때 사용할 변수
    if(index > loop) rr;    // 무한루프 방지
    if (copy_Map[ey][ex] == Sort_Map[ey][ex]) rr; // 만약 처음 시작했을 때 이미 정렬이 되있는 상태이면 rr

    for (int y = 1;y < MR - 1;y++) for (int x = 1;x < MC-1;x++) {
        if (copy_Map[y][x] > 0 && check_Map[y][x]!=X && (y*MR+x!=sdir)) {   // 현재 for문 돌리는 좌표에 퍽이 있고 && 퍽을 움직여도 되고 && 이전 좌표가 아닐 때
            if (check(yy, xx, y, x)) {  // 현재 로봇 위치에서 퍽이 있는 곳으로 smt
                for (int yyy = 1;yyy < MR - 1;yyy++) for (int xxx = 1;xxx < MC - 1;xxx++) {
                    if (copy_Map[yyy][xxx] == 0) {  // 현재 맵에 빈 공간 ( 0 ) 을 찾아서
                        if (check(y, x, yyy, xxx)) {    // 움직 일 수 있는 퍽 위치에서 빈 공간으로 옮길 수 있는지 ( robot -> puck -> 빈공간 )
                            swap(copy_Map[y][x], copy_Map[yyy][xxx]);   // 옮길 수 있으면 퍽 이랑 빈 공간 스왑
                            path[mptr2][0] = y * MR + x;    // 퍽이 있던 위치( 1차원 값 )
                            path[mptr2++][1] = yyy * MR + xxx; // 빈공간이 있던 위치 ( 1차원 값 ) 
                            // 위의 path 배열을 활용 해서 path[ 반복 ][0] / MR  path[ 반복 ][0] % MC 하면 내가 움직여야 할 퍽의 2차원 값이 나옴
                            //옮겨야 될 위치도 path[ 반복 ][ 1 ] 해서 돌리면 됨
                            if (copy_Map[ey][ex] == Sort_Map[ey][ex]) { // 만약 정렬이 됬다면
                                clear = true;   // 함수 탈출
                                copyy();            // Move 함수 제작시 삭제
                                pos[0] = quit2/MR;  // 현재 로봇 y 좌표 업데이트
                                pos[1] = quit2%MC;  // 현재 로봇 x 좌표 업데이트
                                rr;     // 함수 탈출
                            }
                            sort(loop, index + 1, quit2/MR, quit2%MC, ey, ex, yyy * MR + xxx); //정렬이 안됬다면 재귀 호출
                            if (clear) rr;  // 정렬이 됬다면 탈출
                            swap(copy_Map[y][x], copy_Map[yyy][xxx]); // 정렬이 안됬다면 다시 원래대로 바꿔줌
                            mptr2--;    // 함수를 빠져나왔기에 움직일 횟수도 줄여줌
                        }
                    }
                }
            }
        }
    }
}
bool sc(void) {
    for (int y = 1;y < MR - 1;y++) {
        if (y == 3) continue;
        for (int x = 1;x < MC - 1;x++) {
            if (Sort_Map[y][x] != Map[y][x]) rr false;
        }
    }
    rr true;
}
int main(void) {
    
}