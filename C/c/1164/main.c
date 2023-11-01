#include<stdio.h>
int main()
{
    int high[3]={0};
    int cou=0;
    scanf("%d %d %d", &high[0],&high[1],&high[2]);
    for(int i=0; i<3; i++)
    {
        if(high[i]<=170)
        {
            printf("CRASH");break;
        }
        else if(high>170)
            cou++;
    }
    if(cou==3)
        printf("PASS");
}
