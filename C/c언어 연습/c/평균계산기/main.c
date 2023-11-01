#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max =0;
    double total =0;
    double totalavg =0;
    scanf("%d",&max);
    for(int i=0;i<max; i++)
    {
        float a=0;
        scanf("%d",&a);
        total+=a;
    }
    totalavg=total/max;
    printf("%f",totalavg);
    return 0;
}
