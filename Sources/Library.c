
#include <stdio.h>
void printFields(char fields[][20], int fieldCount) {
    printf("�о� ���:\n");
    for (int i = 0; i < fieldCount; i++) {
        printf(" %d. %s\n", i + 1, fields[i]);
    }
}
// �о� ���

int main() {
    char fields[][20] = { "����", "�ڿ�����", "��ȸ����", "����", "����", "����" };
    // �о� �迭
    int fieldCount = sizeof(fields) / sizeof(fields[0]);


    printFields(fields, fieldCount);



    return 0;
}
