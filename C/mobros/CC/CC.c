#include <stdio.h>
#define test(x,y) a=(x), b=(y);

int a=0, b=0;
int main(void){

    test(100,1000);
    printf("%d %d", a,b);
    
}
