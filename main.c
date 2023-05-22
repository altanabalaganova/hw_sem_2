#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char word[20];
    int i, j, count = 0;
    char *letter;
    char vowels[6] = "aeiouy";

    printf("Введите слово: ");
    scanf("%s", &word);
    letter = word;

    for (i = 0; i < 10 ; i++) {
        for (j = 0; j < 6; j++) {if (*(letter + i) == vowels[j]) {count++;}}
    }

    printf("Гласных букв: %d\nСогласных букв: %d", count, strlen(word)-count);

    return 0;
}
