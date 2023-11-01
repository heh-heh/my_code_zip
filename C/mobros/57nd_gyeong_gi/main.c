#include<stdio.h>
#include<math.h>

int puck[5][3]={
    {3,2,1},
    {3,1,2},
    {2,2,1},
    {1,3,3},
    {0,0,0}
};
int map[5][3]={0};
int O_Puck[4]={1,3,2,4};//우선 순위
int number[3]={4,8,2};//바코드 갯수(오른쪽에서 부터)
int f_puck[3]={0,0,0};//완성 판별용
int msum[3]={0};
int home=1 /*출발 도착 위치*/, dowon=0;
int *T_puck[24]={0};//버릴퍽 좌표들
int count=0;
int need_puck[3][5]={0};//필요한 퍽 을 뽑아낸것
int need_puck2[20][5]={0}, pt=0;//필요퍽의 시작 x,y,t,ex,ey

void sort(int ckk, int ckk2);
void move(int x, int y, int t, int ex, int ey);
int findnum(int a,int b);
void func(void);
int check(void);
//스왑을 위한 함수
void swap(int * num11, int * num22){int temp=*num11; *num11=*num22; *num22=temp;}

int main(void){
    func();
    printf("\n\n======정렬 완료=======\n\n");
    for(int i=0; i<3; i++){
                for(int j=0; j<5; j++)
                    printf("%3d ", puck[j][i]);
                printf("\n\n");
            }
}
//정렬
void sort(int ckk, int ckk2)
{
    for(int i=0; i<3&&ckk==0; i++){
        for(int j=4; j>=0; j--){
            if(map[j][i]>0){
                path[pt][0]=j; path[pt][1]=i; path[pt++][2]=1; map[j][i]=0;
                }
            else if(map[j][i]<0){ckk2=0; break;}
        }
    }
    for(int i=0; i<3&&ckk2==0; i++){
        for(int j=0; j<5; j++){
            int ck=0;
            if(map[j][i]>0){
                ck=1;
            }
            if(ck){
                for(int ii=4; ii>=0&&ckk2==0; ii--){
                    if(map[ii][i]<0){
                        for(int iii=0; iii<3&&ckk2==0; iii++){
                            for(int jj=4; jj>=0; jj--){
                                if(map[iii][jj]==0&&jj!=i){
                                    path[pt][0]=ii;path[pt][1]=i; path[pt][3]=iii;path[pt++][4]=jj;
                                    swap(map[ii][i],map[iii][jj]);
                                    ckk2=1;break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(ckk2){ckk2=1; break;}
    }
    for(int i=0; i<3; i++) for(int j=0; j<5; j++) if(map[j][i]>0)sort(0,1);//혹시 필요 퍽 이외의 것이 있을 경우 재귀 함수 작동
}
//정렬 준비+move
void func(void){
    for(int i=0; i<3; i++)
        for(int j=0; j<5; j++)
            map[j][i]=puck[j][i];
    for(int i=0; i<3; i++){
        int cn=0,sum=0;
        for(int j=0; j<4;j++){
            if(cn>3)break;
            else if(O_Puck[cn]==puck[j][i]){
                if(sum+puck[j][i]==number[i]&&puck[j-1][i]<0){puck[j][i]*=-1; break;}
                else if(sum+puck[j][i]>=number[i]){break;}
                else if(sum+puck[j][i]<=number[i]){
                    sum+=puck[j][i];
                    puck[j][i]*=-1;}
            }
            else if((puck[j][i]==O_Puck[cn+1]||puck[j][i]==O_Puck[cn+2])){
                cn++;j--;continue;
            }
            // else{
            //     for(int jj=0; jj<j; jj++)puck[jj][i]*=puck[jj][i]<0?-1:1;
            // }
        }
    }
    for(int i=0; i<5; i++) for(int j=0; j<3; j++)map[i][j]=puck[i][j]>0?puck[i][j]:0;
    for(int i=0; i<3; i++)for(int j=0; j<5; j++)msum[i]+=puck[j][i]<0?abs(puck[j][i]):0;
    for(int i=0; i<3; i++) msum[i]-= number[i]; for(int i=0; i<3; i++)msum[i]=abs(msum[i]);
    for(int i=0; i<3; i++){
        if(msum[i]>=4) findnum(msum[i],i);
        else need_puck[i][0]=msum[i];
    }
    if(check()==0)
        sort();
    int check2 = check( );
    if(check2==2){
        for(int i=0; i<5; i++) for(int j=0; j<3; j++){if(puck[j][i]>0){need_puck2[pt][1]=j; need_puck2[pt][0]=i;need_puck2[pt++][2]=1;}}
    }
    for(int i=pt; i>=0; i--){
            if(check())return;
            move(need_puck2[i][1],need_puck2[i][0],need_puck2[i][2],need_puck2[i][4],need_puck2[i][3]);
            printf("-------MOVENMAP-------");
            printf("\n\n");
            for(int i=0; i<3; i++){
                for(int j=0; j<5; j++)
                    printf("%3d ", puck[j][i]);
                printf("\n\n");
            }
        }

}
//맵완성 채크용

/*무빙을 위함 
x,y : 처리할 퍽 좌표
t : 버리는 퍽인지 판단 1=버림 0=움직임
ex, ey : t==0 일때 퍽을 움직일 위치*/
void move(int x, int y, int t, int ex, int ey)
{

    if(t==1){
        puck[x][y]=0;

    }
    else{
        
        
        
        swap(&puck[x][y],&puck[ex][ey]);
        puck[ex][ey]*=-1;
    }
}
int findnum(int a, int b){
    int arr[5]={4};
    int count11[4]={0};
    int ccc=3, aa=a,ccc2=0;
    for(int i=0; i<3; i++)for(int j=0; j<5; j++)count11[map[j][i]]++;
    //printf("%d  \n",a);
    while(ccc>=1){
        if(aa-ccc>0&&count11[ccc]!=0){
            aa-=ccc;
            count11[ccc]--;arr[ccc2++]=ccc;
        }
        if(aa-ccc<0)ccc--;  
        else if(aa-ccc==0){arr[ccc2]=ccc; break;}
    }
    //for(int i=0; i<5; i++)printf("%d ",arr[i]);printf("\n");
    int ccc3=0;
    int tt=0;

    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            if(O_Puck[arr[j]]>O_Puck[j+1]&&arr[j+1]!=0){
                tt=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tt;
                for(int i=0; i<5; i++)printf("%d ",arr[i]);printf("\n");
            }
        }
    }
    int arr2[5]={0}; 
    int zerocn=0;
    if(arr[0]==O_Puck[2]){
        for(int i=0; i<5; i++)arr2[i]=arr[4-i];
        
        for(int i=0; i<5; i++){if(arr2[i]==0)zerocn++;else if(arr[i]>0)break;}
    }
    else{
        for(int i=0; i<5; i++)arr2[i]=arr[i];
    }
    for(int i=0; i<5; i++){if(i+zerocn<5)need_puck[b][i]=arr2[zerocn+i];}
}
