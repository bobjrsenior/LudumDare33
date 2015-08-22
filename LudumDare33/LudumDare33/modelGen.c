#pragma once
#include "modelGen.h"

Model* getModel(int* numVertsSource, float* verticesSource){
	Model* temp = (Model*)malloc(sizeof(Model));
	temp->numVerts = numVertsSource;
	temp->vertices = verticesSource;
	return temp;
}

Model* getPlane(){
	Model* temp = (Model*)malloc(sizeof(Model));
	temp->numVerts = &PLANE_NUM_VERTS;
	temp->vertices = &PLANE_VERTICES[0];
	return temp;
}