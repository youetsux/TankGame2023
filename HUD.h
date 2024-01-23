#pragma once
#include "Engine/GameObject.h"
#include <vector>
#include <string>

using std::string;


class HUD :
    public GameObject
{
	string ConstructEnemyNumberString();
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	HUD(GameObject* parent);
	int hHUD_;
	int hNumbers_;
	int hKinoko_;
	Transform tHud_;
	Transform tKinoko_;
	std::vector<Transform> tNumbers_;
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;


};

