#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,count=0,a=2;
    scanf("%d", &count);
    while(a<=num)
    {
        if(num%a==0)
        {
            count++;
        }
        a++;
    }
    if(count==1)
        printf("¼Ò¼ö",num);
    else
        printf("test",num);
}
