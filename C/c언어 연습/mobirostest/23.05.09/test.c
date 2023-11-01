#include <stdio.h>

int main()
{
    int num;

    scanf("%d", &num);

    for(int i=1;i<=num;i++)
    {
        for(int l=1;l<=i;l++) printf(" ");
        for(int k=1;k<=num;k++) printf("*");
        printf("\n");
    }
    return 0;
}