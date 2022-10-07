/**
 * reads from stdin and returns the same strings minus the 
 * consecutive duplicates. also print how many consecutive duplicates of each string there are.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wordNode{
	char *word;
	int frequency;
	 
	struct wordNode *next;
} wordNode;


char *readstrings(FILE* input, size_t size){
	char *string;
	int character;
	size_t length = 0;
	
	string = realloc(NULL, sizeof(*string)*size);
	if(!string){
		return string;
	}
	while(EOF != (character=fgetc(input)) && character != '\n'){
		string[length++] = character;
		if(length == size){
			string = realloc(string, sizeof(*string)*(size+=8));
			if(!string){
				return string;
			}
		}
	}
	string[length++] = '\0';
	 
	return realloc(string, sizeof(*string)*length);
}

int main(int argc, char** argv){
	//char *temp;

	wordNode *head = NULL;
	head = malloc(sizeof(wordNode));
	head->word = NULL;
	head->frequency = 0;
	
	wordNode *pointer = head;

	while(!(feof(stdin))){
		char *tempWord = pointer->word;
		char *tempWord2 = readstrings(stdin, 10);

		
		if(tempWord == NULL || strcmp(tempWord,tempWord2) != 0){
			
			wordNode *after = malloc(sizeof(wordNode));
			after->word = tempWord2;
			after->frequency = 1;
			after->next = NULL;
			

			pointer->next = after;
			pointer = after; 
		}
		else if(strcmp(tempWord, tempWord2) == 0){
			pointer->frequency +=1;
			free(tempWord2);
		}
	}
	
	pointer = head->next;
	free(head);
	while(pointer->next != NULL){
		printf("%d %s\n", pointer->frequency, pointer->word);
		free(pointer->word);
		wordNode *temp = pointer;
		pointer = pointer->next;
		free(temp);
	}
	free(pointer->word);
	free(pointer);
	return 0;
}		
