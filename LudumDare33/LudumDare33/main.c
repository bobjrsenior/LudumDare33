#pragma once
#include "main.h"

// Shader macro
#define GLSL(src) "#version 150 core\n" #src

bool keys[349];

vec2* mousePos;
vec3* mouseChange;

//Cube Vertices
GLfloat cubeVertices[] = {
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

	-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
};

GLuint elements[] = {
	0, 1, 2,
	2, 3, 0
};

// Quad vertices
GLfloat quadVertices[] = {
	-1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, 1.0f, 0.0f,

	1.0f, -1.0f, 1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f, 0.0f,
	-1.0f, 1.0f, 0.0f, 1.0f
};

// Shader sources
const GLchar* sceneVertexSource = GLSL(
	in vec3 position;
	in vec3 color;
	in vec2 texcoord;
	out vec3 Color;
	out vec2 Texcoord;
	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 proj;
	uniform vec3 overrideColor;
	void main() {
	   Color = overrideColor * color;
	   Texcoord = texcoord;
	   gl_Position = proj * view * model * vec4(position, 1.0);
	}
);
const GLchar* sceneFragmentSource = GLSL(
	in vec3 Color;
	in vec2 Texcoord;
	out vec4 outColor;
	uniform sampler2D texKitten;
	void main() {
	   outColor = vec4(Color, 1.0) * texture(texKitten, Texcoord);
	}
);

// Shader sources
const GLchar* newSceneVertexSource = GLSL(
	in vec3 position;
	in vec2 texcoord;
	out vec3 Color;
	out vec2 Texcoord;
	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 proj;
	uniform vec3 overrideColor;
	void main() {
		Color = overrideColor;
		Texcoord = texcoord;
		gl_Position = proj * view * model * vec4(position, 1.0);
	}
);
const GLchar* newSceneFragmentSource = GLSL(
	in vec3 Color;
	in vec2 Texcoord;
	out vec4 outColor;
	uniform sampler2D texKitten;
	uniform sampler2D texPuppy;
	void main() {
		outColor = vec4(Color, 1.0) * mix(texture(texKitten, Texcoord), texture(texPuppy, Texcoord), 0.5);
	}
);

const GLchar* screenVertexSource = GLSL(
	in vec2 position;
	in vec2 texcoord;
	uniform vec2 screenLoc;
	out vec2 Texcoord;
	void main() {
	   Texcoord = texcoord;
	   gl_Position = vec4(screenLoc[0] + (abs(screenLoc[0]) * position.x), -screenLoc[1] + (abs(screenLoc[1]) * position.y), 0.0, 1.0);
	}
);
const GLchar* screenFragmentSource = GLSL(
	in vec2 Texcoord;
	out vec4 outColor;
	uniform sampler2D texFramebuffer;
	void main() {
	   outColor = texture(texFramebuffer, Texcoord);
	   float avg = 0.2126 * outColor.r + 0.7152 * outColor.g + 0.0722 * outColor.b;
	   outColor = vec4(avg, avg, avg, 1.0);
	}
);

int main(void)
{
	//Initial variables
	mousePos = makeNewVec2(0.0f, 0.0f);
	mouseChange = makeNewVec3(0.0f, 0.0f, 0.0f);
	srand(time(NULL));
	//Set the error callback  
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW  
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Set the GLFW window creation hints - these are optional  
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version  
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version  
	//glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing  
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  

	//Declare a window object  
	GLFWwindow* window;

	//Create a window and create its OpenGL context  
	//window = glfwCreateWindow(1820, 1080, "Test Window", glfwGetPrimaryMonitor(), NULL);
	window = glfwCreateWindow(800, 600, "Test Window", NULL, NULL);

	//If the window couldn't be created  
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//This function makes the context of the specified window current on the calling thread.   
	glfwMakeContextCurrent(window);

	//Sets the key callback  
	glfwSetKeyCallback(window, key_callback);

	//Set cursor pos callback
	glfwSetCursorPosCallback(window, cursor_position_callback);

	//Initialize GLEW  
	GLenum err = glewInit();

	//If GLEW hasn't initialized  
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return -1;
	}


	glEnable(GL_DEPTH_TEST);
	//Set a background color  
	glfwSwapInterval(1);

	Model* plane = getPlane();

	//New Drawing Test
	// Create Vertex Array Object
	GLuint vaoCube, vaoQuad, vaoPlane;
	glGenVertexArrays(1, &vaoCube);
	glGenVertexArrays(1, &vaoQuad);
	glGenVertexArrays(1, &vaoPlane);
	//glBindVertexArray(vao);

	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vboCube, vboQuad, vboPlane;
	glGenBuffers(1, &vboCube);
	glGenBuffers(1, &vboQuad);
	glGenBuffers(1, &vboPlane);

	glBindBuffer(GL_ARRAY_BUFFER, vboCube);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vboQuad);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vboPlane);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 5 * (*plane->numVerts), plane->vertices, GL_STATIC_DRAW);

	GLuint sceneVertexShader, sceneFragmentShader, sceneShaderProgram;
	createShaderProgram(sceneVertexSource, sceneFragmentSource, &sceneVertexShader, &sceneFragmentShader, &sceneShaderProgram);

	GLuint screenVertexShader, screenFragmentShader, screenShaderProgram;
	createShaderProgram(screenVertexSource, screenFragmentSource, &screenVertexShader, &screenFragmentShader, &screenShaderProgram);

	GLuint sceneNewVertexShader, sceneNewFragmentShader, sceneNewShaderProgram;
	createShaderProgram(sceneVertexSource, newSceneFragmentSource, &sceneNewVertexShader, &sceneNewFragmentShader, &sceneNewShaderProgram);

	// Specify the layout of the vertex data
	glBindVertexArray(vaoCube);
	glBindBuffer(GL_ARRAY_BUFFER, vboCube);
	specifySceneVertexAttributes(sceneShaderProgram);

	glBindVertexArray(vaoQuad);
	glBindBuffer(GL_ARRAY_BUFFER, vboQuad);
	specifyScreenVertexAttributes(screenShaderProgram);

	glBindVertexArray(vaoPlane);
	glBindBuffer(GL_ARRAY_BUFFER, vboPlane);
	specifyNewSceneVertexAttributes(sceneNewShaderProgram);

	// Load textures
	GLuint texKitten = loadTexture("sample.png");
	GLuint texPuppy = loadTexture("sample2.png");

	glUseProgram(sceneShaderProgram);
	glUniform1i(glGetUniformLocation(sceneShaderProgram, "texKitten"), 0);
	glUniform1i(glGetUniformLocation(sceneShaderProgram, "texPuppy"), 1);

	glUseProgram(screenShaderProgram);
	glUniform1i(glGetUniformLocation(screenShaderProgram, "texFramebuffer"), 0);

	// Create frame buffer
	GLuint frameBuffer;
	glGenFramebuffers(1, &frameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

	// Create texture to hold color buffer
	GLuint texColorBuffer;
	glGenTextures(1, &texColorBuffer);
	glBindTexture(GL_TEXTURE_2D, texColorBuffer);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texColorBuffer, 0);

	// Create Renderbuffer Object to hold depth and stencil buffers
	GLuint rboDepthStencil;
	glGenRenderbuffers(1, &rboDepthStencil);
	glBindRenderbuffer(GL_RENDERBUFFER, rboDepthStencil);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rboDepthStencil);

	GLint uniModel = glGetUniformLocation(sceneShaderProgram, "model");

	//Set up projection
	
	GLint uniView = glGetUniformLocation(sceneShaderProgram, "view");

	GLint uniProj = glGetUniformLocation(sceneShaderProgram, "proj");

	GLint uniTime = glGetUniformLocation(sceneShaderProgram, "time");

	GLint uniColor = glGetUniformLocation(sceneShaderProgram, "overrideColor");

	GLint uni2Model = glGetUniformLocation(sceneShaderProgram, "model");

	//Set up projection

	GLint uni2View = glGetUniformLocation(sceneNewShaderProgram, "view");

	GLint uni2Proj = glGetUniformLocation(sceneNewShaderProgram, "proj");

	GLint uni2Time = glGetUniformLocation(sceneNewShaderProgram, "time");

	GLint uni2Color = glGetUniformLocation(sceneNewShaderProgram, "overrideColor");

	GLint uniScreenLoc = glGetUniformLocation(screenShaderProgram, "screenLoc");
	vec2* screenLoc;

	GLfloat angle = 0.0f;
	GLfloat speed = 0.0f;

	vec3* translationCam1 = makeNewVec3(0.0f, 0.0f, 0.0f);
	vec3* translationCam2 = makeNewVec3(0.0f, 0.0f, 0.0f);

	vec2* rotationCam = makeNewVec2(0.0f, 0.0f);

	//Main Loop  
	do
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;

		//glViewport(0, 0, width, height);
		//Check if Mouse Movement Changed
		if (mouseChange->arr[2] == 1.0f){
			//SHow the change has been found and will be reset at end of loop
			mouseChange->arr[2] = 2.0f;
		}
		//Controls
		if (keys[GLFW_KEY_W]){
			translationCam1->arr[0] += .05f;
		}
		else if (keys[GLFW_KEY_S]){
			translationCam1->arr[0] -= .05f;
		}
		if (keys[GLFW_KEY_A]){
			translationCam1->arr[1] += .05f;
		}
		else if (keys[GLFW_KEY_D]){
			translationCam1->arr[1] -= .05f;
		}
		if (keys[GLFW_KEY_Q]){
			translationCam1->arr[2] += .05f;
		}
		else if (keys[GLFW_KEY_E]){
			translationCam1->arr[2] -= .05f;
		}

		if (keys[GLFW_KEY_UP]){
			translationCam2->arr[0] += .05f;
		}
		else if (keys[GLFW_KEY_DOWN]){
			translationCam2->arr[0] -= .05f;
		}

		if (keys[GLFW_KEY_LEFT]){
			translationCam2->arr[1] += .05f;
		}
		else if (keys[GLFW_KEY_RIGHT]){
			translationCam2->arr[1] -= .05f;
		}


		if (keys[GLFW_KEY_SPACE]){
			speed = 1.0f;
		}
		angle += speed;
		if (angle > 360){
			angle -= 360;
		}
		if (speed > .001f){
			speed /= 1.0f + 1.0f / CLOCKS_PER_SEC;
		}
		else{
			speed = 0.0f;
		}
		// Bind our framebuffer and draw 3D scene (spinning cube)
		glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
		glBindVertexArray(vaoCube);
		glEnable(GL_DEPTH_TEST);
		glUseProgram(sceneShaderProgram);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texKitten);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texPuppy);

		//Clear color buffer  
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glClearColor((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, 1.0f);

		mat4* model = rotateNewMat4(angle, makeNewVec3(0.0f, 0.0f, 1.0f));
		translateMat4(model, translationCam2);
		glUniformMatrix4fv(uniModel, 1, GL_TRUE, &model->x[0]);
		mat4* cameraRatation = getNewMat4();
		
		if (mouseChange->arr[2] == 2.0f){
			rotationCam->arr[0] += (1.0f * mouseChange->arr[0]);
			rotationCam->arr[1] += (1.0f * mouseChange->arr[1]);
			if (rotationCam->arr[0] > 360.0f){
				rotationCam->arr[0] -= 360.0f;
			}
			if (rotationCam->arr[1] > 360.0f){
				rotationCam->arr[1] -= 360.0f;
			}
			if (rotationCam->arr[0] < -360.0f){
				rotationCam->arr[0] += 360.0f;
			}
			if (rotationCam->arr[1] < -360.0f){
				rotationCam->arr[1] += 360.0f;
			}
			//printVec2(rotationCam);
		}
		vec3* cameraPos = makeNewVec3(-2.0f, 0.0f, 0.0f);
		addVec3(cameraPos, cameraPos, translationCam1);
		vec3* lookAtPos = (vec3*)malloc(sizeof(vec3));
		GLfloat magTemp = magnitudeVec3(lookAtPos);
		lookAtPos->arr[0] = -cameraPos->arr[0] + (-magTemp * degToRadCos(rotationCam->arr[1]) * degToRadCos(rotationCam->arr[0]));
		lookAtPos->arr[1] = -cameraPos->arr[1] + (magTemp * degToRadCos(rotationCam->arr[1]) * degToRadSin(rotationCam->arr[0]));
		lookAtPos->arr[2] = -cameraPos->arr[2] + (magTemp * degToRadSin(rotationCam->arr[1]));
		//printVec3(lookAtPos);
		mat4* view = lookAtNewMat4(cameraPos,
			lookAtPos,
			makeNewVec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniView, 1, GL_FALSE, &view->x[0]);
		mat4* proj = perspectiveNewMat4(45.0f, ratio, 1.0f, 20.0f);
		glUniformMatrix4fv(uniProj, 1, GL_FALSE, &proj->x[0]);

		// Draw cube
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glEnable(GL_STENCIL_TEST);

		// Draw floor
		glBindVertexArray(vaoPlane);
		glStencilFunc(GL_ALWAYS, 1, 0xFF);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		glStencilMask(0xFF);
		glDepthMask(GL_FALSE);
		glClear(GL_STENCIL_BUFFER_BIT);

		glUniformMatrix4fv(uni2Model, 1, GL_TRUE, &model->x[0]);
		glUniformMatrix4fv(uni2View, 1, GL_FALSE, &view->x[0]);
		glUniformMatrix4fv(uni2Proj, 1, GL_FALSE, &proj->x[0]);


		glDrawArrays(GL_QUADS, 0, *plane->numVerts);
		

		// Draw cube reflection
		glBindVertexArray(vaoCube);
		glStencilFunc(GL_EQUAL, 1, 0xFF);
		glStencilMask(0x00);
		glDepthMask(GL_TRUE);

		scaleMat4(model, makeNewVec3(1.0f, 1.0f, -1.0f));
		translateMat4(model, makeNewVec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniModel, 1, GL_TRUE, &model->x[0]);
		//Shadow
		glUniform3f(uniColor, 0.3f, 0.3f, 0.3f);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);
		glDisable(GL_STENCIL_TEST);

		// Bind default framebuffer and draw contents of our framebuffer
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glBindVertexArray(vaoQuad);
		glDisable(GL_DEPTH_TEST);
		glUseProgram(screenShaderProgram);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texColorBuffer);


		screenLoc = makeNewVec2(.5f, -.5f);
		glUniform2f(uniScreenLoc, screenLoc->arr[0], screenLoc->arr[1]);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		// Bind our framebuffer and draw 3D scene (spinning cube)
		glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
		glBindVertexArray(vaoCube);
		glEnable(GL_DEPTH_TEST);
		glUseProgram(sceneShaderProgram);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texKitten);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texPuppy);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		getMat4(model);
		rotateMat4(model, angle, makeNewVec3(0.0f, 0.0f, 1.0f));
		translateMat4(model, translationCam2);
		glUniformMatrix4fv(uniModel, 1, GL_TRUE, &model->x[0]);
		cameraPos = makeNewVec3(2.5f, 2.5f, 5.0f);
		addVec3(cameraPos, cameraPos, translationCam2);
		lookAtPos = makeNewVec3(0.0f, 0.0f, 0.0f);
		addVec3(lookAtPos, lookAtPos, translationCam2);
		lookAtMat4(view, cameraPos,
			lookAtPos,
			makeNewVec3(0.0f, 0.0f, 1.0f));
		free(cameraPos);
		free(lookAtPos);
		glUniformMatrix4fv(uniView, 1, GL_FALSE, &view->x[0]);

		perspectiveMat4(proj, 45.0f, ratio, 1.0f, 10.0f);
		glUniformMatrix4fv(uniProj, 1, GL_FALSE, &proj->x[0]);

		// Draw cube
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glEnable(GL_STENCIL_TEST);

		// Draw floor
		glStencilFunc(GL_ALWAYS, 1, 0xFF);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
		glStencilMask(0xFF);
		glDepthMask(GL_FALSE);
		glClear(GL_STENCIL_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 36, 6);

		// Draw cube reflection
		glStencilFunc(GL_EQUAL, 1, 0xFF);
		glStencilMask(0x00);
		glDepthMask(GL_TRUE);

		scaleMat4(model, makeNewVec3(1.0f, 1.0f, -1.0f));
		translateMat4(model, makeNewVec3(0.0f, 0.0f, -1.0f));
		glUniformMatrix4fv(uniModel, 1, GL_TRUE, &model->x[0]);
		//Shadow
		glUniform3f(uniColor, 0.3f, 0.3f, 0.3f);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);
		glDisable(GL_STENCIL_TEST);

		// Bind default framebuffer and draw contents of our framebuffer
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glBindVertexArray(vaoQuad);
		glDisable(GL_DEPTH_TEST);
		glUseProgram(screenShaderProgram);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texColorBuffer);

		screenLoc->arr[0] = -.5f;
		glUniform2f(uniScreenLoc, screenLoc->arr[0], screenLoc->arr[1]);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		//Swap buffers  
		glfwSwapBuffers(window);
		//Get and organize events, like keyboard and mouse input, window resizing, etc...  
		glfwPollEvents();

		free(model);
		free(view);
		free(proj);

		//Has the mouse movement change been toggled?
		if (mouseChange->arr[2] == 2.0f){
			mouseChange->arr[0] = 0.0f;
			mouseChange->arr[1] = 0.0f;
			//Reset the change toddle
			mouseChange->arr[2] = 0.0f;
		}

	} //Check if the ESC key had been pressed or if the window had been closed  
	while (!glfwWindowShouldClose(window));


	//Close OpenGL window and terminate GLFW  
	glfwDestroyWindow(window);

	//Finalize and clean up GLFW  
	glfwTerminate();

	exit(EXIT_SUCCESS);
}


//Callbacks

//Define an error callback  
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

//Define the key input callback  
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("%i", key);
	if (key == -1){
		return;
	}
	else if (action == GLFW_PRESS){
		if (key == GLFW_KEY_ESCAPE){
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		keys[key] = true;
	}
	else if (action == GLFW_REPEAT){

	}
	else if (action == GLFW_RELEASE){
		keys[key] = false;
	}

}

//Mouse Position Callback
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	//printf("%f : %f\n", xpos, ypos);
	mouseChange->arr[0] = xpos - mousePos->arr[0];
	mouseChange->arr[1] = ypos - mousePos->arr[1];
	mouseChange->arr[2] = 1.0f;

	mousePos->arr[0] = xpos;
	mousePos->arr[1] = ypos;
}

void createShaderProgram(const GLchar* vertSrc, const GLchar* fragSrc, GLuint* vertexShader, GLuint* fragmentShader, GLuint* shaderProgram)
{
	// Create and compile the vertex shader
	*vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(*vertexShader, 1, &vertSrc, NULL);
	glCompileShader(*vertexShader);

	// Create and compile the fragment shader
	*fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(*fragmentShader, 1, &fragSrc, NULL);
	glCompileShader(*fragmentShader);

	// Link the vertex and fragment shader into a shader program
	*shaderProgram = glCreateProgram();
	glAttachShader(*shaderProgram, *vertexShader);
	glAttachShader(*shaderProgram, *fragmentShader);
	glBindFragDataLocation(*shaderProgram, 0, "outColor");
	glLinkProgram(*shaderProgram);
}

void specifySceneVertexAttributes(GLuint shaderProgram)
{
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
}

void specifyNewSceneVertexAttributes(GLuint shaderProgram)
{
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
}

void specifyScreenVertexAttributes(GLuint shaderProgram)
{
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
}

// Create a texture from an image file
GLuint loadTexture(const GLchar* path)
{
	GLuint texture;
	glGenTextures(1, &texture);

	int width, height;
	unsigned char* image;

	glBindTexture(GL_TEXTURE_2D, texture);
	image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return texture;
}