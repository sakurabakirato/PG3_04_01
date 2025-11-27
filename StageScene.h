#pragma once
#include "IScene.h"

class StageScene : public IScene {

public:

	void Initialize() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
private:
	int playerGraphHandle_;
	float playerPosX;
	float playerPosY;
	float speed;
	float playerRadius;

	int enemyGraphHandle_;
	float enemyPosX;
	float enemyPosY;
	float enemyRadius;
	float enemySpeed;

	int bulletGraphHandle_;
	float bulletPosX = 0.0f;
	float bulletPosY = 0.0f;
	float bulletSpeed = 10.0f;

	int explodeGraphHandle_;
	int backGroundGraph_;

	float e2bR = (enemyRadius) * (enemyRadius);
	float e2bX = 0.0f;
	float e2bY = 0.0f;
	float distance = e2bX + e2bY;

	int isBulletShot = false;
	int isHit = false;
	int isEnemyAlive = true;

	int respawnTimer = 120;

	float backGroundPosY = 0.0f;




};
