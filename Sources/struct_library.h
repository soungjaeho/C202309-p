#pragma once
// ������ ����ü(������ �۰��� �帣 ���ǻ� ���� ������ ����)
struct library {
  char book_name[20];
  char author[20];
  char fields[20];
  char publisher[20];
  int quantity;
  int pages;
  float price;
};

// ������ ���� ���� ����ü(������ ���� )
struct loan_book {
  char book_name[20];
  int quantity;
  
};
