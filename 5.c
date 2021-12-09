#include <stdlib.h> // для перехода на русский язык
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    DIR *dir1;
    DIR *dir2;
    char *currentDirPath = ".";
    char *anotherDirPath = argv[1];


    if ( (dir1 = opendir(currentDirPath)) == NULL ) {
        printf("Не удалось открыть %s", currentDirPath);
        return 1;
    }

    struct dirent *de;
    while (de = readdir(dir1)) {
        printf("%s\n", de->d_name);
    }

    if (errno == -1) {
        printf("Не удалось считать каталог %s", currentDirPath);
        return 1;
    }

    if (closedir(dir1) != 0) {
        printf("Не удалось закрыть каталог %s", currentDirPath);
        return 1;
    }

    if ( (dir2 = opendir(anotherDirPath)) == NULL ) {
        printf("Не удалось открыть %s", anotherDirPath);
        return 1;
    }


    struct dirent *de2;
    while (de2 = readdir(dir2)) {
        printf("%s\n", de2->d_name);
    }

    if (errno == -1) {
        printf("Не удалось считать каталог %s", anotherDirPath);
        return 1;
    } 

    if (closedir(dir2) != 0) {
        printf("Не удалось закрыть каталог %s", anotherDirPath);
        return 1;
    }


    return 0;
}
