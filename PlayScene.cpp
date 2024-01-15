#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
#include "Engine/Text.h"
#include "Engine/Camera.h"
//#include "TankHead.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),pText(nullptr)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{

	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
	//敵をインスタンス化
	for(int i=0;i<30;i++)
		Instantiate<Enemy>(this);

	enemyNum = 30;
	
	pText = new Text;
	pText->Initialize();

}

void PlayScene::Update()
{
	//タンクと一緒にカメラを動かすよ
	Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);
}

void PlayScene::Draw()
{
	pText->Draw(30, 30, "Yahoo!");

}

void PlayScene::Release()
{
}
