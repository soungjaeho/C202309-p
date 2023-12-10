// ���� ���� �Լ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_struct.h"
#include "main_brrow.h"

void borrowBook(struct library lib[], int count,
                struct loan_history loanHistory[], int* loanCount) {
  char bk_nm[30];
  int found = 0;
  if (count == 0) {
    printf("���� �������� ����Ǿ� �ִ� ������ �����ϴ�.\n");
    return;
  }
  printf("�����Ϸ��� �������� �Է��Ͻÿ�: ");
  scanf_s("%s", bk_nm, (int)sizeof(bk_nm));

  for (int i = 0; i < count; i++) {
    if (strcmp(bk_nm, lib[i].book_name) == 0) {
      if (lib[i].quantity == 0) {
        printf("�ش� ������ ���� �������Դϴ�. \n");
      } else {
        strcpy_s(loanHistory[*loanCount].book_name, 20, lib[i].book_name);
        loanHistory[*loanCount].quantity = 0;  // ���� ���� �ʱ�ȭ
        loanHistory[*loanCount].quantity += 1;

        lib[i].quantity -= 1;

        (*loanCount)++;

        printf("���� �Ϸ�\n");
      }
      found = 1;
      break;
    }
  }

  if (!found) {
    printf(
        "�������� �߸� �Է��ϼ̽��ϴ�.\n"
        "���α׷� ó������ ���ư��ϴ�\n\n");
  }
}
void displayBorrowedBooks(struct loan_history loanHistory[], int loanCount) {
  if (loanCount == 0) {
    printf("������ ������ �����ϴ�.\n");
    return;
  }

  printf("������ ������ ����� ����մϴ�.\n");
  for (int i = 0; i < loanCount; i++) {
    printf("%d . ���� ������: %s / �������: %d \n", i + 1,
           loanHistory[i].book_name, loanHistory[i].quantity);
  }
}