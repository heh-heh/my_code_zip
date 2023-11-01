#include<stdio.h>
#define swap(num11, num22) {int temp=num11; num11=num22; num11=temp}

int puck[5][3]={
    {3,1,1},
    {3,2,2},
    {2,2,1},
    {1,3,3},
    {0,0,0}
};
int map[5][3]={0};
int O_Puck[4]={1,3,2,0};//�켱 ����
int number[3]={8,4,2};//���ڵ� ����(�����ʿ��� ����)
int f_puck[3]={0,0,0};//�ϼ� �Ǻ���
int sum[3]={0},msum[3]={0};
int home=1 /*��� ���� ��ġ*/, dowon=0;
int *T_puck[24]={0};//������ ��ǥ��
int count=0;
int need_puck[3][5]={0};
void sort(void);


int main(void){

    sort();
    printf("\n\n");
    for(int i=0; i<count; i++){
        printf("%d %d\n", ((int)T_puck[i]-(int)&puck[0][0])%3,((int)T_puck[i]-(int)&puck[0][0])/12);
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++)
            printf("%3d ", puck[j][i]);
        printf("\n\n");
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++)
            printf("%3d ", map[j][i]);
        printf("\n\n");
    }
}
void sort(void)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<5; j++)
            map[j][i]=puck[j][i];
    for(int i=0; i<3; i++)
        for(int j=0; j<5; j++)sum[i]+=puck[j][i];//�� ���κ� ����

    for(int i=0; i<3; i++){
        int cn=0,sum=0;
        for(int j=0; j<4;j++){

            if(sum==number[i])break;
            else if(O_Puck[cn]==puck[j][i]){
                if(sum+puck[j][i]>number[i])break;
                else if(sum+puck[j][i]<=number[i]){
                        //printf("%d %d\n\n", j,i);
                        sum+=puck[j][i];
                        puck[j][i]*=-1;}
            }
            else if(puck[j][i]==O_Puck[cn+1]||puck[j][i]==O_Puck[cn+2]){
                if(cn>3)break;
                cn++;j--;
            }
            else{
                for(int jj=0; jj<j; jj++)puck[jj][i]*=puck[jj][i]<0?-1:1;
            }


        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++)
            printf("%3d ", puck[j][i]);
        printf("\n\n");
    }

    check();

    for(int i=0; i<3; i++){
        if(f_puck[i]==0){
            int sum=0;
            for(int j=0; j<4; j++){
                if(sum+abs(puck[j][i])<number[i])sum+=puck[j][i]<0?abs(puck[j][i]):0;
                if(sum+abs(puck[j][i])>number[i]&&abs(puck[j-1][i])==O_Puck[2]){puck[j-1][i]*=-1;break;}
                /*
                int index=0;
                for(int ii=0; ii<3; ii++)if(sum+O_Puck[ii]==number[i]){index=ii;break;}
                if(index<2)for(int jj=0; jj<j; jj++)puck[jj][i]*=puck[jj][i]<0?-1:1;*/
            }
        }
    }

    printf("\n\n");

    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++)
            printf("%3d ", puck[j][i]);
        printf("\n\n");
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++)msum[i]+=puck[j][i]<0?abs(puck[j][i]):0;
    }
    for(int i=0; i<3; i++) msum[i]-= number[i]; for(int i=0; i<3; i++)msum[i]=abs(msum[i]);
    for(int i=0; i<3; i++)printf("%d ",msum[i]);
    for(int i=0; i<3; i++){
        if(msum[i]>4){
            for(int i=0; i<3; i++){

            }
        }
        else{
            need_puck[i][0]=msum[i];
        }
    }
    for(int i=0; i<5; i++) for(int j=0; j<3; j++)map[i][j]=puck[i][j]>0?puck[i][j]:0;
    if(check()==0)
        func();
}
//����
void func(void){


}
//�ʿϼ� äũ��
int check(void){
    int C_map[5][3]={0};
    int map_sum[3]={0};
    for(int i=0; i<3; i++)
        for(int j=0; j<5; j++)
            C_map[j][i]=puck[j][i]<0?puck[j][i]*-1:0;

    for(int i=0; i<3; i++){
        for(int j=4; j>=0; j--)
            map_sum[i]+=C_map[j][i];
    }
    for(int i=0; i<3; i++)if(map_sum[i]==number[i])f_puck[i]=1;

    for(int i=0; i<3; i++)if(f_puck[i]==0)return 0;//�̿ϼ� ������ �������

    return 1;
}
//������ ���� //
//x,y : ó���� �� ��ǥ
//t : ������ ������ �Ǵ� 1=���� 0=������
//ex, ey : t==0 �϶� ���� ������ ��ġ
void move(int x, int y, int t, int ex, int ey)//������ ���� x,y : ó���� �� ��ǥ
{
    if(t==1){
        puck[x][y]=0;

    }
    else{

    }
}
