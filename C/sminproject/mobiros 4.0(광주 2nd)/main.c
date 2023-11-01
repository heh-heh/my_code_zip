/************************************************************************************************************/
/*                                                                                                          */
/*                                              MobileRobot.c                                               */
/*                                                                                                          */
/*                                                                                       2020. 1. 1.        */
/************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MR 5            // y
#define MC 5            // x
#define X  -9            // 장애물
#define rr return

#define true 1
#define false 0

#define swap(m1, m2) temp=m1, m1=m2, m2=temp
#define goal(m1, m2) m1=1,m2=999,quit = quit2 = mptr = 0

//volatile int gyaw=0; //메모리에 항상 접근하는 변수


void sort(int loop, int index, int yy, int xx, int ey, int ex, int sdir);
int check(int sy, int sx, int ey, int ex);
void Move(int sy, int sx, int ey, int ex, int puck, int scan);
int smt(int n, int* dat);
void turn(int mpath2);
void update(void);
void Func(void);

int gg = 0, ggg = 0;

int Map[MR][MC] = {     // 현재 스캔한 맵
	{X,X,X,X,X},
	{X,2,3,0,X},
	{X,0,2,3,X},
	{X,0,1,1,X},
	{X,X,X,X,X}
};

int Sort_Map[MR][MC] = {    // 정렬해야 할 맵
    {X,X,X,X,X},
	{X,1,0,1,X},
	{X,2,0,2,X},
	{X,3,0,3,X},
	{X,X,X,X,X}
};
int smt_Map[MR][MC] = {
    {X,X,X,X,X},
	{X,0,0,0,X},
	{X,0,0,0,X},
	{X,0,0,0,X},
	{X,X,X,X,X}
};      // smt 돌리는 맵
int random_Map[MR][MC] = {};
int copy_Map[MR][MC] = {};           // sort 함수 돌리는 맵
int check_Map[MR][MC] = {};         // sort 함수 돌리고 이미 정렬되있는 퍽을 못 움직이게 하는 조건


int path[50][2], mptr = 0, mptr2 = 0, quit = 0, quit2 = 0;
/*
    path : sort함수 돌리고 퍽을 움직이는 좌표 저장
    mptr : smt 함수 안에서 이동할 수 있는 총 거리(node)
    mptr2 : sort함수 안에서 퍽을 움직이는 횟수
    quit : smt함수에서 1차원 값인 도착지
    quit2 : smt 함수에서 2차원 값인 도착지-1
*/
int mpath[50] = {};
/*
int sdir1[7] = { 0,1,-6,-4,6,4,-1 }; // 상하 제외한 나머지 6방향
int sdir2[7] = { 0,3,8,2,4,6,7 };
*/

int sdir1[7] = { 0,-MR,1,MR, -1 }; // 상하 제외한 나머지 6방향
int sdir2[7] = { 0,1,2,3,4};

int pos[2]; //현재 로봇 좌표
int dir = 0;
int clearr = 0;                                                                  // sort함수 탈출 조건
int color[3];
int ptr[3] = { 1,5,3 }, temp;
int CL=0;
int hole[3] = { 6,12,17 }; //비워놔야하는곳3곳

//int pp[3][2]={0,};//b구역 퍽 색깔
int ppp;
int modd;
int clear1 = 0;

#define cdy 130
#define cdx 80

#define qq(a,x,y,w,s) TD(a,x,y,w,s,!(x||y)?s:0,0)
#define c56 CC(5,6,230,2)
#define c53 CC(5,3,230,2)
#define c50 CC(5,0,0,2)
#define c85 CC(8,5,230,2)
#define c14 CC(1,4,230,2)

#define set(n) acc[n]=80;
#define	cls lcd(0,18,"  ")
/****************************************************************************************/
/*
1. #define set(n) >> acc[n] = 80 으로 acc를 빠르게 변경가능
2. #define qq()
3. 변수 이름(barcode, barcodeCnt, enable) 수정
4. cc추가
5. 함수안 distr 추가 >>어떤동작을 수행중인지 lcd로 알수있습니다
6. display => string

*/
/****************************************************************************************/

int main(void){
    for(int i=0; i<5;i++) for(int j=0; j<5; j++)copy_Map[i][j]=Map[i][j];

    for(int i=0; i<5;i++){
        for(int j=0; j<5; j++){
            printf("%3d ", Map[i][j]);
        }
        printf("\n\n");
    }

    dir=1;
    pos[0]=1;
    pos[1]=3;
    Func();
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
                    if (quit && mptr/*++*/== 0) quit2 = i; // 도착지-1
                    else if (quit && !quit2) quit2 = i + sdir1[dir]; // 도착지-1
                    *(dat + i) = 999;

					mpath[mptr++]=dir;

					rr 1;
                }
            }
        }
    } while (j && smt(n + 1, dat));
    rr 0;
}

void update(void) { // 현재 맵을 copy_Map에 update 해주는 함수
    for (int y = 0; y < MR; y++) for (int x = 0; x < MC; x++) copy_Map[y][x] = Map[y][x];
    //copy_Map[3][3] = X; // 맨 중앙을 X 해줘야 smt에서 길을 찾을 때 올바르게 찾음 해주지 않으면 중앙으로 로봇이 이동함
    mptr2 = clear1 = false;  // update가 맨 처음 해주는 용도라서 sort함수 끝나고 sort함수에서 사용한 변수들 초기화
}
void copyy(void) {  // copyy함수는 퍽을 옮기는 함수를 안만들어서 임시로 sort함수 끝나고 정렬된 맵을 현재 맵에 넣어줌
    //copy_Map[3][3] = Map[3][3];
    for (int y = 1; y < MR - 1; y++) for (int x = 1; x < MC - 1; x++) Map[y][x] = copy_Map[y][x];
}
int check(int sy, int sx, int ey, int ex) {

    for (int y = 1; y < MR - 1; y++) for (int x = 1; x < MC - 1; x++) {
        if (copy_Map[y][x]) smt_Map[y][x] = X;  // 퍽이 있으면 장애물 처리( X )
        else smt_Map[y][x] = 0; // 퍽이 없으면 0
    }   // 조건 보기전 smt 돌리는 맵을 셋팅 해줌

    smt_Map[sy][sx] = 1;    // start
    smt_Map[ey][ex] = 999;  // end
    quit = quit2 = mptr = 0;    // smt 돌릴때 사용하는 변수 초기화
    return smt(1, &smt_Map[0][0]);   // start 지점에서 end 지점으로 로봇이 이동할 수 있다면 true 못하면 false
}

void sort(int loop, int index, int yy, int xx, int ey, int ex, int sdir) {
	//yy==현재 로봇 y좌표
	//xx==현재 로봇 x좌표
	//ey==1
	//ex==1,5,3 순서로 들어감
	//check 2중for문은로 맵전체를 보면서 copy맵에 값이있으면
	//		smt맵에 장애물처리 아니면 smt맵에 0
	// 		그러고 난후 시작좌표에서 끝좌표를 smt
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
                            path[mptr2][1] = yyy * MR + xxx; // 빈공간이 있던 위치 ( 1차원 값 )
                            mptr2++;
                            // 위의 path 배열을 활용 해서 path[ 반복 ][0] / MR  path[ 반복 ][0] % MC 하면 내가 움직여야 할 퍽의 2차원 값이 나옴
                            //옮겨야 될 위치도 path[ 반복 ][ 1 ] 해서 돌리면 됨
                            if (copy_Map[ey][ex] == Sort_Map[ey][ex]) { // 만약 정렬이 됬다면
                                clearr = 1;   // 함수 탈출
                                //copyy();            // Move 함수 제작시 삭제
                                rr;     // 함수 탈출
                            }
                            sort(loop, index + 1, quit2/MR, quit2%MC, ey, ex, yyy * MR + xxx); //정렬이 안됬다면 재귀 호출
                            if (clearr) rr;  // 정렬이 됬다면 탈출
                            swap(copy_Map[y][x], copy_Map[yyy][xxx]); // 정렬이 안됬다면 다시 원래대로 바꿔줌
                            mptr2--;    // 함수를 빠져나왔기에 움직일 횟수도 줄여줌
                        }
                    }
                }
            }
        }
    }
}

void Func(void) {
    int ptr[3] = { 1,2,3 }, temp;

    for (int k = 0;k < 3;k++) { // 맨 첫번 째 열
        update();
		//copyy();


        for (int i = 1;i <= 30;i++) {
            if (clearr) {
				break;
			}
            sort(i, 0, pos[0], pos[1], 1, ptr[k], 999);
        }
		//++
        for (int i = 0;i < mptr2;i++) { // Move
            Move(pos[0], pos[1], path[i][0]/MR, path[i][0]%MC, 0,0); // 퍽 잡고
            Move(pos[0], pos[1], path[i][1]/MR, path[i][1]%MC, 1,0); // 퍽 버리기
            //lcd(3,0,"%02d %02d %02d %02d",path[i][0]/MR,path[i][0]%MC,path[i][1]/MR,path[i][1]%MC);
			//beep(1,100);
			//swap(Map[path[i][0] / MR][path[i][0] % MC], Map[path[i][1] / MR][path[i][1] % MC]);
		}
        check_Map[1][ptr[k]] = X; // 정렬 했으니 다음 정렬부터는 퍽을 옮기면 안됨

	}
	/*
    for (int k = 2;k < 5;k += 2) {  // 3번째 열에 정렬해야 할것을 2번째 열에 정렬함 왜냐하면 지금 알고리즘 상으론 정렬이 안되기 때문에 정렬 안되는 부분을 수동으로 하기 위함
        update();
        for (int i = 1;i <= 30;i++) {
            if (clearr) break;
            sort(i, 0, pos[0], pos[1], 2, k, 999);
        }
        for (int i = 0;i < mptr2;i++) { // Move
            Move(pos[0], pos[1], path[i][0] / MR, path[i][0] % MC, 0,0);
            Move(pos[0], pos[1], path[i][1] / MR, path[i][1] % MC, 1,0);
            swap(Map[path[i][0] / MR][path[i][0] % MC], Map[path[i][1] / MR][path[i][1] % MC]);
        }
        check_Map[2][k] = X;
    }

    for (int k = 0;k < 3;k++) { // 5번째 열 정렬
        update();
        for (int i = 1;i <= 30;i++) {
            if (clearr) break;
            sort(i, 0, pos[0], pos[1], 5, ptr[k], 999);
        }
        for (int i = 0;i < mptr2;i++) { // Move
            Move(pos[0], pos[1], path[i][0] / MR, path[i][0] % MC, 0,0);
            Move(pos[0], pos[1], path[i][1] / MR, path[i][1] % MC, 1,0);
            swap(Map[path[i][0] / MR][path[i][0] % MC], Map[path[i][1] / MR][path[i][1] % MC]);
        }
        check_Map[5][ptr[k]] = X;
    }
	*/
}


int sc(void) {
    for (int y = 1; y < MR; y++) {
        //if (y == 3) continue;
        for (int x = 1; x < MC; x++) {
            if (Sort_Map[y][x] != Map[y][x]) rr false;
        }
    }
    rr true;
}




void turn(int i) { // i=가야하는 방향 dir=내가 보는 방향
    dir=i;
}

void Move(int sy, int sx, int ey, int ex, int puck, int scan) {//puck매개변수가 참이면 도착지에 퍽버리기 ----  스캔 매개변수가 참이면 Move에 1 넣기
    int now = sy * MC + sx;
    //int spd = 600;
    //int a = 0, temp;
    //int temp;

	//check(sy,sx,ey,ex);

    for (int y = 1;y < MR-1;y++) for (int x = 1;x < MC-1;x++) { // 현재 맵을 기준으로 smt 맵 셋팅
        if (Map[y][x]==X) smt_Map[y][x] = X;
        else smt_Map[y][x] = 0;
    }

	//smt_Map[3][3]=X;
    goal(smt_Map[sy][sx], smt_Map[ey][ex]);
	smt(1, &smt_Map[0][0]);
    printf("%d %d : ",now / MR,now % MC);
    for (int i = mptr - 1;i >= 0;i--) {
        printf("%d ", mpath[i]);
        now=now+sdir1[mpath[i]];
    }
    printf("\n");

    pos[0] = now / MR; // 현재 위치 업데이트 // y 좌표
    pos[1] = now % MC; // x 좌표


}
