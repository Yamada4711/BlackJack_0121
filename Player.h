#pragma once

#include "Person.h"

//�v���C���[�N���X
class Player : public Person
{
public:
	Player(const char pName[]);
	void GetName();

protected:
	//�Q�[�����s
	void playBase(Shoe& shoe);

private:
	char name[NAME];

};
