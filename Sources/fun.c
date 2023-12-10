#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include "main_struct.h"

// ���� �߰� �Լ�, ������ ������(�⺻��ȣ 123�߰�)
void addBook(struct library lib[], int* count) {
  int password;
  printf("������ ��ȣ�� �Է��Ͻÿ� : ");
  scanf_s("%d", &password);

  if (password == 123) {
    printf("������ �̸��� �Է��Ͻÿ� : ");
    scanf_s("%s", lib[*count].book_name, (int)sizeof(lib[*count].book_name));

    printf("�۰��� �̸��� �Է��Ͻÿ� : ");
    scanf_s("%s", lib[*count].author, (int)sizeof(lib[*count].author));

    printf("������ �帣�� �Է��Ͻÿ� : ");
    scanf_s("%s", lib[*count].fields, (int)sizeof(lib[*count].fields));

    printf("������ ���ǻ縦 �Է��Ͻÿ� : ");
    scanf_s("%s", lib[*count].publisher, (int)sizeof(lib[*count].publisher));

    printf("��ü �������� �Է��Ͻÿ� : ");
    scanf_s("%d", &lib[*count].pages, (int)sizeof(lib[*count].pages));

    printf("������ ������ �Է��Ͻÿ� :  ");
    scanf_s("%f", &lib[*count].price, (int)sizeof(lib[*count].price));

    printf("������ ������ �Է��Ͻÿ� :  ");
    scanf_s("%d", &lib[*count].quantity, (int)sizeof(lib[*count].quantity));

    printf("\n���� �߰� �Ϸ�!\n\n");
    (*count)++;
  } else {
    printf("�ùٸ��� ���� ��ȣ�Դϴ�.\n\n");
  }
}

// ���� �帣 Ȯ�� �Լ�
void displayGenres(struct library lib[], int count) {
  printf("�����ϰ� �ִ� �帣 ���\n");

  char printedGenres[20][20];
  int printedCount = 0;

  for (int j = 0; j < count; j++) {
    int genrePrinted = 0;
    for (int k = 0; k < printedCount; k++) {
      if (strcmp(lib[j].fields, printedGenres[k]) == 0) {
        genrePrinted = 1;
        break;
      }
    }

    if (!genrePrinted) {
      printf("%s\n", lib[j].fields);
      strcpy_s(printedGenres[printedCount], 20, lib[j].fields);
      printedCount++;
    }
  }
}

// �帣�� ���� Ȯ�� �Լ�
void displayBooksByGenre(struct library lib[], int count) {
  char field_nm[30];
  int found = 0;

  printf("�帣���� �Է��Ͻÿ� : ");
  scanf_s("%s", field_nm, (int)sizeof(field_nm));

  for (int i = 0; i < count; i++) {
    if (strcmp(field_nm, lib[i].fields) == 0) {
      printf("�帣 %s�� ���� ������ ����մϴ�. \n", field_nm);
      printf("-------------------\n");
      printf("������ : %s \n", lib[i].book_name);
      printf("�۰��� : %s \n", lib[i].author);
      printf("���� ���ǻ� : %s \n", lib[i].publisher);
      printf("���� ������ : %d \n", lib[i].pages);
      printf("���� ���� % f \n", lib[i].price);
      printf("�������� % d \n", lib[i].quantity);
      if (lib[i].quantity == 0) {
        printf("����Ұ�!\n");
      } else {
        printf("���Ⱑ��!\n");
      }
      printf("-------------------\n\n");
      found = 1;
    }
  }

  if (!found) {
    printf(
        "�帣�� �߸� �Է��ϼ̽��ϴ�.\n"
        "���α׷� ó������ ���ư��ϴ�\n\n");
  }
}

// ���� ���� �� Ȯ�� �Լ�
void displayBookCount(struct library lib[], int count) {
  printf("\n�� ������ ����:  %d\n", count);
}
