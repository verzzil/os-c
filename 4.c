#include <stdlib.h> // для перехода на русский язык
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file1;
	FILE *file2;
    char *fristPartPath = "./";
    char *secondPartPath = argv[1];
    char *thirdPartPath = argv[2];
    char firstPath[512];
    char secondPath[512];

    snprintf(firstPath, sizeof firstPath, "%s%s", fristPartPath, secondPartPath);
    snprintf(secondPath, sizeof secondPath, "%s%s", fristPartPath, thirdPartPath);


    if ((file1 = fopen(firstPath, "r")) == NULL) {
        printf("Не удалось открыть файл 1");
        return 1;
    }
    if ((file2 = fopen(secondPath, "w")) == NULL) {
        printf("Не удалось открыть файл 2");
        return 1;
    }

    char s = ' ';
    while ((s = fgetc(file1)) != EOF) {
        if ((fputc((int) s, file2))== EOF) {
            printf("Не удалось записать в файл 2");
            return 1;
        }
    }

    if ((fclose(file1)) == EOF) {
        printf("Не удалось закрыть файл 1");
        return 1;
    }
    if ((fclose(file2)) == EOF) {
        printf("Не удалось закрыть файл 2");
        return 1;
    }
}