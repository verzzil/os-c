#include <stdlib.h> // для перехода на русский язык
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *file;
    char *fristPartPath = "./";
    char *secondPartPath = argv[1];
    char path[512];
    int N = strtol(argv[2], NULL, 10);
    
    snprintf(path, sizeof path, "%s%s", fristPartPath,secondPartPath);

	if ((file = fopen(path, "r")) == NULL) {
    	printf("Не удалось открыть файл");
    	return 1;
    }

    int i = 0;
    char c = 0;
    char space = ' ';
    while ( (c = fgetc(file)) != EOF ) {
    	if (i == N && N != 0) {
    		scanf("%c", &space);
    		i = 0;
    	}
    	printf("%c", c);
		i++;
    }

    if ((fclose(file)) == EOF) {
    	printf("Не удалось закрыть файл");
    	return 1;
    }
	return 0;
}