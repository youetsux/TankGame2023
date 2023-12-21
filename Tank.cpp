#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"


Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1),speed_(0.05),front_({0,0,1,0})
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);
	//speed_ = 0.05;
	//front_ = XMVECTOR({ 0,0,1,0 });
}

void Tank::Update()
{

	if (Input::IsKey(DIK_W))
	{
		//��]�s������߂�
		XMMATRIX rotY = �Ȃ�;
		//�x�N�g���̉�]���ʂ����߂�
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);


		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3( &(transform_.position_) ); //XMVECTOR�ɍ��킹��
		pos = pos + move; //pos = pos + speed * front_
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_S))
	{
		XMVECTOR move;
		move = speed_ * front_;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - move;
		XMStoreFloat3(&(transform_.position_), pos);
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
