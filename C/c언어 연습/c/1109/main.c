#include<stdio.h>
int main()
{
    char name[20];
    int age=0;
    char code[3];
    double codee=0;

    scanf("%s", name);
    scanf("%d", &age);
    scanf("%c", code);
    scanf("%lf", &codee);

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%c\n", code);
    printf("%f\n",codee);

}
