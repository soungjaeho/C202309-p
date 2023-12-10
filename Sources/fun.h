#pragma once
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
void displayBorrowedBooks(struct loan_history loanHistory[], int loanCount);