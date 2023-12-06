#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ ����ü(�̸� �۰� �帣 ���ǻ� ���� ������ ����)
struct library {
  char book_name[20];
  char author[20];
  char fields[20];
  char publisher[20];
  int quantity;
  int pages;
  float price;
};

// ������ ���� ���� ����ü
struct loan_history {
  char book_name[20];
  int quantity;
};

// �Լ� ���� ����
void addBook(struct library lib[], int* count);
void displayGenres(struct library lib[], int count);
void displayBooksByGenre(struct library lib[], int count);
void displayBookCount(struct library lib[], int count);
void borrowBook(struct library lib[], int count);

int main() {
  struct library lib[100];
  int i = 0;
  int count = 0;
  int input = 0;

  while (1) {
    printf("--------------------\n");
    printf("�ڵ��� ���� �ý��ۡ�\n");
    printf("--------------------\n\n");
    printf(
        "1. ���� ���� �߰� (������ ����)\n"
        "2. ���� �帣 Ȯ��\n"
        "3. �帣�� ���� Ȯ��\n"
        "4. ���� ���� �� Ȯ��\n"
        "5. ���� ���� <----  �̱���\n"
        "6. ���α׷� ����\n\n");

    printf("�������� �Է��Ͻÿ�: ");
    scanf_s("%d", &input);

    switch (input) {
      case 1:
        addBook(lib, &count);
        break;
      case 2:
        displayGenres(lib, count);
        break;
      case 3:
        displayBooksByGenre(lib, count);
        break;
      case 4:
        displayBookCount(lib, count);
        break;
      case 5:
        borrowBook(lib, count);
        break;
      case 6:
        exit(0);
      default:
        printf(
            "�߸� �Է��ϼ̽��ϴ�.\n"
            "�ٽ� �������ּ���.\n\n");
    }
  }
  return 0;
}

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
      printf("���� ������ :  %d \n ", lib[i].pages);
      printf("���� ���� % f \n", lib[i].price);
      printf("�������� % d \n", lib[i].quantity);
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

// ���� ���� �Լ�
void borrowBook(struct library lib[], int count) {
  char bk_nm[30];
  int found = 0;
  printf("�����Ϸ��� �������� �Է��Ͻÿ�: ");
  scanf_s("%s", bk_nm, (int)sizeof(bk_nm));

  for (int i = 0; i < count; i++) {
    if (strcmp(bk_nm, lib[i].book_name) == 0) {
      if (lib[i].quantity == 0) {
        printf("�ش� ������ ���� �������Դϴ�. \n");
      } else {
        lib[i].quantity -= 1;
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