#include <stdio.h> 
#include <locale.h>
#include <conio.h>
#include <string.h>

#define SIZE 100

void show_menu() {
	printf("1 - Ввод выражения\n");
	printf("2 - Проверка выражения\n");
	printf("3 - Выход\n");
}

int push(char* stack, int* sp, char bracket) {
	if (*sp == SIZE - 1) {
		return 0;
	}
	else {
		*(sp) = *(sp)+1;
		stack[*(sp)] = bracket;
		return 1;
	}
}

int pop(char* stack, int* sp) {
	*(sp) = *(sp)-1;
	return stack[*(sp)+1];
}

void view(char* stack, int* sp) {

	if (*(sp) == -1) {
		printf("\nСтек пуст!\n");
	}

	for (int i = 0; i < (*(sp)+1); i++) {
		printf("%c", *(stack + i));
	}
	printf("\n");
}

void write(char* string, int size_string) {

	scanf_s("%s", string, 255);

}

int check(char* string, int size_string, char* stack, int* sp) {

	int flag = 0; 
	int first_iteration = 0;

	for (int i = 0; i < size_string; i++) {

		char bracket = *(string + i);

		if (bracket == '<' || bracket == '(' || bracket == '{' || bracket == '[' || bracket == '>' || bracket == ')' || bracket == '}' || bracket == ']') {
			
			push(stack, sp, bracket);

			//view(stack, sp);

			if (flag == 0) {                               // прпускаем каждую вторую итерацию
				flag = 1;
				continue;
			}

			else {

				if ((((stack[*sp] - stack[*sp - 1]) < 1 ) || ((stack[*sp] - stack[*sp - 1]) > 3))  && (first_iteration != 0)) {     // если скобки разные - выходим

					return 0;

				}

				else {

					pop(stack, sp);                        // выталкиваем пару скобок со стека
					pop(stack, sp);

					first_iteration = 1;
					flag = 0;
				}

			}

		}

	}

	return 1;
}


int main() {

	setlocale(LC_ALL, ".1251");
	char ch;
	int sp = -1;

	char stack[SIZE];

	char string[255] = { 0 };
	int size_string = 255;

	do {

		show_menu();

		scanf_s(" %c", &ch, 1);

		switch (ch) {

		case '0':
			break;

		case '1':

			printf("\nВведите выражение: \n");

			write(string, size_string);

			break;

		case '2':

			if (check(string, size_string, stack, &sp) == 1) {

				printf("\nOk!\n");

			}

			else {

				printf("\nError!\n");

			}

			break;

		case '3':
			break;

		default:
			printf("Неверная операция");
			break;
		}
	} while (ch != '3');
}
