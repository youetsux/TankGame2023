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
	//transform_は自分（TankHead）のメンバ変数
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
