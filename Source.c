#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double max_to_k(double* ptr_array, int n, int k);

int main(void) {
	srand((unsigned)time(NULL));
	setlocale(LC_CTYPE, "RUS");
	double array[N], element;
	int size, begin, end, k;
	printf("Введите размер массива: ");
	scanf("%d", &size);
	// 1
	full_elements(array, size);
	printf("\nисходный массив:\n");
	put_elements(array, size);
	calc_elements(array, size);
	printf("\nмассив после обработки:\n");
	put_elements(array, size);
	printf("\n\n");
	// 2
	printf("Введите начальный индекс: ");
	scanf("%d", &begin);
	printf("Введите конечный индекс: ");
	scanf("%d", &end);
	printf("сумма элементов массива с %d по %d = %5lf\n", begin, end, sum_elements(array, begin, end));
	printf("введите элемент для поиска: ");
	scanf("%lf", &element);
	printf("элемент был найден (индекс - да, -1 - нет) = %d\n", find_element(array, size, element));
	printf("\n\n");
	// 3
	printf("Введите значение k: ");
	scanf("%d", &k);
	printf("максимальный элемент среди первых %d элементов = %5lf\n", k+1, max_to_k(array, size, k));
	return 0;
}

double max_to_k(double* ptr_array, int n, int k)
{
	double max = ptr_array[0];
	for (int i = 1; i <= k && i < n; i++) {
		if (ptr_array[i] > max)
			max = ptr_array[i];
	}
	return max;
}

int find_element(double* ptr_array, int n, double element) {
	for (int i = 0; i < n; i++) {
		if (ptr_array[i] == element) {
			return i;
		}
	}
	return -1;
}

double sum_elements(double* ptr_array, int begin, int end) {
	double sum = 0;
	for (int i = begin; i <= end; i++) {
		sum += ptr_array[i];
	}
	return sum;
}

double* full_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++) {
		ptr_array[i] = (rand() % 10001) / 100. - 50.;
	}
	return ptr_array;
}

int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++) {
		printf("array[%d] = %5lf\n", i, ptr_array[i]);
	}
	return n;
}

double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++) {
		ptr_array[i] = ptr_array[i] * ptr_array[i];
	}
	return ptr_array;
}