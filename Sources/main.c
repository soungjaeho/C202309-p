#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include "struct_library.h"
#include "brrow.h"

int main() {
  struct library lib[100];
  struct loan_book loanBook[100];
  int i = 0;
  int count = 0;
  int input = 0;
  int loanCount = 0;

  while (1) {
    printf("--------------------\n");
    printf("�ڵ��� ���� �ý��ۡ�\n");
    printf("--------------------\n\n");
    printf(
        "1. ���� ���� �߰� (������ ����)\n"
        "2. ���� �帣 Ȯ��\n"
        "3. �帣�� ���� Ȯ��\n"
        "4. ���� ���� �� Ȯ��\n"
        "5. ���� ���� \n"
        "6. ������ ���� ���\n"
        "7. ���� �ݳ�"
        "8. ���α׷� ����\n\n");

    printf("�������� �Է��Ͻÿ�: ");
    scanf_s("%d", &input);
    // ������ ���

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
        borrowBook(lib, count, loanBook, &loanCount);
        break;
      case 6:
        displayBorrowedBooks(loanBook, loanCount);
        break;
      case 7:
        returnBook(lib, count, loanBook, &loanCount);
        break;
      case 8:
        exit(0);
      default:
        printf(
            "�߸� �Է��ϼ̽��ϴ�.\n"
            "�ٽ� �������ּ���.\n\n");
    }
  }
  return 0;
}