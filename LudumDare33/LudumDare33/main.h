/*
* @file main.h
* @brief Function prototypes and includes for main.c
*
*/

//Includes
//Include GLEW  
#include <GL/glew.h>  

//Include GLFW  
#include <GLFW\glfw3.h>
#include "matrixMath.h"
#include "modelList.h"
#include "maze.h"

// Image importing
#include <SOIL.h>

//Include the standard C++ headers  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#include <math.h>

//Callbacks

/**
* @brief the callback for GLFW Errors
*/
static void error_callback(int error, const char* description);

/**
* @brief the callback for GLFW Keyboard Input
*/
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

/**
* @brief the callback for GLFW Mouse Position
*/
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

void createShaderProgram(const GLchar* vertSrc, const GLchar* fragSrc, GLuint* vertexShader, GLuint* fragmentShader, GLuint* shaderProgram);

void specifySceneVertexAttributes(GLuint shaderProgram);

void specifyScreenVertexAttributes(GLuint shaderProgram);

void specifyNewSceneVertexAttributes(GLuint shaderProgram);

GLuint loadTexture(const GLchar* path);