/**
 * This program will take a string as a command line argument
 *  and will also take in strings stdin. it will only echo the 
 * stdin string if it contains the key in the command line string.
 */

//gcc -g -Wall -Wvla -fsanitize=address grep.c -o grep
//on windows: gcc -g -Wall -Wvla grep.c -o grep.exe

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *str = malloc(2);

    if (!str) {
        printf("Cannot allocate string.\n");
        return 1;
    }

    int c;
    char *reallocStr;
    int end = 0;
    size_t buf = 2;

    while(1) {
        size_t len = 0;
        printf("Enter some text: ");

        while (1) {
            if((c = getchar()) == EOF) {
                end = 1;
                break;
            } else if(c == '\n') break;

            if (len + 1 == buf) {
                buf *= 2;
                reallocStr = realloc(str, buf - 1);

                if (!reallocStr) {
                    printf("Cannot reallocate string.\n");
                    free(str);
                    return 1;
                }

            str = reallocStr;

            }

            str[len++] = c;
        }

        if(end == 1) break;

        str[len] = '\0';

        printf("You entered: %s\n", str);
    }

    free(str);

    return 0;
}
