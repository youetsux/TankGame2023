#include "Enemy.h"
#include "Engine/Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Mushroom 1.fbx");
	assert(hModel_ >= 0);
	//�A�j���[�V�����̃Z�b�g
	//Model::

}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
