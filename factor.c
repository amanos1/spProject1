/**
 * This program takes in a number from the command line and returns the prime factors of that number
 * Compile using gcc -g -Wall -Wvla -fsanitize=address factor.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  //Read in the number to find factors of
  int toCheck;
  toCheck = atoi(argv[1]);
  
  int i;
  for(i = 2; toCheck > 1; i++){
    while(toCheck % i == 0){
      printf("%d ", i);
      toCheck = toCheck / i;
    }
  }
  printf("\n")
  return 0 
}
