#include <stdio.h>
#include <stdlib.h> // для перехода на русский язык
#include <string.h>

int main (int argc, char * argv[]) {
    FILE *file;
    char *fristPartPath = "./";
    char *secondPartPath = argv[1];
    char path[512];
    snprintf(path, sizeof path, "%s%s", fristPartPath, secondPartPath);
    
    char currentSymbol = ' ';

    if ((file = fopen(path, "w")) == NULL) {
    	printf("Не удалось открыть файл");
    	return 0;
    }

    while (1) {
		scanf(" %s", &currentSymbol);
		if (strcmp(&currentSymbol, "!") == 0) {
			break;
		}

		if ((fputc((int) currentSymbol, file)) == EOF) {
			printf("Не удается записать в файл");
    		return 0;
		}
    }

    if ((fclose(file)) == EOF) {
    	printf("Не удалось закрыть файл");
    	return 0;
    }
    return 0;
 }
