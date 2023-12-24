#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_library.h"
#include "borrow.h"

// 도서 대출 함수
void borrowBook(struct library lib[], int count, struct loan_book loanBook[],
                int* loanCount) {
  char bk_nm[30];
  int found = 0;
  if (count == 0) {
    printf("현재 도서관에 저장되어 있는 도서가 없습니다.\n");
    return;
  }// 도서관에 저장한 도서가 없을때

  printf("대출하려는 도서명을 입력하시오: ");
  getchar();
  scanf_s("%[^\n]", bk_nm, (int)sizeof(bk_nm));


  for (int i = 0; i < count; i++) {
    if (strcmp(bk_nm, lib[i].book_name) == 0) {
      if (lib[i].quantity == 0) {
        printf("해당 도서는 전권 대출중입니다. \n"); // 수량이 0일때
      } else {
        strcpy_s(loanBook[*loanCount].book_name, 20, lib[i].book_name);
        loanBook[*loanCount].quantity = 0;  // 대출 수량 초기화
        loanBook[*loanCount].quantity += 1;

        lib[i].quantity -= 1; // 도서 수량 -1
        
        (*loanCount)++; // 대출 수량 +1

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
// 대출 도서 출력함수
void displayBorrowedBooks(struct loan_book loanBook[], int loanCount) {
  if (loanCount == 0) {
    printf("대출한 도서가 없습니다.\n");
    return;
  }// 대출한 도서가 없을때

  printf("대출한 도서의 목록을 출력합니다.\n");
  for (int i = 0; i < loanCount; i++) {
    printf("%d . 대출 도서명: %s / 대출수량: %d \n", i + 1,
           loanBook[i].book_name, loanBook[i].quantity);
  }
} // 대출한 도서의 이름과 대출 수량을 출력

// 도서 반납 함수
void returnBook(struct library lib[], int count, struct loan_book loanBook[],
                int* loanCount) {
  char bk_nm[30];
  int found = 0;

  if (*loanCount == 0) {
    printf("반납할 도서가 없습니다.\n");
    return;  
  }

  printf("반납하려는 도서명을 입력하시오: ");
  getchar();
  scanf_s("%[^\n]", bk_nm, (int)sizeof(bk_nm));
  getchar();

  for (int i = 0; i < *loanCount; i++) {
    if (strcmp(bk_nm, loanBook[i].book_name) == 0) {
      for (int j = i; j < *loanCount - 1; j++) {
        strcpy_s(loanBook[j].book_name, 20, loanBook[j + 1].book_name);
        loanBook[j].quantity = loanBook[j + 1].quantity;
      }
      // 도서 반납 = 대출 구조체에서 삭제

      (*loanCount)--; 
      // 대출 수량 감소

      for (int k = 0; k < count; k++) {
        if (strcmp(bk_nm, lib[k].book_name) == 0) {
          lib[k].quantity += 1;
          break;
        }
      }
      // 반납 도서 수량 증가
      printf("도서 반납 완료\n");
      found = 1;
      break;
    }
  }

  if (!found) {
    printf(
        "대출 기록에 해당 도서가 없습니다.\n"
        "프로그램 처음으로 돌아갑니다\n\n");
  }
}