#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    char map[50] = {' '};
    map[0]='>';
    int num=0;
    char key = ' ';
    int x=0;
    //int mapx=35;
    while(1)
    {
        printf("%s",map);
        printf("\n");
        scanf("%d", &num);
        system(" cls ");
        while(1)
        {
            for(int i=0; i<num; i++)
            {
                printf("%s",map);
                map[i]='>';
                _sleep(5);
                system(" cls ");
            }

            for(int i=0; i<num-1; i++)
            {
                printf("%s",map);
                map[i]=' ';
                _sleep(5);
                system(" cls ");

            }



            for(int i=num-1; i>=0; i--)
            {
                printf("%s",map);
                map[i]='<';
                _sleep(5);
                system(" cls ");
            }
            for(int i=num-1; i>=0; i--)
            {
                printf("%s",map);
                map[i]=' ';
                _sleep(5);
                system(" cls ");

            }
        }

        system(" cls ");
    }
    return 0;
}
