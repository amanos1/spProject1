/**
 * This program creates a game where the player 
 * tries to get to a treasure while avoiding a monster.
 */

//gcc -g -Wall -Wvla -fsanitize=address monster.c -o monster
//on windows: gcc -g -Wall -Wvla monster.c -o monster.exe

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
			if(i == plrY && j == plrX)
				printf("P");
			else if(i == goalY && j == goalX)
				printf("G");
			else if(i == monY && j == monX)
				printf("M");
			else
				printf(".");
			if(j < boardX - 1)
				printf(" ");
		}
		printf("\n");
	}
}

int movePlayer(char dir) {
	int ugh = 0;
	switch(dir) {
		case 'N':
			if(plrY < boardY-1) {
				plrY++;
				ugh = 1;
			}
			break;
		case 'W':
			if(plrX > 0) {
				plrX--;
				ugh = 1;
			}
			break;
		case 'E':
			if(plrX < boardX-1) {
				plrX++;
				ugh = 1;
			}
			break;
		case 'S':
			if(plrY > 0) {
				plrY--;
				ugh = 1;
			}
	}
	if(ugh == 0) {
		printf("invalid move\n");
	}
	return ugh;
}

int abs(int a) {
	if(a < 0)
		return a * -1;
	return a;
}

void monsterFollows() {
	int distX = monX - plrX;
	int distY = monY - plrY;
	char dir;
	if(abs(distX) >= abs(distY)) {
		if(distX == 0) return;
		if(distX < 0) {
			dir = 'E';
			monX++;
		} else {
			dir = 'W';
			monX--;
		}
	} else {
		if(distY < 0) {
			dir = 'N';
			monY++;
		} else {
			dir = 'S';
			monY--;
		}
	}
	printf("monster moves %c\n", dir);
}

int didWin() {
	if(plrX == goalX && plrY == goalY) {
		printf("player wins!\n");
		return 1;
	}
	return 0;
}

int didLose() {
	if(plrX == monX && plrY == monY) {
		printf("monster wins!\n");
		return 1;
	}
	return 0;
}

void gameLoop() {
	while(1) {
		printBoard();
		int kachiga = 0;
		do {
			char command;
			scanf("%1s", &command);
			kachiga = movePlayer(command);
		} while(kachiga == 0);
		if(didWin()) break;
		monsterFollows();
		if(didLose()) break;
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

	gameLoop();

	return 0;
}
