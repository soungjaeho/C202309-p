// ���� ���� �Լ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_library.h"
#include "brrow.h"

void borrowBook(struct library lib[], int count,
                struct loan_history loanHistory[], int* loanCount) {
  char bk_nm[30];
  int found = 0;
  if (count == 0) {
    printf("���� �������� ����Ǿ� �ִ� ������ �����ϴ�.\n");
    return;
  }// �������� ������ ������ ������

  printf("�����Ϸ��� �������� �Է��Ͻÿ�: ");
  scanf_s("%s", bk_nm, (int)sizeof(bk_nm));

  for (int i = 0; i < count; i++) {
    if (strcmp(bk_nm, lib[i].book_name) == 0) {
      if (lib[i].quantity == 0) {
        printf("�ش� ������ ���� �������Դϴ�. \n"); // ������ 0�϶�
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
// ���� ���� ����Լ�
void displayBorrowedBooks(struct loan_history loanHistory[], int loanCount) {
  if (loanCount == 0) {
    printf("������ ������ �����ϴ�.\n");
    return;
  }// ������ ������ ������

  printf("������ ������ ����� ����մϴ�.\n");
  for (int i = 0; i < loanCount; i++) {
    printf("%d . ���� ������: %s / �������: %d \n", i + 1,
           loanHistory[i].book_name, loanHistory[i].quantity);
  }
} // ������ ������ �̸��� ���� ������ ���

// ���� �ݳ� �Լ�
void returnBook(struct library lib[], int count, struct loan_history loanHistory[], int* loanCount) {
  char bk_nm[30];
  int found = 0;

  if (*loanCount == 0) {
    printf("�ݳ��� ������ �����ϴ�.\n");
    return;  
  }

  printf("�ݳ��Ϸ��� �������� �Է��Ͻÿ�: ");
  scanf_s("%s", bk_nm, (int)sizeof(bk_nm));

  for (int i = 0; i < *loanCount; i++) {
    if (strcmp(bk_nm, loanHistory[i].book_name) == 0) {
      for (int j = i; j < *loanCount - 1; j++) {
        strcpy_s(loanHistory[j].book_name, 20, loanHistory[j + 1].book_name);
        loanHistory[j].quantity = loanHistory[j + 1].quantity;
      }
      // ���� �ݳ� = ���� ����ü���� ����

      (*loanCount)--; 
      // ���� ���� ����

      for (int k = 0; k < count; k++) {
        if (strcmp(bk_nm, lib[k].book_name) == 0) {
          lib[k].quantity += 1;
          break;
        }
      }
      // �ݳ� ���� ���� ����
      printf("���� �ݳ� �Ϸ�\n");
      found = 1;
      break;
    }
  }

  if (!found) {
    printf(
        "���� ��Ͽ� �ش� ������ �����ϴ�.\n"
        "���α׷� ó������ ���ư��ϴ�\n\n");
  }
}