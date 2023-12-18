#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"


Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1), front_({ 0,0,1,0 })
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);
}

void Tank::Update()
{
	XMMATRIX m = XMMatrixRotationY(XMConvertToRadians(this->transform_.rotate_.y));	//Ｙ軸で30度回転させる行列
	XMVECTOR a = XMVector3TransformCoord(front_, m);	//ベクトルｖを行列ｍで変形
	if (Input::IsKey(DIK_W))
	{
		XMFLOAT3 move;
		XMStoreFloat3(&move, (a * 0.01f));
		this->transform_.position_ = this->transform_.Float3Add(this->transform_.position_, move);
	}
	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 1;

	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 1;
	}
	Debug::Log("angle = ");
	Debug::Log(transform_.rotate_.y, true);
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
