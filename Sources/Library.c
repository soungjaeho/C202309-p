#include <stdio.h>

void printFields(char fields[][20], int fieldCount) {
    printf("�о� ���:\n");
    for (int i = 0; i < fieldCount; i++) {
        printf(" %d. %s\n", i + 1, fields[i]);
    }
}
// �о� ���
/*
void printBooks(int choiceNumber, char fields, int fieldCount) {

    printf("�ش� �о� ���� ���");
    for (int i = 0; i < fieldCount; i++) {
        printf("");
    }
}
*/


int main() {
    char fields[][20] = { "����", "�ڿ�����", "��ȸ����", "����", "����", "����" };
    // �о� �迭
    int fieldCount = sizeof(fields) / sizeof(fields[0]);
    int choiceNumber;

    char fields_Literature[][20] = { "����1","����2" };
    char fields_natural_science[][20] = { "�ڿ�����1","�ڿ�����2" };
    char fields_social_science[][20] = { "��ȸ����1","��ȸ����2" };
    char fields_Engineering[][20] = { "����1","����2" };
    char fields_History[][20] = { "����1","����2" };
    char fields_Art[][20] = { "����1","����2" };

    printFields(fields, fieldCount);
    printf("���ϴ� �о� ��ȣ�� �Է��Ͻÿ� : ");
    scanf_s("%d", &choiceNumber);
    int bookCount = 2;
    if (choiceNumber < 0 && choiceNumber>6) {
        printf("�߸��� �����Դϴ�. ���α׷��� �����մϴ�");

        return -1;
    }
    switch (choiceNumber)
    {
    case 1:
        for (int i = 0; i < bookCount; i++) {
            printf("%s", fields_Literature[i]);
        }
        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;

    case 6:

        break;

    }

    return 0;
}
