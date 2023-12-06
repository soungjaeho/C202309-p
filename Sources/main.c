#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 도서관 구조체(이름 작가 장르 출판사 수량 페이지 가격)
struct library {
  char book_name[20];
  char author[20];
  char fields[20];
  char publisher[20];
  int quantity;
  int pages;
  float price;
};

// 대출한 도서 정보 구조체
struct loan_history {
  char book_name[20];
  int quantity;
};

// 함수 원형 선언
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
    printf("★도서 관리 시스템★\n");
    printf("--------------------\n\n");
    printf(
        "1. 도서 정보 추가 (관리자 전용)\n"
        "2. 보유 장르 확인\n"
        "3. 장르별 도서 확인\n"
        "4. 도서 종류 수 확인\n"
        "5. 도서 대출 <----  미구현\n"
        "6. 프로그램 종료\n\n");

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
        borrowBook(lib, count);
        break;
      case 6:
        exit(0);
      default:
        printf(
            "잘못 입력하셨습니다.\n"
            "다시 선택해주세요.\n\n");
    }
  }
  return 0;
}

// 도서 추가 함수, 관리자 선택지(기본암호 123추가)
void addBook(struct library lib[], int* count) {
  int password;
  printf("관리자 암호를 입력하시오 : ");
  scanf_s("%d", &password);

  if (password == 123) {
    printf("도서의 이름을 입력하시오 : ");
    scanf_s("%s", lib[*count].book_name, (int)sizeof(lib[*count].book_name));

    printf("작가의 이름을 입력하시오 : ");
    scanf_s("%s", lib[*count].author, (int)sizeof(lib[*count].author));

    printf("도서의 장르를 입력하시오 : ");
    scanf_s("%s", lib[*count].fields, (int)sizeof(lib[*count].fields));

    printf("도서의 출판사를 입력하시오 : ");
    scanf_s("%s", lib[*count].publisher, (int)sizeof(lib[*count].publisher));

    printf("전체 페이지를 입력하시오 : ");
    scanf_s("%d", &lib[*count].pages, (int)sizeof(lib[*count].pages));

    printf("도서의 가격을 입력하시오 :  ");
    scanf_s("%f", &lib[*count].price, (int)sizeof(lib[*count].price));

    printf("도서의 수량을 입력하시오 :  ");
    scanf_s("%d", &lib[*count].quantity, (int)sizeof(lib[*count].quantity));


    printf("\n도서 추가 완료!\n\n");
    (*count)++;
  } else {
    printf("올바르지 못한 암호입니다.\n\n");
  }
}

// 보유 장르 확인 함수
void displayGenres(struct library lib[], int count) {
  printf("보유하고 있는 장르 목록\n");

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

// 장르별 도서 확인 함수
void displayBooksByGenre(struct library lib[], int count) {
  char field_nm[30];
  int found = 0;

  printf("장르명을 입력하시오 : ");
  scanf_s("%s", field_nm, (int)sizeof(field_nm));

  for (int i = 0; i < count; i++) {
    if (strcmp(field_nm, lib[i].fields) == 0) {
      printf("장르 %s에 속한 도서를 출력합니다. \n", field_nm);
      printf("-------------------\n");
      printf("도서명 : %s \n", lib[i].book_name);
      printf("작가명 : %s \n", lib[i].author);
      printf("도서 출판사 : %s \n", lib[i].publisher);
      printf("도서 페이지 :  %d \n ", lib[i].pages);
      printf("도서 가격 % f \n", lib[i].price);
      printf("보유수량 % d \n", lib[i].quantity);
      printf("-------------------\n\n");
      found = 1;
    }
  }

  if (!found) {
    printf(
        "장르를 잘못 입력하셨습니다.\n"
        "프로그램 처음으로 돌아갑니다\n\n");
  }
}

// 도서 종류 수 확인 함수
void displayBookCount(struct library lib[], int count) {
  printf("\n총 도서의 종류:  %d\n", count);
}

// 도서 대출 함수
void borrowBook(struct library lib[], int count) {
  char bk_nm[30];
  int found = 0;
  printf("대출하려는 도서명을 입력하시오: ");
  scanf_s("%s", bk_nm, (int)sizeof(bk_nm));

  for (int i = 0; i < count; i++) {
    if (strcmp(bk_nm, lib[i].book_name) == 0) {
      if (lib[i].quantity == 0) {
        printf("해당 도서는 전권 대출중입니다. \n");
      } else {
        lib[i].quantity -= 1;
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