#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hHUD_(-1),hNumbers_(-1)
{

}

void HUD::Initialize()
{
	hHUD_ = Image::Load("HUD01.png");
	assert(hHUD_ >= 0);
	hNumbers_ = Image::Load("numbers.png");
	assert(hHUD_ >= 0);
	hKinoko_ = Image::Load("kinoko.png");
	assert(hKinoko_ >= 0);

	for (int i = 0; i < 3; i++)
	{
		Transform t;
		t.position_ = { -0.53f + 0.05f*(float)i, 0.85f, 0.0f };
		tNumbers_.push_back(t);
	}
}

void HUD::Update()
{
	tHud_.position_ = { -0.6, 0.85, 0 };
	tKinoko_.position_ = { -0.31, 0.85, 0 };
	tKinoko_.scale_ = { 0.7, 0.7, 1 };
	int eneNum = ((PlayScene *)(GetParent()))->GetEnemyNum();
	//�����ŃX�g�����O�ɕ������āA����������Ă�����
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);
	for(int i = 0; i < 3; i++) {
		Image::SetRect(hNumbers_, 51.2 *(float)i, 0, 51.2, 60);
		Image::SetTransform(hNumbers_, tNumbers_[i]);
		Image::Draw(hNumbers_);
	}
	Image::SetTransform(hKinoko_, tKinoko_);
	Image::Draw(hKinoko_);

}

void HUD::Release()
{
}
