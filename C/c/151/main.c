#include<stdio.h>
#include<string.h>
int main()
{
    char *t[24]={"����","���","��Ĩ","���","û��","���","����","�Ҹ�","����","����","�Ҽ�","�뼭","����","ó��","���","�ߺ�","�ѷ�","��","�Ե�","�Ҽ�","�뼳","����","����","����"};
    char t2[10];
    printf("���� �Է� : ");
    scanf("%s", t2);
    for(int i=0; i<24; i++)
    {
        if(strcmp(t[i],t2)==0)
        {
            if(i<6)
                printf("������");
            else if(i<12)
                printf("���� ����");
            else if(i<18)
                printf("���� ����");
            else
                printf("�ܿ� ����");
            break;
        }
    }
}
