#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include "main_struct.h"

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
        "장르를 잘못 입력하셨습니다.\n"
        "프로그램 처음으로 돌아갑니다\n\n");
  }
}

// 도서 종류 수 확인 함수
void displayBookCount(struct library lib[], int count) {
  printf("\n총 도서의 종류:  %d\n", count);
}
