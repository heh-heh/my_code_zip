#include<stdio.h>
int main()
{
    int ii=0;//���μ��� ����
    int flow[100][100]={0};
    int k=0;//������ �� ����
    int x[100]={0};//������ �� x ��ǥ
    int y[100]={0};//������ �� y ��ǥ
    int i=0,j=0;
    scanf("%d", &ii);
    for(i=0; i<ii; i++)
    {
        for(j=0; j<ii; j++)
            scanf("%d ",&flow[i][j]);
    }
    scanf("%d", &k);

    for(i=0; i<k; i++)
        scanf("%d %d", &x[i],&y[i]);

    for(i=0; i<k; i++)//������ �� ��ġ Ȯ��
    {
        flow[x[i]-1][y[i]-1]=0;
    }

    for(int k2=0; k2<k; k2++)
    {
        for(int i2=x[k];  i2<x[k]; i2++)
        {
            for(int j2=x[k]-2; j2<x[k]+1; j2++)
            {
                flow[i2][j2]=0;
            }
        }
    }

    for(i=0; i<ii; i++)
    {
        for(j=0; j<ii; j++)
            printf("%3d ", flow[i][j]);
        printf("\n");
    }
}
