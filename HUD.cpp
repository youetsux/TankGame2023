#include "HUD.h"
#include "Engine/Image.h"

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hHUD_(-1),hNumbers_(-1)
{

}

void HUD::Initialize()
{
	hHUD_ = Image::Load("HUD01.png");
	assert(hHUD_ >= 0);
}

void HUD::Update()
{
	transform_.position_ = { 10, 10, 0 };
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, transform_);
	Image::Draw(hHUD_);
}

void HUD::Release()
{
}
