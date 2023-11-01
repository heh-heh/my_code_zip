#include<stdio.h>
int main()
{
    int number[3]={0};
    int sum=1000;
    scanf("%d %d %d", &number[0],&number[1],&number[2]);

    for(int i=0; i<3; i++)
    {
        if(number[i]<sum)
            sum=number[i];
    }
    printf("%d", sum);
}
