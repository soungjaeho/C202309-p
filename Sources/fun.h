#pragma once
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
void displayBorrowedBooks(struct loan_history loanHistory[], int loanCount);