#include<stdio.h>
#include<stdlib.h>

int mapmain[128][128]={0};
int mapnum=0;

int w=0;//��� ���� ��
int b=0;//�Ķ��� ���� ��

int nfull=0;//���� ���� Ȯ��

int countpap(int num)
{
    nfull=0;
    if(num<3)
    {
        for(int i=0; i<num; i++)
            for(int j=0; j<num; j++)
                if(mapmain[0][0]!=mapmain[i][j])
                {
                    nfull=1;
                    break;
                }

        if(nfull==1)
        {
            for(int i=0; i<2; i++)
                for(int j=0; j<2; j++)
                {
                    if(mapmain[i][j]==1)
                        b++;
                    else
                        w++;
                }
        }
        else
        {
            if(mapmain[0][0]==1)
                b++;
            else
                w++;
        }
        printf("%d\n%d", w,b);
    }
    else
    {
        for(int i=0; i<num; i++)
        {
            for(int j=0; j<num; j++)
            {
                if(mapmain[0][0]!=mapmain)
                    nfull=1;
            }
        }
    }
}

int main()
{
    scanf("%d", &mapnum);
    for(int i=0; i<mapnum; i++)
        for(int j=0; j<mapnum; j++)
            scanf("%d", &mapmain[i][j]);//�ʽ�ĵ
    countpap(mapnum);
}
