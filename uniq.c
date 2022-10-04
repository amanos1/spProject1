/**
 * reads from stdin and returns the same strings minus the 
 * consecutive duplicates. also print how many consecutive duplicates of each string there are.
 */
int main(int argc, char *argv[]) {
    char *werd = malloc(2);
    char **collection = malloc(sieof(char *) * 2);

    if (!werd) {
        printf("Cannot allocate string.\n");
        return 1;
    }

    int c;
    char *newWerd;
    int end = 0;
    size_t buf = 2;

    char **newCollection;
    size_t listSize;
    size_t buf2 = 2;

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

        if(contains(werd, matchThis, len, cap) == 0) {
            printf("%s\n", werd);
        }
    }

    free(werd);

    return 0;
}
