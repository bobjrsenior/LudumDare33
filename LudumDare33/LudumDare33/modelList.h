typedef struct Enemy{
	int hp;
	float dps;
	float movementSpeed;
}Enemy;

typedef struct Hero{
	int hp;
	float dps;
	float movementSpeed;
	int slainEnemies;
}Hero;

float squareVertices[16] = { -.1f, .1f, 0.0f, 0.0f,
							.1f, .1f, 1.0f, 0.0f,
							.1f, -.1f, 1.0f, 1.0f,
							-.1f, -.1f, 0.0f, 1.0f };