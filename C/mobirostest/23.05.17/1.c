#include <stdio.h>
int main(void){
    int b=0,a=0, total=0;
    scanf("%d",&a);
    for(int i=10000; i>=1; i/=10){
        b=a%i;total+=a/i;
        printf("%d : %d",a % i, total ); 
        printf("\n");
        a=b;
    }
    printf("total : %d", total);
}