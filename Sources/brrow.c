// 도서 대출 함수
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
    printf("현재 도서관에 저장되어 있는 도서가 없습니다.\n");
    return;
  }
  printf("대출하려는 도서명을 입력하시오: ");
  scanf_s("%s", bk_nm, (int)sizeof(bk_nm));

  for (int i = 0; i < count; i++) {
    if (strcmp(bk_nm, lib[i].book_name) == 0) {
      if (lib[i].quantity == 0) {
        printf("해당 도서는 전권 대출중입니다. \n");
      } else {
        strcpy_s(loanHistory[*loanCount].book_name, 20, lib[i].book_name);
        loanHistory[*loanCount].quantity = 0;  // 대출 수량 초기화
        loanHistory[*loanCount].quantity += 1;

        lib[i].quantity -= 1;

        (*loanCount)++;

        printf("대출 완료\n");
      }
      found = 1;
      break;
    }
  }

  if (!found) {
    printf(
        "도서명을 잘못 입력하셨습니다.\n"
        "프로그램 처음으로 돌아갑니다\n\n");
  }
}
void displayBorrowedBooks(struct loan_history loanHistory[], int loanCount) {
  if (loanCount == 0) {
    printf("대출한 도서가 없습니다.\n");
    return;
  }

  printf("대출한 도서의 목록을 출력합니다.\n");
  for (int i = 0; i < loanCount; i++) {
    printf("%d . 대출 도서명: %s / 대출수량: %d \n", i + 1,
           loanHistory[i].book_name, loanHistory[i].quantity);
  }
}