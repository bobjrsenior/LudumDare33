#pragma once
#include "maze.h"

void getMaze(Maze* maze, int rows, int collumns){
	maze->maze = (int*)realloc(maze->maze, sizeof(int) * rows * collumns);
	for (int e = 0; e < rows * collumns; e++){
		maze->maze[e] = 0;
	}
}

Maze* getNewMaze(int rows, int collumns){
	Maze* temp = (Maze*)malloc(sizeof(Maze));
	temp->rows = rows;
	temp->collumns = collumns;
	temp->maze = (int*)malloc(sizeof(int));
	getMaze(temp, rows, collumns);
	return temp;
}

void getPopulatedMaze(Maze* maze){
	int steps = (maze->rows * maze->collumns) / 2;
	int x = rand() % maze->collumns;
	int y = rand() % maze->rows;
	int heroSpawn = rand() % steps;
	if (heroSpawn < steps / 3){
		heroSpawn = (int)steps / 2;
	}
	printf("Steps: %d\nx: %d\nY: %d\nHero Spawn: %d\n", steps, x, y, heroSpawn);
	maze->maze[(maze->collumns * y) + x] = 1;
	while (steps != 0){
		int good = 0;
		int direction = rand() % 4; //Up Down Left Right
		if (direction == 0){//Up
			if (y != 0){
				good = 1;
				y -= 1;
				if (heroSpawn == 0){
					maze->maze[(maze->collumns * y) + x] = 2;
				}
				else if (maze->maze[(maze->collumns * y) + x] == 0){
					maze->maze[(maze->collumns * y) + x] = 3;
				}
			}
		}
		else if (direction == 1){//Down
			if (y != maze->rows - 1){
				good = 1;
				y += 1;
				if (heroSpawn == 0){
					maze->maze[(maze->collumns * y) + x] = 2;
				}
				else if (maze->maze[(maze->collumns * y) + x] == 0){
					maze->maze[(maze->collumns * y) + x] = 3;
				}
			}
		}
		else if (direction == 2){//Left
			if (x != 0){
				good = 1;
				x += 1;
				if (heroSpawn == 0){
					maze->maze[(maze->collumns * y) + x] = 2;
				}
				else if (maze->maze[(maze->collumns * y) + x] == 0){
					maze->maze[(maze->collumns * y) + x] = 3;
				}
			}
		}
		else if (direction == 3){//Right
			if (x != maze->collumns - 1){
				good = 1;
				x += 1;
				if (heroSpawn == 0){
					maze->maze[(maze->collumns * y) + x] = 2;
				}
				else if (maze->maze[(maze->collumns * y) + x] == 0){
					maze->maze[(maze->collumns * y) + x] = 3;
				}
			}
		}

		if (good){
			steps--;
			heroSpawn--;
		}
	}
}

Maze* getNewPopulatedMaze(int rows, int collumns){
	Maze* temp = getNewMaze(rows, collumns);
	getPopulatedMaze(temp);
	return temp;
}

void printMaze(Maze* maze){
	for (int e = 0; e < maze->rows; e++){
		for (int a = 0; a < maze->collumns; a++){
			printf("%d", maze->maze[(maze->collumns * e) + a]);
		}
		printf("\n");
	}
}