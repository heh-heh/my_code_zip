#include<stdio.h>
#include<string.h>
int main()
{
    char *t[24]={"입춘","우수","경칩","춘분","청명","곡우","입하","소만","망종","하지","소서","대서","입추","처서","백로","추분","한로","상강","입동","소설","대설","동지","소한","대한"};
    char t2[10];
    printf("절기 입력 : ");
    scanf("%s", t2);
    for(int i=0; i<24; i++)
    {
        if(strcmp(t[i],t2)==0)
        {
            if(i<6)
                printf("봄절기");
            else if(i<12)
                printf("여름 절기");
            else if(i<18)
                printf("가을 절기");
            else
                printf("겨울 절기");
            break;
        }
    }
}
