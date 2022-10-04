/**
 * this program will take strings in through stdin until stdin is closed.
 * it will then echo back all the strings in a topographically sorted order.
 * can have a flag -n which indicates numeric sorting, otherwise case-insensitive lexicographic sorting
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
typedef struct wordNode{
	char *word;
	 
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

void addNode(wordNode **head, wordNode *toAdd){

	if(*head == NULL){
		*head = toAdd;
		return;
	}
	else if(strcasecmp((*head)->word, toAdd->word) > 0){
		toAdd->next = *head;
		*head = toAdd;
		return;
	}
	else{
		wordNode *current = *head;
		while(current->next != NULL && strcasecmp(current->next->word, toAdd->word) <= 0){
			current = current->next;
		}
		toAdd->next = current->next;
		current->next = toAdd;
		return;
	}	
						
}

int cmpfunc(const void *a, const void *b){
	return (*(int*)a-*(int*)b);
}

int main(int argc, char *argv[]){
	if(argc > 1){
		//printf("there\n");
		char* flagChecker;
		flagChecker = argv[1];
		//printf("%s\n", flagChecker);
		if(strcmp(flagChecker,"-n") == 0){
			
			//printf("here\n");
			int* input = NULL;
			int currentCapacity = 0;
			int i = 0;
			
			while(!feof(stdin)){
				if(i >= currentCapacity){
					currentCapacity += 4;
					input = realloc(input, sizeof(int) * currentCapacity);
				}
				
				scanf("%d", &input[i]);
				i++;
			}
			int k;
			for(k = 0; k < i-1; k++){
				printf("%d\n", input[k]);
			}
			qsort(input,i-1,sizeof(int),cmpfunc);
		        for(k = 0; k < i-1; k++){
			       printf("%d\n", input[k]);
			}
			free(input);	       

		}		
	}
	else{
		
			//wordNode *head = NULL;
		
		wordNode *pointer = NULL;
		
		while(!(feof(stdin))){
			//Create the node
			char *tempWord = readstrings(stdin, 10);
			

			wordNode *after = malloc(sizeof(wordNode));
			after->word = tempWord;
			after->next = NULL;
			
			//Add it to the list
			addNode(&pointer, after);
		}
		
		while(pointer != NULL){
			printf("%s\n", pointer->word);
			free(pointer->word);
			wordNode *temp = pointer;
			pointer = pointer->next;
			free(temp);
		}
			
	}
	return 0;
}

