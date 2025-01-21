#pragma once

#include "Person.h"

//プレイヤークラス
class Player : public Person
{
public:
	Player(const char pName[]);
	void GetName();

protected:
	//ゲーム実行
	void playBase(Shoe& shoe);

private:
	char name[NAME];

};
