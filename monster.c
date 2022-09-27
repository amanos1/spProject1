/**
 * This program creates a game where the player 
 * tries to get to a treasure while avoiding a monster.
 */

//gcc -g -Wall -Wvla -fsanitize=address monster.c -o monster.exe
#include <stdio.h>
#include <stdlib.h>

int boardX;
int boardY;
int plrX;
int plrY;
int goalX;
int goalY;
int monX;
int monY;

void printBoard() {
	for(int i = boardY-1; i >= 0; i--) {
		for(int j = 0; j < boardX; j++) {
			if(j > 0)
				printf(" ");
			if(i == plrX && j == plrY)
				printf("P");
			else if(i == goalX && j == goalY)
				printf("G");
			else if(i == monX && j == monY)
				printf("M");
			else
				printf(".");
			if(j < boardX - 1)
				printf(" ");
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	if(argc != 9) {
		printf("who invited this kid?");
		return 1;
	}

	boardX = atoi(argv[1]);
	boardY = atoi(argv[2]);
	plrX = atoi(argv[3]);
	plrY = atoi(argv[4]);
	goalX = atoi(argv[5]);
	goalY = atoi(argv[6]);
	monX = atoi(argv[7]);
	monY = atoi(argv[8]);

	printBoard();

	return 0;
}
