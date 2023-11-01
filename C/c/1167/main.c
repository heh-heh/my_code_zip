#include<stdio.h>
int main()
{
    int a[3]={0};
    int b[3]={100000};


    scanf("%d %d %d",&a[0],&a[1],&a[2]);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(b[i]>a[j])
                b[i]=a[j];
        }
    }
    printf("%d %d %d", b[0],b[1],b[2]);
}
