#include "Bullet.h"
#include "Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
}

void Bullet::Update()
{
	//transform_.positionをmoveDir_とbulletSpeedで更新
	//transform_.position_.z += 0.05;
	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
	//transform_.position_->XMVECTOR pos;
	//moveDir->XMVECTOR dir;
	//pos = pos + bulletSpeed_ * dir;
	y座標を落とす
		if (yが相当下に落ちたら)
			KillMe();
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
