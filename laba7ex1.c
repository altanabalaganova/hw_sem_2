/* 1) сортировка выбором для словаря из 10 слов обычно работает лучше всего, так как она справляется за наименьшее количество итераций, однако это не всегда так, допустим если словарь уже отсортирован по алфавиту, сортировка выбором потребует большее количество итераций, чем другие
2) каждый метод требует разное время сортировки, пример:
возьмем словарь anna, lena, masha, igor, stas, vlad, kirill, nona, mark, petr:
Кол-во итераций (BubbleSort): 14
Время выполнения:   0.000217
Кол-во итераций (CombSort): 10
Время выполнения:   0.000083
Кол-во итераций (SelectionSort): 6
Время выполнения:   0.000069
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void selectionSort(char** arr);
void bubbleSort(char** arr);
void combSort(char** arr);
void swap_strings(char* x, char* y);
void getWords(char* arr);
void print(char** arr);
void copy(char** arr, char** copyArr);

int main() {
    int i;
    char** strArr = (char**)malloc(sizeof(char*)*10);
    char** copyArr = (char**)malloc(sizeof(char*)*10);
    for (i = 0; i < 10; i++) {strArr[i] = (char*)malloc(sizeof(char)); copyArr[i] = (char*)malloc(sizeof(char));}

    printf("������� 10 ���� ��� ����������: \n");
    for (i = 0; i < 10; i++) {getWords(strArr[i]);}

    printf("�������� ��� ����������:\n1. SelectionSort\n2. BubbleSort\n3. CombSort\n4. ��������� ��\n");
    scanf("%d", &i);

    if (i == 1) {selectionSort(strArr);}
    else if (i == 2) {bubbleSort(strArr);}
    else if (i == 3) {combSort(strArr);}
    else if (i == 4) {
        copy(strArr, copyArr);
        clock_t start = 0, end = 0;
        start = clock();
        selectionSort(copyArr);
        end = clock();
        printf("����� ����������: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        copy(strArr, copyArr);
        start = 0, end = 0;
        start = clock();
        bubbleSort(copyArr);
        end = clock();
        printf("����� ����������: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        start = 0, end = 0;
        start = clock();
        combSort(strArr);
        end = clock();
        printf("����� ����������: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        }
    return 0;
}

void selectionSort(char** arr) {
    printf("SelectionSort:\n");
    int i, j, min_idx, count = 0, size = 10;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
          if (strcmp(arr[j], arr[min_idx]) < 0)
              min_idx = j;
        }
        if (min_idx != i) {
            swap_strings(arr[min_idx], arr[i]);
            print(arr);
            count += 1;
        }
    }
    printf("���������� �������� ��� SelectionSort: %d\n", count);
}

void bubbleSort(char** arr) {
    printf("BubbleSort:\n");
    int i, j, count = 0, size = 10;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap_strings(arr[j], arr[j + 1]);
                print(arr);
                count += 1;
            }
        }
    }
    printf("���������� �������� ��� BubbleSort: %d\n", count);
}

void combSort(char** arr) {
    printf("CombSort:\n");

    int count = 0, size = 10, swapped = 1;
    float gap = (size/1.3);

    while(gap > 1 || swapped) {
        swapped = 0;
        if (gap < 1) {gap = 1;}
        int igap = (int) gap;

        for(int i = 0; i + igap < size; i++) {
            if(strcmp(arr[i], arr[i +igap]) > 0) {swap_strings(arr[i], arr[i + igap]); swapped = 1; print(arr); count += 1;}
        }
        gap /= 1.3;
    }
    printf("���������� �������� ��� CombSort: %d\n", count);
}

void print(char** arr) {
    printf("[");
    for (int i = 0; i < 10; i++) {
        if (i == 9) {printf("%s", arr[i]);}
        else {printf("%s, ", arr[i]);}
    }
    printf("]\n");
}

void getWords(char* arr) {
    char str[20];
    scanf("%s", str);
    strcpy(arr, str);
}

void copy(char** arr, char** copyArr) {
    for (int i = 0; i < 10; i++) {strcpy(copyArr[i], arr[i]);}
}

void swap_strings(char* x, char* y) {
	char temp[20];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}
