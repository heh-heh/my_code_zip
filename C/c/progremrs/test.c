#include <stdio.h>
#include <stdio.h>

int main(void){
    int n =0,c=0;
    int* arr[][] = malloc(sizeof(int) * 1000 * 1000);	
    scanf("%d", &n);arr[0][0]=0;
    
    
     for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            arr[i][j]=c;
        c++;
    }c=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            arr[j][i]=c;
        c++;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d", arr[i][j]);
        printf("\n");
    }

    return 0;
}