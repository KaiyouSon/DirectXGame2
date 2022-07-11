#pragma once
#include <cstdint>
#include <list>
#include <memory>
#include "Model.h"
#include "WorldTransform.h"
#include "Vector3.h"
#include "BaseEnemyState.h"
#include "EnemyBullet.h"

class Enemy
{
public:
	enum class Phase
	{
		Approach,	// 接近する
		Leave		// 離脱する
	};

private:
	uint32_t textureHandle = 0;
	Model* model = nullptr;
	WorldTransform trans;
	Vector3 generatePos;
	Vector3 pos;
	float speed;
	Phase phase = Phase::Approach;

	std::list<std::unique_ptr<EnemyBullet>> enemyBullets;
	float generateTimer;
	float maxGenerateTimer;

	// 状態
	BaseEnemyState* currentState;

	void ShotUpdate();
	void StateChangeUpdate();

public:
	Enemy();
	~Enemy();
	void Initialize();
	void Update();
	void Draw();

	void SetPos(Vector3 pos);
	Vector3 GetGeneratePos();
	Vector3 GetPos();
};
