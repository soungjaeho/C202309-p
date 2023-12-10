#pragma once

void borrowBook(struct library lib[], int count);
void displayBorrowedBooks(struct loan_history loanHistory[], int loanCount);
void returnBook(struct library lib[], int count,struct loan_history loanHistory[], int* loanCount);
