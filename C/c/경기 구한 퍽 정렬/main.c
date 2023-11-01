#include <stdio.h>
#include <stdlib.h>


int arry[5]={3,2,2,1,1};
int o_puck[4]={1,2,3,0};


int main()
{
    int cn=0;
    for(int i=0; i<5&&arry[i]!==0; i++){
        int idx =0;
        if(arry[i]!=o_puck[cn]){
            for(int ii=0; ii<3; ii++)if(o_puck[ii]==arry[i])idx=ii;
        }


    }


    for(int i=0; i<5&&arry[i] != 0; i++)printf("%d ", arry[i]);
    return 0;
}
