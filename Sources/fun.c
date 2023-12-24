#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include "struct_library.h"

// 도서 추가 함수, 관리자 선택지(관리자 암호 123추가)
void addBook(struct library lib[], int* count) {
  int password;
  printf("관리자 암호를 입력하시오 : ");
  scanf_s("%d", &password);

  if (password == PASSWORD) {
    printf("도서의 이름을 입력하시오 : ");
    getchar();// 버퍼제거
    scanf_s("%[^\n]", lib[*count].book_name, (int)sizeof(lib[*count].book_name));
    getchar();

    printf("작가의 이름을 입력하시오 : ");
    scanf_s("%[^\n]", lib[*count].author, (int)sizeof(lib[*count].author));
    getchar();

    printf("도서의 장르를 입력하시오 : ");
    scanf_s("%[^\n]", lib[*count].fields,
            (int)sizeof(lib[*count].fields) );
    getchar();

    printf("도서의 출판사를 입력하시오 : ");
    scanf_s("%[^\n]", lib[*count].publisher,
            (int)sizeof(lib[*count].publisher) );
    // 문자열을 입력받을때(도서명, 작가명, 장르, 출판사) 띄어쓰기를 포함하여 입력받기
    getchar();
    printf("전체 페이지를 입력하시오 : ");
    if (scanf_s("%d", &lib[*count].pages, (int)sizeof(lib[*count].pages)) !=1) {
      printf("페이지는 숫자로 입력해주세요.\n");
      while (getchar() != '\n');
      return;
    }

    printf("도서의 가격을 입력하시오 :  ");
    if (scanf_s("%f", &lib[*count].price, (int)sizeof(lib[*count].price)) !=1) {
      printf("가격은 숫자로 입력해주세요.\n");
      while (getchar() != '\n');
      return;
    }

    printf("도서의 수량을 입력하시오 :  ");
    if (scanf_s("%d", &lib[*count].quantity,(int)sizeof(lib[*count].quantity)) != 1) {
      printf("수량은 숫자로 입력해주세요.\n");
      while (getchar() != '\n');
      return;
    }
    // 페이지, 가격, 수량은 숫자만 입력가능하게 설정
    printf("\n도서 추가 완료!\n\n");
    (*count)++;
  } else {
    printf("올바르지 못한 암호입니다.\n\n");
  }
}// 도서 정보 입력  -> 도서명 작가명 장르 출판사 페이지 가격 수량


// 보유 장르 확인 함수
void displayGenres(struct library lib[], int count) {
  printf("보유하고 있는 장르 목록\n");

  char printedGenres[20][20];// 출력한 장르 배열
  int printedCount = 0;

  for (int j = 0; j < count; j++) {
    int genrePrinted = 0; // 출력한 장르인지
    for (int k = 0; k < printedCount; k++) {
      if (strcmp(lib[j].fields, printedGenres[k]) == 0) {// 해당어 장르가 출력한장르에 있는지 확인
        genrePrinted = 1;
        break;
      }
    }
    // 출력한 장르면 건너뛰기

    if (!genrePrinted) {
      printf("%d번 장르: %s\n", printedCount+1, lib[j].fields);
      strcpy_s(printedGenres[printedCount], 20, lib[j].fields);  // 출력한 장르는 출력한장르 배열로 복사
      printedCount++; // 출력한장르수
    }
  }
} //요약 : 입력한 도서의 종류수만큼 반복 장르를 출력한 장르에 저장,  출력한적 없는 장르  = 출력, 출력한 장르 수 증가

// 장르별 도서 정보 확인 함수
void displayBooksByGenre(struct library lib[], int count) {
  char field_nm[30];
  int found = 0;

  printf("장르명을 입력하시오 : ");
  scanf_s(" %[^\n]", field_nm, (int)sizeof(field_nm));
  getchar();

  for (int i = 0; i < count; i++) {
    if (strcmp(field_nm, lib[i].fields) == 0) {
      printf("장르 %s에 속한 도서를 출력합니다. \n", field_nm);
      printf("-------------------\n");
      printf("도서명 : %s \n", lib[i].book_name);
      printf("작가명 : %s \n", lib[i].author);
      printf("도서 출판사 : %s \n", lib[i].publisher);
      printf("도서 페이지 : %d \n", lib[i].pages);
      printf("도서 가격 % f \n", lib[i].price);
      printf("보유수량 % d \n", lib[i].quantity);
      if (lib[i].quantity == 0) {
        printf("대출불가!\n");
      } else {
        printf("대출가능!\n");
      }
      printf("-------------------\n\n");
      found = 1;
    }
  }

  if (!found) {
    printf(
        "\n장르를 잘못 입력하셨습니다.\n\n"
        "프로그램 처음으로 돌아갑니다\n\n");
  }
}// 입력한 장르와 일치하는 도서의 정보를 출력

// 도서 종류 수 확인 함수
void displayBookCount(struct library lib[], int count) {
  printf("\n총 도서의 종류:  %d\n", count);
}

// 도서 정보 파일로 저장 함수
void saveLibrary(struct library lib[], int count, int input_output) {
  FILE* file;
  const char* File_Type;
  if (input_output == 1) {
    File_Type = "library.txt";
  } else if (input_output == 2) {
    File_Type = "library.csv ";
  } else {
    printf("잘못 입력하셨습니다. \n");
    return;
  }
  if (fopen_s(&file, File_Type, "w") != 0) {// 쓰기 모드로 파일열기
    printf("파일을 열 수 없습니다.\n");
    return;
  }

  // 필드 이름 저장
  fprintf(file, "도서명,작가명,장르,출판사,수량,페이지,가격\n");

  for (int i = 0; i < count; i++) {
    fprintf(file, "%s,%s,%s,%s,%d,%d,%.2f\n", lib[i].book_name, lib[i].author,
            lib[i].fields, lib[i].publisher, lib[i].quantity, lib[i].pages,
            lib[i].price);
  }// 도서 정보를 파일에 입력

  fclose(file);
  printf("도서 정보가 파일에 저장되었습니다.\n");
}
// 대출 도서 정보 파일로 저장 함수
void saveLoanBooks(struct loan_book loanBook[], int loanCount,
                   int input_output) {
  FILE* file;
  const char* File_Type;
  if (input_output == 1) {
    File_Type = "loan_books.txt";
  } else if (input_output == 2) {
    File_Type = "loan_books.csv";
  } else {
    printf("잘못 입력하셨습니다. \n");
    return;
  }
  if (fopen_s(&file, File_Type, "w") != 0) {// 쓰기모드로 파일 열기
    printf("파일을 열 수 없습니다.\n");
    return;
  }

  fprintf(file, "도서명,수량\n");

  for (int i = 0; i < loanCount; i++) {
    fprintf(file, "%s,%d\n", loanBook[i].book_name, loanBook[i].quantity);
  }// 필드 이름 저장 : 대출한 도서라서 도서명과 대출 수량만 필요

  fclose(file);
  printf("대출 도서 정보가 파일에 저장되었습니다.\n");
}
