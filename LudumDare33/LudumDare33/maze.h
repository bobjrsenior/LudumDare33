#include <stdio.h>
#include <stdlib.h>

typedef struct Maze{
	int rows;
	int collumns;
	int* maze;
}Maze;

void getMaze(Maze* maze, int rows, int collumns);

Maze* getNewMaze(int rows, int collumns);

void getPopulatedMaze(Maze* maze);

Maze* getNewPopulatedMaze(int rows, int collumns);

void printMaze(Maze* maze);