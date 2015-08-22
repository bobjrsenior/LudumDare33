#pragma once
#include "maze.h"

void getMaze(Maze* maze, int rows, int collumns){

}

Maze* getNewMaze(int rows, int collumns){
	Maze* temp = (Maze*)malloc(sizeof(Maze));
	getMaze(temp, rows, collumns);
	return temp;
}