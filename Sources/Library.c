
#include <stdio.h>
void printFields(char fields[][20], int fieldCount) {
    printf("분야 목록:\n");
    for (int i = 0; i < fieldCount; i++) {
        printf(" %d. %s\n", i + 1, fields[i]);
    }
}
// 분야 출력

int main() {
    char fields[][20] = { "문학", "자연과학", "사회과학", "공학", "역사", "예술" };
    // 분야 배열
    int fieldCount = sizeof(fields) / sizeof(fields[0]);


    printFields(fields, fieldCount);



    return 0;
}
