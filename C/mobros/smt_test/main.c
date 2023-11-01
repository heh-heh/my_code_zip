#include <stdio.h>
#include <stdlib.h>

#define MR 5
#define MC 5
#define X -9
#define rr return
#define swap(x,y) temp=x; x=y; y=temp;

int main(void);
void move(int x1, int y1, int x2, int y2);
void move2(int x1, int y1, int x2, int y2);
void turn(int tu);

int path[50], mptr = 0, mptr2 = 0, quit = 0, quit2 = 0;
int sdir1[5] = { 0,-MC,1,MC,-1}; // �� ���� �� ��
int temp,sdir=0;
int now=9; // �κ� ��ġ

int map[5][5]={
    {X,X,X,X,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,0,0,0,X},
    {X,X,X,X,X}
};
int temp_map[5][5]={0,};

int main(){
    sdir=3;
    move(1,2,3,3);
    for(int i=0; i<10; i++){
        printf("%d ",path[i]);
    }
}

int smt(int n, int* dat){ // n�� ���۰� ������ 1, dat ���� �� ����
    int i, j, * p, dir;
    do {
        j = 0;
        for (i = MC; i < (MR - 1) * MC; i++) if (*(dat + i) == n){
            j++;
            for (dir = 1; dir < 5; dir++){
                p = (dat + i) + sdir1[dir];
                if (!*p)*p = n + 1;
                else if (*p == 999) {
                    if (!quit) quit = i + sdir1[dir];
                    if (quit && mptr == 0) quit2 = i; // ������-1
                    else if (quit && !quit2) quit2 = i + sdir1[dir]; // ������-1
                    path[mptr++] = dir;
                    *(dat + i) = 999;
                    rr 1;
                }
            }
        }
    } while (j && smt(n + 1, dat));
    rr 0;
}



void move(int x1, int y1, int x2, int y2){
    for(int i=0; i<5; i++){for(int j=0; j<5; j++){
        if(map[i][j])temp_map[i][j]=X;
        else{map[i][j]=temp_map[i][j];}
    }}
    temp_map[x1][y1]=1, temp_map[x2][y2]=999;

    smt(1,&temp_map[0][0]);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%3d ", temp_map[i][j]);
        }
        printf("\n\n");
    }

    // for(int i=mptr-1; i>=0; i--){
    //     if(i==0){
    //         for(int i=1; i<5; i++){
    //             if(*(&temp_map[x2][y2]+sdir1[i])!=(-9 || 999)){
    //                 if(i>sdir) st(1);
    //                 else if(i<sdir) st(2);
    //                 else st(3);
    //             }
    //         }
    //     }
    //     while(path[i]!=sdir){
    //         if(path[i]>sdir){
    //             turn(2); sdir++;
    //         }
    //         else if(path[i]<sdir){
    //             turn(1); sdir--;
    //         }
    //     }
    //     if(sdir>path[i-1]){
    //         st(2); sdir--;
    //     }
    //     else if(sdir<path[i-1]){
    //         st(1); sdir++;
    //     }
    //     else{
    //         st(3);
    //     }
    // }
}

void turn(int tu){ // 1�� ������ 2�� ����
    if(tu==1){
        //aa(0,0,-450,50);
    }
    else if(tu==2){
        //aa(0,0,450,50);
    }
}

void st(int stri){ // 1�� ������ 2�� ���� 3�� ����
    if(stri==1){

    }
    else if(stri==2){

    }
    else if(stri==3){

    }
}


