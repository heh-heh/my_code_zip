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
#define X  -9            // ��ֹ�
#define rr return

#define true 1
#define false 0

#define swap(m1, m2) temp=m1, m1=m2, m2=temp
#define goal(m1, m2) m1=1,m2=999,quit = quit2 = mptr = 0

//volatile int gyaw=0; //�޸𸮿� �׻� �����ϴ� ����


void sort(int loop, int index, int yy, int xx, int ey, int ex, int sdir);
int check(int sy, int sx, int ey, int ex);
void Move(int sy, int sx, int ey, int ex, int puck, int scan);
int smt(int n, int* dat);
void turn(int mpath2);
void update(void);
void Func(void);

int gg = 0, ggg = 0;

int Map[MR][MC] = {     // ���� ��ĵ�� ��
	{X,X,X,X,X},
	{X,2,3,0,X},
	{X,0,2,3,X},
	{X,0,1,1,X},
	{X,X,X,X,X}
};

int Sort_Map[MR][MC] = {    // �����ؾ� �� ��
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
};      // smt ������ ��
int random_Map[MR][MC] = {};
int copy_Map[MR][MC] = {};           // sort �Լ� ������ ��
int check_Map[MR][MC] = {};         // sort �Լ� ������ �̹� ���ĵ��ִ� ���� �� �����̰� �ϴ� ����


int path[50][2], mptr = 0, mptr2 = 0, quit = 0, quit2 = 0;
/*
    path : sort�Լ� ������ ���� �����̴� ��ǥ ����
    mptr : smt �Լ� �ȿ��� �̵��� �� �ִ� �� �Ÿ�(node)
    mptr2 : sort�Լ� �ȿ��� ���� �����̴� Ƚ��
    quit : smt�Լ����� 1���� ���� ������
    quit2 : smt �Լ����� 2���� ���� ������-1
*/
int mpath[50] = {};
/*
int sdir1[7] = { 0,1,-6,-4,6,4,-1 }; // ���� ������ ������ 6����
int sdir2[7] = { 0,3,8,2,4,6,7 };
*/

int sdir1[7] = { 0,-MR,1,MR, -1 }; // ���� ������ ������ 6����
int sdir2[7] = { 0,1,2,3,4};

int pos[2]; //���� �κ� ��ǥ
int dir = 0;
int clearr = 0;                                                                  // sort�Լ� Ż�� ����
int color[3];
int ptr[3] = { 1,5,3 }, temp;
int CL=0;
int hole[3] = { 6,12,17 }; //��������ϴ°�3��

//int pp[3][2]={0,};//b���� �� ����
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
1. #define set(n) >> acc[n] = 80 ���� acc�� ������ ���氡��
2. #define qq()
3. ���� �̸�(barcode, barcodeCnt, enable) ����
4. cc�߰�
5. �Լ��� distr �߰� >>������� ���������� lcd�� �˼��ֽ��ϴ�
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







int smt(int n, int* dat) {  // smt�� ���ڷ� �ٽ� ���� ��
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
                    if (quit && mptr/*++*/== 0) quit2 = i; // ������-1
                    else if (quit && !quit2) quit2 = i + sdir1[dir]; // ������-1
                    *(dat + i) = 999;

					mpath[mptr++]=dir;

					rr 1;
                }
            }
        }
    } while (j && smt(n + 1, dat));
    rr 0;
}

void update(void) { // ���� ���� copy_Map�� update ���ִ� �Լ�
    for (int y = 0; y < MR; y++) for (int x = 0; x < MC; x++) copy_Map[y][x] = Map[y][x];
    //copy_Map[3][3] = X; // �� �߾��� X ����� smt���� ���� ã�� �� �ùٸ��� ã�� ������ ������ �߾����� �κ��� �̵���
    mptr2 = clear1 = false;  // update�� �� ó�� ���ִ� �뵵�� sort�Լ� ������ sort�Լ����� ����� ������ �ʱ�ȭ
}
void copyy(void) {  // copyy�Լ��� ���� �ű�� �Լ��� �ȸ��� �ӽ÷� sort�Լ� ������ ���ĵ� ���� ���� �ʿ� �־���
    //copy_Map[3][3] = Map[3][3];
    for (int y = 1; y < MR - 1; y++) for (int x = 1; x < MC - 1; x++) Map[y][x] = copy_Map[y][x];
}
int check(int sy, int sx, int ey, int ex) {

    for (int y = 1; y < MR - 1; y++) for (int x = 1; x < MC - 1; x++) {
        if (copy_Map[y][x]) smt_Map[y][x] = X;  // ���� ������ ��ֹ� ó��( X )
        else smt_Map[y][x] = 0; // ���� ������ 0
    }   // ���� ������ smt ������ ���� ���� ����

    smt_Map[sy][sx] = 1;    // start
    smt_Map[ey][ex] = 999;  // end
    quit = quit2 = mptr = 0;    // smt ������ ����ϴ� ���� �ʱ�ȭ
    return smt(1, &smt_Map[0][0]);   // start �������� end �������� �κ��� �̵��� �� �ִٸ� true ���ϸ� false
}

void sort(int loop, int index, int yy, int xx, int ey, int ex, int sdir) {
	//yy==���� �κ� y��ǥ
	//xx==���� �κ� x��ǥ
	//ey==1
	//ex==1,5,3 ������ ��
	//check 2��for������ ����ü�� ���鼭 copy�ʿ� ����������
	//		smt�ʿ� ��ֹ�ó�� �ƴϸ� smt�ʿ� 0
	// 		�׷��� ���� ������ǥ���� ����ǥ�� smt
    int temp = 0;   // swap �Ҷ� ����� ����
    if(index > loop) rr;    // ���ѷ��� ����
    if (copy_Map[ey][ex] == Sort_Map[ey][ex]) rr; // ���� ó�� �������� �� �̹� ������ ���ִ� �����̸� rr

    for (int y = 1;y < MR - 1;y++) for (int x = 1;x < MC-1;x++) {
        if (copy_Map[y][x] > 0 && check_Map[y][x]!=X && (y*MR+x!=sdir)) {   // ���� for�� ������ ��ǥ�� ���� �ְ� && ���� �������� �ǰ� && ���� ��ǥ�� �ƴ� ��
            if (check(yy, xx, y, x)) {  // ���� �κ� ��ġ���� ���� �ִ� ������ smt
                for (int yyy = 1;yyy < MR - 1;yyy++) for (int xxx = 1;xxx < MC - 1;xxx++) {
                    if (copy_Map[yyy][xxx] == 0) {  // ���� �ʿ� �� ���� ( 0 ) �� ã�Ƽ�
                        if (check(y, x, yyy, xxx)) {    // ���� �� �� �ִ� �� ��ġ���� �� �������� �ű� �� �ִ��� ( robot -> puck -> ����� )
                            swap(copy_Map[y][x], copy_Map[yyy][xxx]);   // �ű� �� ������ �� �̶� �� ���� ����
                            path[mptr2][0] = y * MR + x;    // ���� �ִ� ��ġ( 1���� �� )
                            path[mptr2][1] = yyy * MR + xxx; // ������� �ִ� ��ġ ( 1���� �� )
                            mptr2++;
                            // ���� path �迭�� Ȱ�� �ؼ� path[ �ݺ� ][0] / MR  path[ �ݺ� ][0] % MC �ϸ� ���� �������� �� ���� 2���� ���� ����
                            //�Űܾ� �� ��ġ�� path[ �ݺ� ][ 1 ] �ؼ� ������ ��
                            if (copy_Map[ey][ex] == Sort_Map[ey][ex]) { // ���� ������ ��ٸ�
                                clearr = 1;   // �Լ� Ż��
                                //copyy();            // Move �Լ� ���۽� ����
                                rr;     // �Լ� Ż��
                            }
                            sort(loop, index + 1, quit2/MR, quit2%MC, ey, ex, yyy * MR + xxx); //������ �ȉ�ٸ� ��� ȣ��
                            if (clearr) rr;  // ������ ��ٸ� Ż��
                            swap(copy_Map[y][x], copy_Map[yyy][xxx]); // ������ �ȉ�ٸ� �ٽ� ������� �ٲ���
                            mptr2--;    // �Լ��� �������Ա⿡ ������ Ƚ���� �ٿ���
                        }
                    }
                }
            }
        }
    }
}

void Func(void) {
    int ptr[3] = { 1,2,3 }, temp;

    for (int k = 0;k < 3;k++) { // �� ù�� ° ��
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
            Move(pos[0], pos[1], path[i][0]/MR, path[i][0]%MC, 0,0); // �� ���
            Move(pos[0], pos[1], path[i][1]/MR, path[i][1]%MC, 1,0); // �� ������
            //lcd(3,0,"%02d %02d %02d %02d",path[i][0]/MR,path[i][0]%MC,path[i][1]/MR,path[i][1]%MC);
			//beep(1,100);
			//swap(Map[path[i][0] / MR][path[i][0] % MC], Map[path[i][1] / MR][path[i][1] % MC]);
		}
        check_Map[1][ptr[k]] = X; // ���� ������ ���� ���ĺ��ʹ� ���� �ű�� �ȵ�

	}
	/*
    for (int k = 2;k < 5;k += 2) {  // 3��° ���� �����ؾ� �Ұ��� 2��° ���� ������ �ֳ��ϸ� ���� �˰��� ������ ������ �ȵǱ� ������ ���� �ȵǴ� �κ��� �������� �ϱ� ����
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

    for (int k = 0;k < 3;k++) { // 5��° �� ����
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




void turn(int i) { // i=�����ϴ� ���� dir=���� ���� ����
    dir=i;
}

void Move(int sy, int sx, int ey, int ex, int puck, int scan) {//puck�Ű������� ���̸� �������� �ܹ����� ----  ��ĵ �Ű������� ���̸� Move�� 1 �ֱ�
    int now = sy * MC + sx;
    //int spd = 600;
    //int a = 0, temp;
    //int temp;

	//check(sy,sx,ey,ex);

    for (int y = 1;y < MR-1;y++) for (int x = 1;x < MC-1;x++) { // ���� ���� �������� smt �� ����
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

    pos[0] = now / MR; // ���� ��ġ ������Ʈ // y ��ǥ
    pos[1] = now % MC; // x ��ǥ


}
