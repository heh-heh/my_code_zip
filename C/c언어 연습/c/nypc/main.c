#include<stdio.h>
int main()
{
    long int m,f,n;
    int ii,j,evl=0, jj=0;

    scanf("%d %d %d", &m, &f, &n);
    ii=n;//���� ���� üũ
    j=f;//��������
    jj=0;//�ö� ����
    while(1)
    {
        j++;
        jj++;
        if(j>=m)
        {
            ii=ii-jj;
            if(ii<=0)
            {
                ii=ii+jj;
                break;
            }
            //printf("%d ", ii);
            evl++;
            j=1;
            jj=0;

        }
    }

    printf("%d", evl);
}
