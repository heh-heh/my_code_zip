#include <stdio.h>
int need_puck[3][5]={0};
int O_Puck[4]={1,3,2,9};
int number[3]={4,12,8};
int np=0;
int map[5][3]={
    {3,2,1},
    {3,3,2},
    {2,2,1},
    {1,1,3},
    {0,0,0}
};

void findnum(void);
int O_puckch(int *a);
void s_sort(int arr[]);

int main(void){
    findnum();
    printf("=====need_puck=====\n\n");
    for(int i=0; i<3; i++){ for(int j=0; j<5; j++) printf("%d ", need_puck[i][j]); printf("\n");}
    
}
void findnum(void){
    int arr[5]={4};
    int count11[4]={0};
    
    for(int i=0; i<3; i++)for(int j=0; j<5; j++)++count11[map[j][i]];
    
    for(int i=0; i<3; i++){
        int sum=0,pp=3,j=0;
        while(pp){
            if(count11[pp]&&sum+pp<=number[i]){arr[j++]=pp; --count11[pp]; sum+=pp;}
            else if(count11[pp]&&sum+pp==number[i]){arr[j++]=pp; --count11[pp]; sum+=pp; break;}
            else pp--;
        }
        for(int j=0; j<5; j++)arr[j]=arr[j]==0?4:arr[j];
        if(O_puckch(&arr[0]))s_sort(arr);
        for(int j=0; j<5 ; j++){need_puck[i][j]=arr[j]==4?0:arr[j]; arr[j]=0;}
    }
    for(int i=1; i<4; i++)printf("%d", count11[i]);
}

int O_puckch(int *a){
    int j=0, i=0;
    while(i<3){
        if(*(a+j)==O_Puck[i])j++;
        else if(*(a+j)!=O_Puck[i])i++;
        if(i>1&&*(a+j)==O_Puck[0])return 1;
        
    }
    return 0;
}
void s_sort(int arr[]) {
    int i, j, min_idx, tmp;
    for (i = 0; i < 5 - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < 5; j++) {
            if (O_Puck[arr[j] - 1] < O_Puck[arr[min_idx] - 1]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }
}