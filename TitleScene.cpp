#include <Novice.h>
#include "TitleScene.h"

void TitleScene::Initialize() 
{
	titleGraph_ = Novice::LoadTexture("./Resources/title.png");
}

void TitleScene::Update(char* keys, char* preKeys) 
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) 
	{
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() 
{

	Novice::ScreenPrintf(0, 0, "Curernt Scene : Title");
	Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	Novice::DrawSprite(350, 240, titleGraph_, 2.0f, 2.0f, 0.0f, WHITE);
}
