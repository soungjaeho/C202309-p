#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include "struct_library.h"

// ���� �߰� �Լ�, ������ ������(������ ��ȣ 123�߰�)
void addBook(struct library lib[], int* count) {
  int password;
  printf("������ ��ȣ�� �Է��Ͻÿ� : ");
  scanf_s("%d", &password);

  if (password == PASSWORD) {
    printf("������ �̸��� �Է��Ͻÿ� : ");
    getchar();// ��������
    scanf_s("%[^\n]", lib[*count].book_name, (int)sizeof(lib[*count].book_name));
    getchar();

    printf("�۰��� �̸��� �Է��Ͻÿ� : ");
    scanf_s("%[^\n]", lib[*count].author, (int)sizeof(lib[*count].author));
    getchar();

    printf("������ �帣�� �Է��Ͻÿ� : ");
    scanf_s("%[^\n]", lib[*count].fields,
            (int)sizeof(lib[*count].fields) );
    getchar();

    printf("������ ���ǻ縦 �Է��Ͻÿ� : ");
    scanf_s("%[^\n]", lib[*count].publisher,
            (int)sizeof(lib[*count].publisher) );
    // ���ڿ��� �Է¹�����(������, �۰���, �帣, ���ǻ�) ���⸦ �����Ͽ� �Է¹ޱ�
    getchar();
    printf("��ü �������� �Է��Ͻÿ� : ");
    if (scanf_s("%d", &lib[*count].pages, (int)sizeof(lib[*count].pages)) !=1) {
      printf("�������� ���ڷ� �Է����ּ���.\n");
      while (getchar() != '\n');
      return;
    }

    printf("������ ������ �Է��Ͻÿ� :  ");
    if (scanf_s("%f", &lib[*count].price, (int)sizeof(lib[*count].price)) !=1) {
      printf("������ ���ڷ� �Է����ּ���.\n");
      while (getchar() != '\n');
      return;
    }

    printf("������ ������ �Է��Ͻÿ� :  ");
    if (scanf_s("%d", &lib[*count].quantity,(int)sizeof(lib[*count].quantity)) != 1) {
      printf("������ ���ڷ� �Է����ּ���.\n");
      while (getchar() != '\n');
      return;
    }
    // ������, ����, ������ ���ڸ� �Է°����ϰ� ����
    printf("\n���� �߰� �Ϸ�!\n\n");
    (*count)++;
  } else {
    printf("�ùٸ��� ���� ��ȣ�Դϴ�.\n\n");
  }
}// ���� ���� �Է�  -> ������ �۰��� �帣 ���ǻ� ������ ���� ����


// ���� �帣 Ȯ�� �Լ�
void displayGenres(struct library lib[], int count) {
  printf("�����ϰ� �ִ� �帣 ���\n");

  char printedGenres[20][20];// ����� �帣 �迭
  int printedCount = 0;

  for (int j = 0; j < count; j++) {
    int genrePrinted = 0; // ����� �帣����
    for (int k = 0; k < printedCount; k++) {
      if (strcmp(lib[j].fields, printedGenres[k]) == 0) {// �ش�� �帣�� ������帣�� �ִ��� Ȯ��
        genrePrinted = 1;
        break;
      }
    }
    // ����� �帣�� �ǳʶٱ�

    if (!genrePrinted) {
      printf("%d�� �帣: %s\n", printedCount+1, lib[j].fields);
      strcpy_s(printedGenres[printedCount], 20, lib[j].fields);  // ����� �帣�� ������帣 �迭�� ����
      printedCount++; // ������帣��
    }
  }
} //��� : �Է��� ������ ��������ŭ �ݺ� �帣�� ����� �帣�� ����,  ������� ���� �帣  = ���, ����� �帣 �� ����

// �帣�� ���� ���� Ȯ�� �Լ�
void displayBooksByGenre(struct library lib[], int count) {
  char field_nm[30];
  int found = 0;

  printf("�帣���� �Է��Ͻÿ� : ");
  scanf_s(" %[^\n]", field_nm, (int)sizeof(field_nm));
  getchar();

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
        "\n�帣�� �߸� �Է��ϼ̽��ϴ�.\n\n"
        "���α׷� ó������ ���ư��ϴ�\n\n");
  }
}// �Է��� �帣�� ��ġ�ϴ� ������ ������ ���

// ���� ���� �� Ȯ�� �Լ�
void displayBookCount(struct library lib[], int count) {
  printf("\n�� ������ ����:  %d\n", count);
}

// ���� ���� ���Ϸ� ���� �Լ�
void saveLibrary(struct library lib[], int count, int input_output) {
  FILE* file;
  const char* File_Type;
  if (input_output == 1) {
    File_Type = "library.txt";
  } else if (input_output == 2) {
    File_Type = "library.csv ";
  } else {
    printf("�߸� �Է��ϼ̽��ϴ�. \n");
    return;
  }
  if (fopen_s(&file, File_Type, "w") != 0) {// ���� ���� ���Ͽ���
    printf("������ �� �� �����ϴ�.\n");
    return;
  }

  // �ʵ� �̸� ����
  fprintf(file, "������,�۰���,�帣,���ǻ�,����,������,����\n");

  for (int i = 0; i < count; i++) {
    fprintf(file, "%s,%s,%s,%s,%d,%d,%.2f\n", lib[i].book_name, lib[i].author,
            lib[i].fields, lib[i].publisher, lib[i].quantity, lib[i].pages,
            lib[i].price);
  }// ���� ������ ���Ͽ� �Է�

  fclose(file);
  printf("���� ������ ���Ͽ� ����Ǿ����ϴ�.\n");
}
// ���� ���� ���� ���Ϸ� ���� �Լ�
void saveLoanBooks(struct loan_book loanBook[], int loanCount,
                   int input_output) {
  FILE* file;
  const char* File_Type;
  if (input_output == 1) {
    File_Type = "loan_books.txt";
  } else if (input_output == 2) {
    File_Type = "loan_books.csv";
  } else {
    printf("�߸� �Է��ϼ̽��ϴ�. \n");
    return;
  }
  if (fopen_s(&file, File_Type, "w") != 0) {// ������� ���� ����
    printf("������ �� �� �����ϴ�.\n");
    return;
  }

  fprintf(file, "������,����\n");

  for (int i = 0; i < loanCount; i++) {
    fprintf(file, "%s,%d\n", loanBook[i].book_name, loanBook[i].quantity);
  }// �ʵ� �̸� ���� : ������ ������ ������� ���� ������ �ʿ�

  fclose(file);
  printf("���� ���� ������ ���Ͽ� ����Ǿ����ϴ�.\n");
}
