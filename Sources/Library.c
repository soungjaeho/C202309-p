#include <stdio.h>

void printFields(char fields[][20], int fieldCount) {
    printf("분야 목록:\n");
    for (int i = 0; i < fieldCount; i++) {
        printf(" %d. %s\n", i + 1, fields[i]);
    }
}
// 분야 출력
/*
void printBooks(int choiceNumber, char fields, int fieldCount) {

    printf("해당 분야 도서 목록");
    for (int i = 0; i < fieldCount; i++) {
        printf("");
    }
}
*/


int main() {
    char fields[][20] = { "문학", "자연과학", "사회과학", "공학", "역사", "예술" };
    // 분야 배열
    int fieldCount = sizeof(fields) / sizeof(fields[0]);
    int choiceNumber;

    char fields_Literature[][20] = { "문학1","문학2" };
    char fields_natural_science[][20] = { "자연과학1","자연과학2" };
    char fields_social_science[][20] = { "사회과학1","사회과학2" };
    char fields_Engineering[][20] = { "공학1","공학2" };
    char fields_History[][20] = { "역사1","역사2" };
    char fields_Art[][20] = { "예술1","예술2" };

    printFields(fields, fieldCount);
    printf("원하는 분야 번호를 입력하시오 : ");
    scanf_s("%d", &choiceNumber);
    int bookCount = 2;
    if (choiceNumber < 0 && choiceNumber>6) {
        printf("잘못된 선택입니다. 프로그램을 종료합니다");

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
