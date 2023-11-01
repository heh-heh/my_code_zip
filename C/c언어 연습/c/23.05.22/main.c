#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*
    num : 분자
    dum : 분모
*/
int func(int num1, int dum1, int num2, int dum2){
    int arry[2];
    int a = dum1>dum2?dum1:dum2 , b = a==dum1?dum2:dum1;
    int t = a%b;
    if(t!=0){
        arry[0] = (num1*a)+(num2*b);
        arry[1] = (a*b);
    }
    else{
        int tt = 1;
        while(1){
            if(b*++tt == a){break;}
        }
        arry[0] = (num1*tt)+num2;
        arry[1] = (b*tt);
    }
    printf("%d %d", arry[0],arry[1]);
    //return arry;
}

int main(){
    func(9,2,1,3);
}