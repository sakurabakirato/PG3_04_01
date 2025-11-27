#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Initialize() 
{
	clearGraph_ = Novice::LoadTexture("./Resources/clear.png");
}

void ClearScene::Update(char* keys, char* preKeys) 
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) 
	{
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Curernt Scene : Clear");
	Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");
	Novice::DrawSprite(0, 0, clearGraph_, 1.0f, 1.0f, 0.0f, WHITE); 
}