#include <stdio.h>

#define r(x) (x==1 ? 8<<x:x==5?2<<x:1<<x)
//#define r(x) tc(x==1?~PIND&0x08<<x:x==5?~PIND&0x02<<x:~PINE&0x01<<x)

int main(void){

    while(1){
        int a=0;
        printf("r센서 번호 입력 : " );
        scanf("%d",&a);
        printf("%d\n",r(a));
    }

}