# include <stdio.h>
# define MAX_SIZE 9

// gap��ŭ ������ ��ҵ��� ���� ����
// ������ ������ first���� last����
void inc_insertion_sort(int list[], int first, int last, int gap){
  int i, j, key;

  for(i=first+gap; i<=last; i=i+gap){
    key = list[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

    // ���� ���ĵ� �迭�� i-gap�����̹Ƿ� i-gap��°���� �������� �����Ѵ�.
    // j ���� first �̻��̾�� �ϰ�
    // key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+gap��°�� �̵�
    for(j=i-gap; j>=first && list[j]>key; j=j-gap){
      list[j+gap] = list[j]; // ���ڵ带 gap��ŭ ���������� �̵�
    }

    list[j+gap] = key;
  }
}

// �� ����
void shell_sort(int list[], int n){
  int i, gap;

  for(gap=n/2; gap>0; gap=gap/2){
    if((gap%2) == 0)gap++; // gap�� Ȧ���� �����.

    // �κ� ����Ʈ�� ������ gap�� ����.
    for(i=0; i<gap; i++){
      // �κ� ����Ʈ�� ���� ���� ���� ����
      inc_insertion_sort(list, i, n-1, gap);
    }
    for(int ii=0; ii<9; ii++)printf("%3d ", list[ii]);printf("\n");
  }
}

void main(){
  int i;
  int n = MAX_SIZE;
  int list[9] = {5,2,0,1,9,7,3,11,6};

  // �� ���� ����
  shell_sort(list, n);

  // ���� ��� ���

}
