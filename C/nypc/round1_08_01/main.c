#include <stdio.h>

int main(void){
    int n, m , sum1=0, sum2=0,res=0;
    int map[50][50];
    
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            for(int i=1; i<=m; i++){
                if(x - i > 0)sum1 += map[x-i][y];
                if(x + i < n)sum1 += map[x+i][y];
                if(y - i > 0)sum1 += map[x][y-i];
                if(y + i < n)sum1 += map[x][y+i];
                
            }sum1+=map[x][y];printf("sum1 : %d\n", sum1);
            if(res < sum1) res = sum1; sum1=0;
        }
    }
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            for(int i=1; i<=m; i++){
                if(x - i > 0 && y - i > 0) sum2 += map[x-i][y-i];
                if(x - i > 0 && y + i < n) sum2 += map[x-i][y+i];
                if(x + i < n && y - i > 0) sum2 += map[x+i][y-i];
                if(x + i < n && y + i < n) sum2 += map[x+i][y+i];
            }
            sum2+=map[x][y]; printf("sum2 : %d\n", sum2);
            if(res < sum2) res = sum2; sum2=0;
        }
    }
    printf("%d", res);getchar();getchar();
}