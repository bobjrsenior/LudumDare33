#include "modelList.h"
#include <stdlib.h>

typedef struct Model{
	int* numVerts;
	float* vertices;
}Model;

Model* getModel(int* numVertsSource, float* verticesSource);

Model* getPlane();