#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int min(int xmax, int *minmap)
{
    int maxmin=xmax*1.5;
    int x[100]={0};
    int y[100]={0};
    srand(time(NULL));
    for(int i=0;i<=xmax; i++)
    {
        x[i]=rand()%xmax;
        y[i]=rand()%xmax;
        for(int j=i+1;j<=i+1; j++)
        {
            if(x[i]==x[j]&&y[i]==y[j])
            {
                i--;
                break;
            }
        }
    }
    for(int i=0;i<xmax; i++)
    {
        *(*minmap+x[i])+y[i]=1;
    }
    return maxmin;
}
int main(void)
{
    int mapmax=0;
    int map[100][100]={0};
    while(1)
    {
        printf("지뢰찾기 맵의 최대 사이즈를 입력하세요 : ");
        if(scanf_s("%d",&mapmax)==0||mapmax<4)
        {
            printf("다시 입력 하세요\n\n");
            rewind(stdin);
            continue;
        }

        else break;
    }

    min(mapmax,map);
    for(int i=0;i<mapmax;i++)
    {
        for(int j=0; j<mapmax;j++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
    return 0;
}
