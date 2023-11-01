#include<stdio.h>
int main()
{
    int sc1[3]={0};
    float sc2[3]={0};
    float total=0;

    for(int i=0; i<3; i++)
        scanf("%f %d", &sc2[i], &sc1[i]);
    for(int i=0; i<3; i++)
    {
        total+=sc2[i]*sc1[i];
    }
    printf("%.1f", total);
    return 0;
}
