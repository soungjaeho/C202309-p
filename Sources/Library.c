#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ ����ü
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
			"���� ���� �ý���\n"
			"----------------\n");
		printf("\n\n");
		printf("1. ���� ���� �߰� (������ ����)\n"
			"2. ���� �帣 Ȯ��\n"
			"3. �帣�� ���� Ȯ��\n"
			"4. ���� �� Ȯ��\n"
			"5. ���α׷� ����\n");

		
		printf("\n\n�������� �Է��Ͻÿ�: ");
		scanf_s("%d", &input);
		int password;
		switch (input) {

			// å ���� �Է�
		case 1:
			printf("������ ��ȣ�� �Է��Ͻÿ� : ");
			scanf_s("%d", &password);
			if (password == 123) {

				printf("������ �̸��� �Է��Ͻÿ� : ");
				scanf_s("%s", lib[i].book_name, (int)sizeof(lib[i].book_name));

				printf("�۰��� �̸��� �Է��Ͻÿ� : ");
				scanf_s("%s", lib[i].author, (int)sizeof(lib[i].author));

				printf("������ �帣�� �Է��Ͻÿ� : ");
				scanf_s("%s", lib[i].fields, (int)sizeof(lib[i].fields));

				printf("������ ���ǻ縦 �Է��Ͻÿ� : ");
				scanf_s("%s", lib[i].publisher, (int)sizeof(lib[i].publisher));

				printf("��ü �������� �Է��Ͻÿ� : ");
				scanf_s("%d", &lib[i].pages, (int)sizeof(lib[i].pages));

				printf("������ ������ �Է��Ͻÿ� :  ");
				scanf_s("%f", &lib[i].price, (int)sizeof(lib[i].price));
				printf("\n\n");
				i++; // i�� �����̾�� ��� ������ġ�� ���� -> å 1�Ǹ� �������̾����Ŷ� case 3 ����
				count++;

				break;
			}
			else
			{
				printf("�ùٸ��� ���� ��ȣ�Դϴ�.\n\n");

				break;
			}

		case 2:
			printf("�����ϰ� �ִ� �帣 ���\n");

			// �帣 
			char printedGenres[20][20];
			int printedCount = 0;

			for (int j = 0; j < count; j++) {
				// ���� ������ �帣�� �̹� ����� �帣 ��Ͽ� ������ ���
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
			printf("�帣���� �Է��Ͻÿ� : ");
			scanf_s("%s", field_nm, (int)sizeof(field_nm));
			int found = 0;
			for (i = 0; i < count; i++) {
				

				if (strcmp(field_nm, lib[i].fields) == 0) {
					printf("�帣 %s�� ���� ������ ����մϴ�. \n", field_nm);
					printf("-------------------\n");
					printf("������ : %s \n", lib[i].book_name);
					printf("�۰��� : %s \n", lib[i].author);
					printf("���� ���ǻ� : %s \n", lib[i].publisher);
					printf("���� ������ :  %d \n ", lib[i].pages);
					printf("���� ���� % f \n", lib[i].price);
					printf("-------------------\n\n");
					found = 1;
				}

				if (!found) {
					printf("�帣�� �߸� �Է��ϼ̽��ϴ�.\n");
					printf("���α׷� ó������ ���ư��ϴ�\n\n");
				}
			}
			break;

			// �� ������ ���
		case 4:
			printf("\n �� ���� ��:  %d\n", count);
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}
