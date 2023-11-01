#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




int path[50], mptr = 0, mptr2 = 0, quit = 0;
int sdir1[5] = { 0,0,1,0,-1}; // 앞 오른 뒤 왼
int temp,sdir=0;

int sol(const char* maps[], size_t maps_len);
int smt(int n, int* dat, int arr_size);

int m_map[102][102]={{-9,},};

int main(void){
    for(int ii=0; ii<102; ii++) for(int jj=0; jj<102; jj++) m_map[ii][jj]=-9;

    char txt[1000]={" "};
    long long int map_len=0;
    scanf("%s", txt);
    scanf("%lld", &map_len);
    char txt2[100][100];
    for(int i=0; i<map_len; i++){
        for(int j=0; j<map_len; j++){
            
        }
    }

    sol(&txt2[0][0] , map_len);
}

int sol(const char* maps[], size_t maps_len){
    
    int map_c =0;
    // for(int ii=1; ii<=maps_len; ii++){
    //     for(int jj=1; jj<=maps_len; jj++){
    //         if( *(maps+map_c)=='S') m_map[ii][jj]=1;
    //         else if( *(maps+map_c)=='E') m_map[ii][jj]=999;
    //         else if(*(maps+map_c)=='X') m_map[ii][jj]=-9;
    //         else m_map[ii][jj]=0;
    //         map_c++;
    //     }5
    // }
    
    // for(int ii=0; ii<=maps_len+1; ii++){ for(int jj=0; jj<=maps_len+1; jj++)printf("%4d", m_map[ii][jj]); printf("\n\n");}
    for(int i=0; i<25; i+=1) printf("%c", maps[i]);
    getchar();
    getchar();

}







int smt(int n, int* dat, int arr_size) {  // smt는 디코로 다시 설명 함
    int i, j, * p, dir;
    do {
        j = 0;
        for (i = arr_size; i < (arr_size - 1) * arr_size; i++) if (*(dat + i) == n) {
            j++;
            for (dir = 1; dir < 5; dir++) {
                p = (dat + i) + sdir1[dir];
                if (!*p)*p = n + 1;
                else if (*p == 999) {
                    if (!quit) quit = i + sdir1[dir];
                    path[mptr++] = dir;
                    *(dat + i) = 999;
                    return 1;
                }
            }
        }
    } while (j && smt(n + 1, dat,arr_size));
    return 0;
}