#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    int i=0;
    int j=0;


    int ant[11][11];

    for(int x=1; x<11; x++)//�����Է�
    {
        for(int y=1; y<11; y++)
        {
            scanf("%d", &ant[x][y]);
        }
    }
    i=2,j=2;

    while(ant[i][j] != 2 && i <= 10 && j <= 10)//���
    {
        if(ant[i][j+1] != 1) // ������ �˻�
            ant[i][j++] = 9;

        else if(ant[i+1][j] != 1) // �Ʒ��� �˻�
            ant[i++][j] = 9;
        else
            break;
    }
    ant[i][j]=9;

    for(int x =1; x<11; x++)
    {
        for(int y =1; y<11; y++)
            printf("%d ", ant[x][y]);
        printf("\n");
    }
}
