#include <stdio.h>
int main()
{
    int i, n, t1 = 1, t2 = 1, nextTerm;
    printf("����� �Ǻ���ġ ������ ���� N��: ");
    scanf("%d", &n);
    printf("�Ǻ���ġ ����: ");

    for (i = 0; i < n+1; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}
