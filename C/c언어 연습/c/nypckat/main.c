#include<stdio.h>
int log[200][3];
int n,m;

int main()
{

    scanf("%d %d", &n,&m);

    for(int i=0; i<m; i++)
        scanf("%d %d %d", &log[i][0],&log[i][1],&log[i][2]);

    if(end()==1)
        printf("yes");
    else
        printf("no");
}

void end()
{
    for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            if(log[i][1]==log[j][1]&&log[i][2]!=log[j][2])
            {
                return 1;
            }
            else if(log[i][1]!=log[j][1]&&log[i][2]!=log[j][2])
            {
                if(log[i+1][1]==log[j][1]&&log[i+1][2]!=log[j][2])
                    return 1;

            }

            else
                return 0;
        }
    }
}

