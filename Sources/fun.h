#pragma once
#define PASSWORD 123 // ������ ��ȣ

// �Լ� ���� ����
/* 
���� �����Է�
���� �帣 ���
�帣�� ���� ���
���� ����������
*/

void addBook(struct library lib[], int* count);
void displayGenres(struct library lib[], int count);
void displayBooksByGenre(struct library lib[], int count);
void displayBookCount(struct library lib[], int count);
void saveLoanBooks(struct loan_book loanBook[], int loanCount,int input_output);
void saveLibrary(struct library lib[], int count, int input_output);