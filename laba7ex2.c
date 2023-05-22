#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void combSort(char** arr);
void swap_strings(char* x, char* y);
void getWords(char* arr);
void print(char** arr);


int main() {
    int i;
    char** strArr = (char**)malloc(sizeof(char*)*10);

    for (i = 0; i < 10; i++) {strArr[i] = (char*)malloc(sizeof(char));}

    printf("Введите 10 слов для сортировки их по алфавиту: \n");
    for (i = 0; i < 10; i++) {getWords(strArr[i]);}
    combSort(strArr);

    return 0;
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
    printf("Кол-во итераций (CombSort): %d\n", count);
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

void swap_strings(char* x, char* y) {
	char temp[20];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}
