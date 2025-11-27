#include "StageScene.h"
#include <Novice.h>

void StageScene::Initialize() 
{
	playerGraphHandle_ = Novice::LoadTexture("./Resources/player.png");
	enemyGraphHandle_ = Novice::LoadTexture("./Resources/enemy-export.png");
	bulletGraphHandle_ = Novice::LoadTexture("./Resources/bullet.png");
	explodeGraphHandle_ = Novice::LoadTexture("./Resources/bakuhatu.png");
	backGroundGraph_ = Novice::LoadTexture("./Resources/haikei.png");

	playerPosX = 670.0f;
	playerPosY = 360.0f;
	speed = 5.0f;
	playerRadius = 64.0f;

	enemyPosX = 600.0f;
	enemyPosY = 0.0f;
	enemyRadius = 64.0f;
	enemySpeed = 3.0f;

	bulletPosX = 0.0f;
	bulletPosY = 0.0f;
	bulletSpeed = 10.0f;

	e2bR = (enemyRadius) * (enemyRadius);
	e2bX = 0.0f;
	e2bY = 0.0f;
	distance = e2bX + e2bY;

	isBulletShot = false;
	isHit = false;
	isEnemyAlive = true;

	respawnTimer = 120;

	backGroundPosY = 0.0f;

}

void StageScene::Update(char* keys, char* preKeys) {

	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {

		sceneNo = CLEAR;
	}
	
	if (keys[DIK_W] && keys[DIK_W] != 0)
	{
		playerPosY -= speed;
	}
	if (keys[DIK_S] && keys[DIK_S] != 0)
	{
		playerPosY += speed;
	}
	if (keys[DIK_A] && keys[DIK_A] != 0)
	{
		playerPosX -= speed;
	}
	if (keys[DIK_D] && keys[DIK_D] != 0)
	{
		playerPosX += speed;
	}


	if (playerPosX >= 1280)
	{
		playerPosX = 1280;
	}
	if (playerPosX - playerRadius <= 0)
	{
		playerPosX = playerRadius;
	}
	if (playerPosY - playerRadius <= 0)
	{
		playerPosY = playerRadius;
	}
	if (playerPosY >= 720)
	{
		playerPosY = 720;
	}

	
	if (isBulletShot)
	{
		e2bX = (bulletPosX - enemyPosX) * (bulletPosX - enemyPosX);
		e2bY = (bulletPosY - enemyPosY) * (bulletPosY - enemyPosY);
		distance = e2bX + e2bY;
		if (distance <= e2bR)
		{
			isEnemyAlive = false;
			isHit = true;
		}
	}

	
	if (isEnemyAlive == false)
	{
		--respawnTimer;
	}
	if (respawnTimer < 0)
	{
		respawnTimer = 120;
		isEnemyAlive = true;
		isHit = false;
	}

	
	if (isEnemyAlive)
	{
		enemyPosX += enemySpeed;
		if (enemyPosX + enemyRadius > 1280)
		{
			enemySpeed = -enemySpeed;
		}
		if (enemyPosX < 0)
		{
			enemySpeed = -enemySpeed;
		}
	}

	
	if (isBulletShot == false)
	{
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		{
			isBulletShot = true;
			bulletPosX = playerPosX - playerRadius + 15;
			bulletPosY = playerPosY - playerRadius + 15;
		}
	}
	if (isBulletShot)
	{
		if (bulletPosY <= 0)
			isBulletShot = false;
		bulletPosY = bulletPosY - bulletSpeed;
	}

	
	backGroundPosY++;
	if (backGroundPosY >= 720.0f)
	{
		backGroundPosY = 0.0f;
	}


}

void StageScene::Draw() {

	Novice::ScreenPrintf(0, 0, "Curernt Scene : Stage");
	Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");

	Novice::DrawSprite(0, static_cast<int>(backGroundPosY), backGroundGraph_, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, static_cast<int>(backGroundPosY) - 720, backGroundGraph_, 1.0f, 1.0f, 0.0f, WHITE);

	Novice::DrawSprite(static_cast<int>(playerPosX - playerRadius), static_cast<int>(playerPosY - playerRadius), playerGraphHandle_, 0.5, 0.5, 0.0f, WHITE);

	if (isEnemyAlive)
	{
		Novice::DrawSprite(static_cast<int>(enemyPosX), static_cast<int>(enemyPosY), enemyGraphHandle_, 0.5f, 0.5f, 0.0f, WHITE);
	}
	if (respawnTimer < 120 && respawnTimer >= 90)
	{
		Novice::DrawSprite(static_cast<int>(enemyPosX), static_cast<int>(enemyPosY), explodeGraphHandle_, 0.5f, 0.5f, 0.0f, WHITE);
	}
	if (isBulletShot)
	{
		Novice::DrawSprite(static_cast<int>(bulletPosX), static_cast<int>(bulletPosY), bulletGraphHandle_, 0.2f, 0.2f, 0.0f, WHITE);
	}
}