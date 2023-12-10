#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include "struct_library.h"
#include "brrow.h"

int main() {
  struct library lib[100];
  struct loan_history loanHistory[100];
  int i = 0;
  int count = 0;
  int input = 0;
  int loanCount = 0;

  while (1) {
    printf("--------------------\n");
    printf("★도서 관리 시스템★\n");
    printf("--------------------\n\n");
    printf(
        "1. 도서 정보 추가 (관리자 전용)\n"
        "2. 보유 장르 확인\n"
        "3. 장르별 도서 확인\n"
        "4. 도서 종류 수 확인\n"
        "5. 도서 대출 \n"
        "6. 대출한 도서 목록\n"
        "7. 프로그램 종료\n\n");

    printf("선택지를 입력하시오: ");
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
        borrowBook(lib, count, loanHistory, &loanCount);
        break;
      case 6:
        displayBorrowedBooks(loanHistory, loanCount);
        break;
      case 7:
        exit(0);
      default:
        printf(
            "잘못 입력하셨습니다.\n"
            "다시 선택해주세요.\n\n");
    }
  }
  return 0;
}