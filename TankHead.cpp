#include "TankHead.h"
#include "Engine/Model.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"), hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
}

void TankHead::Draw()
{
	//transform_‚Í©•ªiTankHeadj‚Ìƒƒ“ƒo•Ï”
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
