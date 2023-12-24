#pragma once
#define PASSWORD 123 // 관리자 암호

// 함수 원형 선언
/* 
도서 정보입력
보유 장르 출력
장르별 도서 목록
보유 도서종류수
*/

void addBook(struct library lib[], int* count);
void displayGenres(struct library lib[], int count);
void displayBooksByGenre(struct library lib[], int count);
void displayBookCount(struct library lib[], int count);
void saveLoanBooks(struct loan_book loanBook[], int loanCount,int input_output);
void saveLibrary(struct library lib[], int count, int input_output);