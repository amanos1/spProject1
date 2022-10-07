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
	if(dir == 'N' && plrY < boardY - 1) {
		plrY++;
		return 1;
	} else if(dir == 'W' && plrX > 0) {
		plrX--;
		return 1;
	} else if(dir == 'E' && plrX < boardX - 1) {
		plrX++;
		return 1;
	} else if(dir == 'S' && plrY > 0) {
		plrY--;
		return 1;
	}
	printf("invalid move\n");
	return 0;
}

int abs(int a) {
	if(a < 0)
		return a * -1;
	return a;
}

int randIO() {
	return rand() % 2;
}

void monsterFollows() {
	int distX = monX - plrX;
	int distY = monY - plrY;
	char dir;
	if(abs(distX) == abs(distY)) {
		if(randIO() == 0) {
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
	} else if(abs(distX) > abs(distY)) {
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
		while(kachiga == 0) {
			char command;
			scanf(" %c", &command);
			kachiga = movePlayer(command);
		}
		if(didWin()) break;
		monsterFollows();
		if(didLose()) break;
	}
}

int main(int argc, char *argv[]) {
	if(argc != 9) {
		printf("you need the right amount of inputs!!!");
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
	
	if(boardX < 0 || boardY < 0 || plrX < 0 || plrY < 0 || goalX < 0 || goalY < 0 || monX < 0 || monY < 0) {
		printf("no negative numbers!");
		return 1;
	}
	
	gameLoop();

	return 0;
}
