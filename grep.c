/**
 * This program will take a string as a command line argument
 *  and will also take in strings stdin. it will only echo the 
 * stdin string if it contains the key in the command line string.
 */

//shit it still prints out statements when letters are separated by spaces, gotta fix that

//gcc -g -Wall -Wvla -fsanitize=address grep.c -o grep
//on windows: gcc -g -Wall -Wvla grep.c -o grep.exe

#include <stdio.h>
#include <stdlib.h>

int contains(char *one, char *two, int oneLen, int caseSens) {
    int j = 0;
    for(int i = 0; i <= oneLen; i++) {
        if(two[j] == '\0') return 0;
        if(caseSens == 0) {
            if(one[i] == two[j]) j++;
        } else {
            if(one[i] == two[j] || (one[i] - 32) == two[j] || one[i] == (two[j] - 32)) j++;
        }
    }
    return 1;
}

int checkOption(char *arg) {
    if(arg[0] == '-' && arg[1] == 'i' && arg[2] == '\0') {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("No argument provided.\n");
        return 1;
    }

    int cap = checkOption(argv[1]);

    int index = 1 + cap;

    char *matchThis = argv[index];

    char *werd = malloc(2);

    if (!werd) {
        printf("Cannot allocate string.\n");
        return 1;
    }

    int c;
    char *newWerd;
    int end = 0;
    size_t buf = 2;

    while(1) {
        size_t len = 0;

        while (1) {
            if((c = getchar()) == EOF) {
                end = 1;
                break;
            } else if(c == '\n') break;

            if (len + 1 == buf) {
                buf *= 2;
                newWerd = realloc(werd, buf - 1);

                if (!newWerd) {
                    printf("Cannot reallocate string.\n");
                    free(werd);
                    return 1;
                }

            werd = newWerd;

            }

            werd[len++] = c;
        }

        if(end == 1) break;

        werd[len] = '\0';

        if(contains(werd, matchThis, len, cap) == 0) {
            printf("%s\n", werd);
        }
    }

    free(werd);

    return 0;
}
