#pragma once

#include "Person.h"

//�f�B�[���[�N���X
class Dealer : public Person 
{
public:
	Dealer(const char pName[]);
	void GetName();

protected:
	//�Q�[�����s
	void playBase(Shoe& shoe);

private:
	char name[NAME];

};