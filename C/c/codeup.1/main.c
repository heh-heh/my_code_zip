#include<stdio.h>

void initant();
void checkwall_food();
void printant();
int anteat[10][10]={0};

int main()
{
    initant();
    checkwall_food();
    printant();
}
void initant()
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            scanf("%d ",&anteat[i][j]);
}
void checkwall_food()
{
    int i=1,j=1;
    while(1)
    {
        if(anteat[i][j]==2)
            break;
        if(anteat[i][j]==0&&anteat[i][j+1]!=1)
        {
            anteat[i][j]=9;
            j++;
        }
        else if(anteat[i][j+1]==1)
        {
            i++;
            anteat[i][j]=9;
        }

    }
}
void printant()
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            printf("%d ",anteat[i][j]);
}
