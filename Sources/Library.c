#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 도서관 구조체
struct library {
	char book_name[20];
	char author[20];
	char fields[20];
	char publisher[20];
	int pages;
	float price;
};

int main()
{

	struct library lib[100];

	char field_nm[30], bk_nm[30];



	int i = 0; int input = 0; int count = 0;


	while (input != 5) {

		printf("----------------\n"
			"도서 관리 시스템\n"
			"----------------\n");
		printf("\n\n");
		printf("1. 도서 정보 추가 (관리자 전용)\n"
			"2. 보유 장르 확인\n"
			"3. 장르별 도서 확인\n"
			"4. 도서 수 확인\n"
			"5. 프로그램 종료\n");

		
		printf("\n\n선택지를 입력하시오: ");
		scanf_s("%d", &input);
		int password;
		switch (input) {

			// 책 정보 입력
		case 1:
			printf("관리자 암호를 입력하시오 : ");
			scanf_s("%d", &password);
			if (password == 123) {

				printf("도서의 이름을 입력하시오 : ");
				scanf_s("%s", lib[i].book_name, (int)sizeof(lib[i].book_name));

				printf("작가의 이름을 입력하시오 : ");
				scanf_s("%s", lib[i].author, (int)sizeof(lib[i].author));

				printf("도서의 장르를 입력하시오 : ");
				scanf_s("%s", lib[i].fields, (int)sizeof(lib[i].fields));

				printf("도서의 출판사를 입력하시오 : ");
				scanf_s("%s", lib[i].publisher, (int)sizeof(lib[i].publisher));

				printf("전체 페이지를 입력하시오 : ");
				scanf_s("%d", &lib[i].pages, (int)sizeof(lib[i].pages));

				printf("도서의 가격을 입력하시오 :  ");
				scanf_s("%f", &lib[i].price, (int)sizeof(lib[i].price));
				printf("\n\n");
				i++; // i가 변함이없어서 계속 같은위치에 저장 -> 책 1권만 저장중이었던거라 case 3 오류
				count++;

				break;
			}
			else
			{
				printf("올바르지 못한 암호입니다.\n\n");

				break;
			}

		case 2:
			printf("보유하고 있는 장르 목록\n");

			// 장르 
			char printedGenres[20][20];
			int printedCount = 0;

			for (int j = 0; j < count; j++) {
				// 현재 도서의 장르가 이미 출력한 장르 목록에 없으면 출력
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
			break;

		case 3:
			printf("장르명을 입력하시오 : ");
			scanf_s("%s", field_nm, (int)sizeof(field_nm));
			int found = 0;
			for (i = 0; i < count; i++) {
				

				if (strcmp(field_nm, lib[i].fields) == 0) {
					printf("장르 %s에 속한 도서를 출력합니다. \n", field_nm);
					printf("-------------------\n");
					printf("도서명 : %s \n", lib[i].book_name);
					printf("작가명 : %s \n", lib[i].author);
					printf("도서 출판사 : %s \n", lib[i].publisher);
					printf("도서 페이지 :  %d \n ", lib[i].pages);
					printf("도서 가격 % f \n", lib[i].price);
					printf("-------------------\n\n");
					found = 1;
				}

				if (!found) {
					printf("장르를 잘못 입력하셨습니다.\n");
					printf("프로그램 처음으로 돌아갑니다\n\n");
				}
			}
			break;

			// 총 도서수 출력
		case 4:
			printf("\n 총 도서 수:  %d\n", count);
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}
